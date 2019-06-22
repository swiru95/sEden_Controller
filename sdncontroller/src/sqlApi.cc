/**
 * sqlApi.cc This file contains definitions of aplications which use SQL database policy!
 */

#include "SimpleController.h"
#include <sstream>
#include <chrono>
#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace chrono;
using namespace sql;

/**
 * This sqlExampleApp works like this:
 * -OFP_PacketIn comming-> controller ask mysqldatabase if there is a flow
 * -ARP comming, controller examinated it and sending out reply with correct mac addres from XML flow.
 * Replay is sent to the outport from XML.
 * -IPv4 comming, controller says to switch setting correct flow and then out packet to switch and passing it
 * to this destinated port.
 * All packets are checket like this:
 * ipsrc,ipdst,macsrc,macdst,inport,outport are examinated and equaled to flows in XML file.
 * IPv6 doesnt supported
 */
void SimpleController::sqlExampleApp(ChunkQueue& queue, int connId) {

    string dbIpAddr = "", dbPort = "", dbUser = "", dbPassword = "",
            dbName = "";
    dbIpAddr = par("dbIpAddr").stringValue();
    if (strcmp(dbIpAddr.c_str(), "") == 0)
        error("You should precise DB IP address (dbIpAddr).");
    dbPort = par("dbPort").stringValue();
    if (strcmp(dbPort.c_str(), "") == 0)
        error("You should precise DB Port (dbPort).");
    dbUser = par("dbUser").stringValue();
    if (strcmp(dbUser.c_str(), "") == 0)
        error("You should precise DB User (dbIpAddr).");
    dbPassword = par("dbPassword").stringValue();
    dbName = par("dbName").stringValue();
    if (strcmp(dbName.c_str(), "") == 0)
        error("You should precise DB User (dbIpAddr).");

    auto search = con2switch.find(connId);
    string sw = search->second;
    if (!strcmp("", sw.c_str())) {
        error("No switch!!!");
        return;
    }
    EV << "AT " << sw << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        string dstMacAddr, srcMacAddr, srcIpAddr, dstIpAddr, query;
        uint16_t inPort, outPort;
        int id;

        /* Create a connection */
        driver = get_driver_instance();
        string connection = "tcp://" + dbIpAddr + ":" + dbPort;
        con = driver->connect(connection, dbUser, dbPassword);
        /* Connect to the MySQL test database */
        con->setSchema(dbName);
        stmt = con->createStatement();
        query = "SELECT switchname FROM flows WHERE "
                "switchname='" + sw + "';";
        res = stmt->executeQuery(query);
        res->next();
        EV << " ROW COUNTS: " << res->rowsCount();
        if (res->rowsCount() == 0) {
            EV_WARN << "No switch name!" << endl;
            return;
        } else {
            EV << " Got match in DB for: " << sw << ": " << res->getString(1)
                      << " ROW COUNT=" << res->rowsCount() << endl;
        }
        auto& appPktInMsg = queue.pop<Ofp_packet_in>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        inPort = appPktInMsg->getIn_port();
        auto& appEthData = queue.pop<EthernetMacHeader>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        srcMacAddr = appEthData->getSrc().str();
        dstMacAddr = appEthData->getDest().str();
        if (appEthData->getTypeOrLength() == ETHERTYPE_IPv4) {
            EV << "IPV4!" << endl;
            auto& appIpv4Data = queue.pop<Ipv4Header>(b(-1),
                    Chunk::PF_ALLOW_NULLPTR);
            srcIpAddr = appIpv4Data->getSrcAddress().str();
            dstIpAddr = appIpv4Data->getDestAddress().str();
            query = "SELECT portout FROM flows WHERE "
                    "switchname='" + sw + "' and "
                    "portin=" + to_string(inPort) + " and "
                    "ipsrc='" + srcIpAddr + "' and "
                    "ipdst='" + dstIpAddr + "' and "
                    "macsrc='" + srcMacAddr + "' and "
                    "macdst='" + dstMacAddr + "';";
            EV << query << endl;
            res = stmt->executeQuery(query);
            res->next();
            EV << " ROW COUNTS: " << res->rowsCount();
            if (res->rowsCount() == 0) {
                if (log2file) {
                    string filestr = "logs/"
                            + string(getParentModule()->getName())
                            + "_ErrorLog.log";
                    ofstream file(filestr, ios::app);
                    auto timex = system_clock::to_time_t(system_clock::now());

                    file << "ER> " << ctime(&timex) << "   Switch: " << sw
                            << " src: " << appIpv4Data->getSrcAddress() << " ("
                            << appEthData->getSrc() << ") "
                            << " trying to connect with: "
                            << appIpv4Data->getDestAddress() << endl;
                    file.close();
                }
                delete res;
                delete stmt;
                delete con;
                return;
            }
            outPort = res->getUInt(1);
            Packet *outPacket = new Packet("FLOW_MOD");
            outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
            outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
                    &Protocol::tcp);
            outPacket->setKind(TCP_C_SEND);
            const auto& payload = makeShared<Ofp_header>();
            payload->setVersion(OFPV_v100);
            payload->setType(OFPT_FLOW_MOD);
            payload->setXid(getEnvir()->getUniqueNumber());
            uint16_t len = OFP_HEADER_SIZE + OFP_MATCH_SIZE + OFP_FLOW_MOD_SIZE
                    + OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
            payload->setLength(len);
            outPacket->insertAtBack(payload);
            const auto& payloadMatch = makeShared<Ofp_match>();
            payloadMatch->setWildcards(0x003000e2);
            payloadMatch->setIn_port(appPktInMsg->getIn_port());
            payloadMatch->setDl_dst(MacAddress(dstMacAddr.c_str()));
            payloadMatch->setDl_src(MacAddress(srcMacAddr.c_str()));
            payloadMatch->setDl_type(appEthData->getTypeOrLength());
            payloadMatch->setNw_dst(Ipv4Address(srcIpAddr.c_str()));
            payloadMatch->setNw_src(Ipv4Address(dstIpAddr.c_str()));
            outPacket->insertAtBack(payloadMatch);
            const auto& payloadFm = makeShared<Ofp_flow_mod>();
            payloadFm->setCookie(getEnvir()->getUniqueNumber());
            payloadFm->setCommand(OFPFC_ADD);
            payloadFm->setIdle_timeout(tIdle);
            payloadFm->setHard_timeout(tHard);
            payloadFm->setPriority(1);
            payloadFm->setBuffer_id(appPktInMsg->getBuffer_id());
            payloadFm->setOut_port(outPort);
            payloadFm->setFlags(0);
            outPacket->insertAtBack(payloadFm);
            const auto& payloadAh = makeShared<Ofp_action_head>();
            payloadAh->setType(0);   //to swport
            len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
            payloadAh->setLength(len);
            outPacket->insertAtBack(payloadAh);
            const auto& payloadA = makeShared<Ofp_output_action>();
            payloadA->setPort(outPort);
            payloadA->setMax_len(0xFFFF);
            outPacket->insertAtBack(payloadA);

            send(outPacket, "socketOut");

            EV << "Turning packet out!" << endl;
            Packet *outPacket1 = new Packet("PACKET_OUT");
            outPacket1->addTagIfAbsent<SocketReq>()->setSocketId(connId);
            outPacket1->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
                    &Protocol::tcp);
            outPacket1->setKind(TCP_C_SEND);
            const auto& payload1 = makeShared<Ofp_header>();
            payload1->setVersion(OFPV_v100);
            payload1->setType(OFPT_PACKET_OUT);
            payload1->setXid(getEnvir()->getUniqueNumber());
            len = OFP_HEADER_SIZE + OFP_PACKET_OUT_SIZE + OFP_ACTIONS_HEAD_SIZE
                    + OFP_OUTPUT_ACTION_SIZE + MAC_HEADER_SIZE
                    + appIpv4Data->getTotalLengthField().get();
            payload1->setLength(len);
            outPacket1->insertAtBack(payload1);
            const auto& payloadPktOut = makeShared<Ofp_packet_out>();
            payloadPktOut->setBuffer_id(appPktInMsg->getBuffer_id());
            payloadPktOut->setIn_port(appPktInMsg->getIn_port());
            len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
            payloadPktOut->setActions_len(len);
            outPacket1->insertAtBack(payloadPktOut);
            const auto& payloadAh1 = makeShared<Ofp_action_head>();
            payloadAh1->setType(OUTPUT_ACTION);   //to swport
            payloadAh1->setLength(len);
            outPacket1->insertAtBack(payloadAh1);
            const auto& payloadA1 = makeShared<Ofp_output_action>();
            payloadA1->setPort(outPort);
            payloadA1->setMax_len(0xFFFF);
            outPacket1->insertAtBack(payloadA1);

            auto& appDataRest = queue.pop<BytesChunk>(
                    appIpv4Data->getTotalLengthField() - B(20),
                    Chunk::PF_ALLOW_NULLPTR);

            outPacket1->insertAtBack(appEthData);
            outPacket1->insertAtBack(appIpv4Data);
            outPacket1->insertAtBack(appDataRest);

            send(outPacket1, "socketOut");

            delete res;
            delete stmt;
            delete con;
            return;
        }
        if (appEthData->getTypeOrLength() == ETHERTYPE_ARP) {
            EV << "ARP" << endl;
            auto& appArpData = queue.pop<ArpPacket>(b(-1),
                    Chunk::PF_ALLOW_NULLPTR);
            srcIpAddr = appArpData->getSrcIpAddress().str();
            dstIpAddr = appArpData->getDestIpAddress().str();
            if (appArpData->getOpcode() == ARP_REPLY) {
                arpRepRec++;
                Packet *outPacket = new Packet("PORT_MODE");
                outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
                outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
                        &Protocol::tcp);
                outPacket->setKind(TCP_C_SEND);
                const auto& payload = makeShared<Ofp_header>();
                payload->setVersion(OFPV_v100);
                payload->setType(OFPT_PORT_MOD);
                payload->setXid(getEnvir()->getUniqueNumber());
                uint16_t len = OFP_HEADER_SIZE + OFP_PORT_MODE_SIZE;
                payload->setLength(len);
                outPacket->insertAtBack(payload);
                const auto& portmod = makeShared<Ofp_port_mode>();
                portmod->setPort_no(appPktInMsg->getIn_port());
                itSM = switchMap.find((char*) sw.c_str());
                portmod->setHw_addr(
                        itSM->second->getPortHw(appPktInMsg->getIn_port()));
                portmod->setConfig(PORT_DOWN + NO_FWD + NO_PACKET_IN);
                portmod->setMask(0x00000061);   //PORT_DOWN,NO_FWD,NO_PCK_IN
                outPacket->insertAtBack(portmod);
                send(outPacket, "socketOut");
                portModSend++;
                if (log2file) {
                    string filestr = "logs/"
                            + string(getParentModule()->getName())
                            + "_ErrorLog.log";
                    ofstream file(filestr, ios::app);
                    auto timex = system_clock::to_time_t(system_clock::now());
                    file << "WARNING!!> " << ctime(&timex) << "   Switch: "
                            << sw << " src: " << appArpData->getSrcIpAddress()
                            << " (" << appArpData->getSrcMacAddress() << ") "
                            << " Possible ARP_SPOOFING threat (arp_reply)."
                            << endl << " Target: "
                            << appArpData->getDestIpAddress() << endl;
                    file.close();
                }
                delete res;
                delete stmt;
                delete con;
                return;
            }
            arpReqRec++;
            query = "SELECT macdst,portout FROM flows WHERE "
                    "switchname='" + sw + "' and "
                    "portin=" + to_string(appPktInMsg->getIn_port()) + " and "
                    "ipsrc='" + srcIpAddr + "' and "
                    "ipdst='" + dstIpAddr + "' and "
                    "macsrc='" + srcMacAddr + "';";
            EV << query << endl;
            res = stmt->executeQuery(query);
            res->next();
            EV << " #ROW COUNTS: " << res->rowsCount();
            if (res->rowsCount() == 0) {
                if (log2file) {
                    string filestr = "logs/"
                            + string(getParentModule()->getName())
                            + "_ErrorLog.log";
                    ofstream file(filestr, ios::app);
                    auto timex = system_clock::to_time_t(system_clock::now());

                    file << "ER> " << ctime(&timex) << "   Switch: " << sw
                            << " src: " << appArpData->getSrcIpAddress() << " ("
                            << appArpData->getSrcMacAddress() << ") "
                            << " trying connect with: "
                            << appArpData->getDestIpAddress() << endl;
                    file.close();
                }
                delete res;
                delete stmt;
                delete con;
                return;
            }
            Packet *outPacket = new Packet("PACKET_OUT");
            outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
            outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
                    &Protocol::tcp);
            outPacket->setKind(TCP_C_SEND);
            const auto& payload = makeShared<Ofp_header>();
            payload->setVersion(OFPV_v100);
            payload->setType(OFPT_PACKET_OUT);
            payload->setXid(getEnvir()->getUniqueNumber());
            uint16_t len = OFP_HEADER_SIZE + OFP_PACKET_OUT_SIZE
                    + OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE
                    + MAC_HEADER_SIZE + ARP_SIZE;
            payload->setLength(len);
            outPacket->insertAtBack(payload);
            const auto& payloadPktOut = makeShared<Ofp_packet_out>();
            payloadPktOut->setBuffer_id(-1);
            payloadPktOut->setIn_port(CONTROLLER);
            len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
            payloadPktOut->setActions_len(len);
            outPacket->insertAtBack(payloadPktOut);
            const auto& payloadAh = makeShared<Ofp_action_head>();
            payloadAh->setType(OUTPUT_ACTION);   //to swport
            payloadAh->setLength(len);
            outPacket->insertAtBack(payloadAh);
            const auto& payloadA = makeShared<Ofp_output_action>();
            payloadA->setPort(inPort);
            payloadA->setMax_len(0xFFFF);
            outPacket->insertAtBack(payloadA);
            auto ethData = makeShared<EthernetMacHeader>();
            ethData->setDest(appEthData->getSrc());
            ethData->setSrc(MacAddress(res->getString(1).c_str()));
            ethData->setTypeOrLength(ETHERTYPE_ARP);
            outPacket->insertAtBack(ethData);
            auto arpRep = makeShared<ArpPacket>();
            arpRep->setDestIpAddress(appArpData->getSrcIpAddress());
            arpRep->setDestMacAddress(appArpData->getSrcMacAddress());
            arpRep->setSrcIpAddress(appArpData->getDestIpAddress());
            arpRep->setSrcMacAddress(MacAddress(res->getString(1).c_str()));
            arpRep->setOpcode(ARP_REPLY);
            outPacket->insertAtBack(arpRep);

            send(outPacket, "socketOut");
            arpRepSend++;
            delete res;
            delete stmt;
            delete con;
            return;
        }
        if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
            EV << "IPV6" << endl;
            ipV6Rec++;
            //TODO
            delete res;
            delete stmt;
            delete con;
            return;
        }

    } catch (sql::SQLException &e) {
        string errorek = "SQL Exception!! ERROR: " + e.getSQLState() + "!->>"
                + e.what();
        error(errorek.c_str());
    }

}
