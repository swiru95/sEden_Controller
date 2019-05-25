/**
 * xmlPpi.cc This file contains definitions of applications which use XML flow policy!
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
/** This App1 works like this:
 * -ARP comming, controller says to switch to send it to the destinated out port.
 * -IPv4 comming, controller says to switch setting correct flow and then out packet to switch and passing it
 * to this port.
 * All packets are checket like this:
 * ipsrc,ipdst,macsrc,macdst,inport,outport are examinated and equaled to flows in XML file.
 * IPv6 doesnt supported
 */
void SimpleController::app1(ChunkQueue& queue, int connId) {

    auto search = con2switch.find(connId);
    string sw = search->second;
    if (!strcmp("", sw.c_str())) {
        error("No switch!!!");
        return;
    }

    auto flowsXml = par("flows").xmlValue();
    auto switchXml = flowsXml->getElementsByTagName("switch");
    unsigned int i = 0;
    while (strcmp(sw.c_str(), switchXml[i]->getAttribute("name"))) {
        i++;
        if ((unsigned) i >= switchXml.size()) {
            perror("No switch name!");
            return;
        }
    }
    auto choosenSwXml = switchXml[i];
    auto entries = choosenSwXml->getChildren();
    EV << "Got " << entries.size() << " entries in XML for" << sw << endl;
    auto& appPktInMsg = queue.pop<Ofp_packet_in>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
    auto& appEthData = queue.pop<EthernetMacHeader>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
///////////////////IPv4
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv4) {
        EV << "IPv4!" << endl;
        ipV4Rec++;
        auto& appIpv4Data = queue.pop<Ipv4Header>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        i = 0;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be entry!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);
//PRINT1
            EV << "XML: " << dstMacAddr << endl << srcMacAddr << endl
                      << dstIpAddr << endl << srcIpAddr << endl << inPort
                      << endl << outPort << endl;
            EV << "PIN: " << appEthData->getDest() << endl
                      << appEthData->getSrc() << endl
                      << appIpv4Data->getDestAddress() << endl
                      << appIpv4Data->getSrcAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(dstMacAddr, appEthData->getDest().str().c_str())
                    or strcmp(srcMacAddr, appEthData->getSrc().str().c_str())
                    or strcmp(srcIpAddr,
                            appIpv4Data->getSrcAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appIpv4Data->getDestAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
        }

//NEW FLOW (Flow Mode msg)
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
        payloadMatch->setDl_dst(MacAddress(dstMacAddr));
        payloadMatch->setDl_src(MacAddress(srcMacAddr));
        payloadMatch->setDl_type(appEthData->getTypeOrLength());
        payloadMatch->setNw_dst(Ipv4Address(srcIpAddr));
        payloadMatch->setNw_src(Ipv4Address(dstIpAddr));
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

        flModSend++;
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
        EV << "LEN: " << queue.getLength() << endl << "REQ LEN: "
                  << appIpv4Data->getTotalLengthField() - B(20) << endl;
        auto& appDataRest = queue.pop<BytesChunk>(
                appIpv4Data->getTotalLengthField() - B(20),
                Chunk::PF_ALLOW_NULLPTR);

        outPacket1->insertAtBack(appEthData);
        outPacket1->insertAtBack(appIpv4Data);
        outPacket1->insertAtBack(appDataRest);

        ipV4Send++;
        packOutSend++;

        send(outPacket1, "socketOut");
        return;

    }
//////////////////ARP
    if (appEthData->getTypeOrLength() == ETHERTYPE_ARP) {
        EV << "ARP!" << endl;

        auto& appArpData = queue.pop<ArpPacket>(b(-1), Chunk::PF_ALLOW_NULLPTR);
        i = 0;
        if (appArpData->getOpcode() == ARP_REQUEST)
            arpReqRec++;
        if (appArpData->getOpcode() == ARP_REPLY)
            arpRepRec++;
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be \"entry\"!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);

            EV << "XML: " << srcMacAddr << endl << srcIpAddr << endl
                      << dstIpAddr << endl << inPort << endl << outPort << endl;
            EV << "PIN: " << appArpData->getSrcMacAddress() << endl
                      << appArpData->getSrcIpAddress() << endl
                      << appArpData->getDestIpAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(srcMacAddr, appArpData->getSrcMacAddress().str().c_str())
                    or strcmp(srcIpAddr,
                            appArpData->getSrcIpAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appArpData->getDestIpAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
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
        payloadPktOut->setBuffer_id(appPktInMsg->getBuffer_id());
        payloadPktOut->setIn_port(appPktInMsg->getIn_port());
        len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
        payloadPktOut->setActions_len(len);
        outPacket->insertAtBack(payloadPktOut);
        const auto& payloadAh = makeShared<Ofp_action_head>();
        payloadAh->setType(OUTPUT_ACTION);   //to swport
        payloadAh->setLength(len);
        outPacket->insertAtBack(payloadAh);
        const auto& payloadA = makeShared<Ofp_output_action>();
        payloadA->setPort(outPort);
        payloadA->setMax_len(0xFFFF);
        outPacket->insertAtBack(payloadA);
        outPacket->insertAtBack(appEthData);
        outPacket->insertAtBack(appArpData);

        if (appArpData->getOpcode() == ARP_REQUEST)
            arpReqSend++;
        if (appArpData->getOpcode() == ARP_REPLY)
            arpRepSend++;
        packOutSend++;

        send(outPacket, "socketOut");
        return;
    }

//////////////////IPv6
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
        EV << "IPV6" << endl;
        ipV6Rec++;
        return;
        //TODO
    }
}
/** This App2 works like this:
 * -ARP comming, controller examinated it and sending out reply with correct mac addres from XML flow.
 * Replay is sent to the outport from XML.
 * -IPv4 comming, controller says to switch setting correct flow and then out packet to switch and passing it
 * to this destinated port.
 * All packets are checket like this:
 * ipsrc,ipdst,macsrc,macdst,inport,outport are examinated and equaled to flows in XML file.
 * IPv6 doesnt supported
 */
void SimpleController::app2(ChunkQueue& queue, int connId) {

    auto search = con2switch.find(connId);
    string sw = search->second;
    if (!strcmp("", sw.c_str())) {
        error("No switch!!!");
        return;
    }

    auto flowsXml = par("flows").xmlValue();
    auto switchXml = flowsXml->getElementsByTagName("switch");
    unsigned int i = 0;
    while (strcmp(sw.c_str(), switchXml[i]->getAttribute("name"))) {
        i++;
        if ((unsigned) i >= switchXml.size()) {
            perror("No switch name!");
            return;
        }
    }
    auto choosenSwXml = switchXml[i];
    auto entries = choosenSwXml->getChildren();
    EV << "Got " << entries.size() << " entries in XML." << endl;
    auto& appPktInMsg = queue.pop<Ofp_packet_in>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
    auto& appEthData = queue.pop<EthernetMacHeader>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
///////////////////IPv4
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv4) {
        EV << "IPv4!" << endl;
        ipV4Rec++;
        auto& appIpv4Data = queue.pop<Ipv4Header>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        i = 0;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be entry!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);
//PRINT1
            EV << "XML: " << dstMacAddr << endl << srcMacAddr << endl
                      << dstIpAddr << endl << srcIpAddr << endl << inPort
                      << endl << outPort << endl;
            EV << "PIN: " << appEthData->getDest() << endl
                      << appEthData->getSrc() << endl
                      << appIpv4Data->getDestAddress() << endl
                      << appIpv4Data->getSrcAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(dstMacAddr, appEthData->getDest().str().c_str())
                    or strcmp(srcMacAddr, appEthData->getSrc().str().c_str())
                    or strcmp(srcIpAddr,
                            appIpv4Data->getSrcAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appIpv4Data->getDestAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
        }

//NEW FLOW (Flow Mode msg)
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
        payloadMatch->setDl_dst(MacAddress(dstMacAddr));
        payloadMatch->setDl_src(MacAddress(srcMacAddr));
        payloadMatch->setDl_type(appEthData->getTypeOrLength());
        payloadMatch->setNw_dst(Ipv4Address(srcIpAddr));
        payloadMatch->setNw_src(Ipv4Address(dstIpAddr));
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

        flModSend++;
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

        ipV4Send++;
        packOutSend++;

        send(outPacket1, "socketOut");
        return;

    }
//////////////////ARP
    if (appEthData->getTypeOrLength() == ETHERTYPE_ARP) {
        EV << "ARP!" << endl;

        auto& appArpData = queue.pop<ArpPacket>(b(-1), Chunk::PF_ALLOW_NULLPTR);
        i = 0;
        if (appArpData->getOpcode() == ARP_REQUEST)
            arpReqRec++;
        if (appArpData->getOpcode() == ARP_REPLY)
            arpRepRec++;
        if (appArpData->getOpcode() == ARP_REPLY) {
            if (log2file) {
                string filestr = "logs/" + string(getParentModule()->getName())
                        + "_ErrorLog.log";
                ofstream file(filestr, ios::app);
                auto timex = system_clock::to_time_t(system_clock::now());
                file << "WARNING!!> " << ctime(&timex) << "   Switch: " << sw
                        << " src: " << appArpData->getSrcIpAddress() << " ("
                        << appArpData->getSrcMacAddress() << ") "
                        << " Possible ARP_SPOOFING threat (arp_reply)." << endl
                        << " Target: " << appArpData->getDestIpAddress()
                        << endl;
                file.close();
            }
            return;
        }
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be \"entry\"!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);

            EV << "XML: " << srcMacAddr << endl << srcIpAddr << endl
                      << dstIpAddr << endl << inPort << endl << outPort << endl;
            EV << "PIN: " << appArpData->getSrcMacAddress() << endl
                      << appArpData->getSrcIpAddress() << endl
                      << appArpData->getDestIpAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(srcMacAddr, appArpData->getSrcMacAddress().str().c_str())
                    or strcmp(srcIpAddr,
                            appArpData->getSrcIpAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appArpData->getDestIpAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
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
        ethData->setSrc(MacAddress(dstMacAddr));
        ethData->setTypeOrLength(ETHERTYPE_ARP);
        outPacket->insertAtBack(ethData);
        auto arpRep = makeShared<ArpPacket>();
        arpRep->setDestIpAddress(appArpData->getSrcIpAddress());
        arpRep->setDestMacAddress(appArpData->getSrcMacAddress());
        arpRep->setSrcIpAddress(appArpData->getDestIpAddress());
        arpRep->setSrcMacAddress(MacAddress(dstMacAddr));
        arpRep->setOpcode(ARP_REPLY);
        outPacket->insertAtBack(arpRep);

        arpRepSend++;
        packOutSend++;

        send(outPacket, "socketOut");
        return;
    }

//////////////////IPv6
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
        EV << "IPV6" << endl;
        ipV6Rec++;
        //TODO
        return;
    }

}
/**
 * This App4 works like this:
 * -OFP_PacketIn comming-> controller check XML if there is a flow
 * -ARP comming, controller examinated it and sending out to flood. (as normal)
 * -IPv4 comming, controller says to switch setting correct flow and then out packet to switch and passing it
 * to this destinated port.
 * All packets are checked like this:
 * ipsrc,ipdst,macsrc,macdst,inport,outport are examinated and equaled to flows in XML file.
 * IPv6 doesnt supported
 */
void SimpleController::app4(ChunkQueue& queue, int connId) {

    auto search = con2switch.find(connId);
    string sw = search->second;
    if (!strcmp("", sw.c_str())) {
        error("No switch!!!");
        return;
    }

    auto flowsXml = par("flows").xmlValue();
    auto switchXml = flowsXml->getElementsByTagName("switch");
    unsigned int i = 0;
    while (strcmp(sw.c_str(), switchXml[i]->getAttribute("name"))) {
        i++;
        if ((unsigned) i >= switchXml.size()) {
            perror("No switch name!");
            return;
        }
    }
    auto choosenSwXml = switchXml[i];
    auto entries = choosenSwXml->getChildren();
    EV << "Got " << entries.size() << " entries in XML." << endl;
    auto& appPktInMsg = queue.pop<Ofp_packet_in>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
    auto& appEthData = queue.pop<EthernetMacHeader>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
///////////////////IPv4
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv4) {
        EV << "IPv4!" << endl;
        ipV4Rec++;
        auto& appIpv4Data = queue.pop<Ipv4Header>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        i = 0;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be entry!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);
//PRINT1
            EV << "XML: " << dstMacAddr << endl << srcMacAddr << endl
                      << dstIpAddr << endl << srcIpAddr << endl << inPort
                      << endl << outPort << endl;
            EV << "PIN: " << appEthData->getDest() << endl
                      << appEthData->getSrc() << endl
                      << appIpv4Data->getDestAddress() << endl
                      << appIpv4Data->getSrcAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(dstMacAddr, appEthData->getDest().str().c_str())
                    or strcmp(srcMacAddr, appEthData->getSrc().str().c_str())
                    or strcmp(srcIpAddr,
                            appIpv4Data->getSrcAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appIpv4Data->getDestAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
        }

//NEW FLOW (Flow Mode msg)
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
        payloadMatch->setDl_dst(MacAddress(dstMacAddr));
        payloadMatch->setDl_src(MacAddress(srcMacAddr));
        payloadMatch->setDl_type(appEthData->getTypeOrLength());
        payloadMatch->setNw_dst(Ipv4Address(srcIpAddr));
        payloadMatch->setNw_src(Ipv4Address(dstIpAddr));
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

        flModSend++;

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

        ipV4Send++;
        packOutSend++;

        send(outPacket1, "socketOut");
        return;

    }
//TODO ARP
    //////////////////ARP
    if (appEthData->getTypeOrLength() == ETHERTYPE_ARP) {
        EV << "ARP!" << endl;
        auto& appArpData = queue.pop<ArpPacket>(b(-1), Chunk::PF_ALLOW_NULLPTR);
        i = 0;
        if (appArpData->getOpcode() == ARP_REQUEST)
            arpReqRec++;
        if (appArpData->getOpcode() == ARP_REPLY)
            arpRepRec++;
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be \"entry\"!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);

            EV << "XML: " << srcMacAddr << endl << srcIpAddr << endl
                      << dstIpAddr << endl << inPort << endl << outPort << endl;
            EV << "PIN: " << appArpData->getSrcMacAddress() << endl
                      << appArpData->getSrcIpAddress() << endl
                      << appArpData->getDestIpAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(srcMacAddr, appArpData->getSrcMacAddress().str().c_str())
                    or strcmp(srcIpAddr,
                            appArpData->getSrcIpAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appArpData->getDestIpAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
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
        payloadPktOut->setBuffer_id(appPktInMsg->getBuffer_id());
        payloadPktOut->setIn_port(appPktInMsg->getIn_port());
        len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
        payloadPktOut->setActions_len(len);
        outPacket->insertAtBack(payloadPktOut);
        const auto& payloadAh = makeShared<Ofp_action_head>();
        payloadAh->setType(OUTPUT_ACTION);   //to swport
        payloadAh->setLength(len);
        outPacket->insertAtBack(payloadAh);
        const auto& payloadA = makeShared<Ofp_output_action>();
        if (appArpData->getOpcode() == ARP_REPLY)
            payloadA->setPort(outPort);
        if (appArpData->getOpcode() == ARP_REQUEST)
            payloadA->setPort(FLOOD);
        payloadA->setMax_len(0xFFFF);
        outPacket->insertAtBack(payloadA);
        outPacket->insertAtBack(appEthData);
        outPacket->insertAtBack(appArpData);

        if (appArpData->getOpcode() == ARP_REQUEST)
            arpReqSend++;
        if (appArpData->getOpcode() == ARP_REPLY)
            arpRepSend++;
        packOutSend++;

        send(outPacket, "socketOut");
        return;
    }

//////////////////IPv6
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
        EV << "IPV6" << endl;
        ipV6Rec++;
        //TODO
        return;
    }
}
/** This App5 works like this:
 * -ARP comming, controller examinated it and sending out reply with correct mac addres from XML flow.
 * Replay is sent to the outport from XML.
 * If there is an arp_reply -> it means that it may be possible arpspoof attack so it shutting down inPort
 * -IPv4 comming, controller says to switch setting correct flow and then out packet to switch and passing it
 * to this destinated port.
 * All packets are checket like this:
 * ipsrc,ipdst,macsrc,macdst,inport,outport are examinated and equaled to flows in XML file.
 * IPv6 doesnt supported
 */
void SimpleController::app5(ChunkQueue& queue, int connId) {

    auto search = con2switch.find(connId);
    string sw = search->second;
    if (!strcmp("", sw.c_str())) {
        error("No switch!!!");
        return;
    }

    auto flowsXml = par("flows").xmlValue();
    auto switchXml = flowsXml->getElementsByTagName("switch");
    unsigned int i = 0;
    while (strcmp(sw.c_str(), switchXml[i]->getAttribute("name"))) {
        i++;
        if ((unsigned) i >= switchXml.size()) {
            perror("No switch name!");
            return;
        }
    }
    auto choosenSwXml = switchXml[i];
    auto entries = choosenSwXml->getChildren();
    EV << "Got " << entries.size() << " entries in XML." << endl;
    auto& appPktInMsg = queue.pop<Ofp_packet_in>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
    auto& appEthData = queue.pop<EthernetMacHeader>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
///////////////////IPv4
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv4) {
        EV << "IPv4!" << endl;
        ipV4Rec++;
        auto& appIpv4Data = queue.pop<Ipv4Header>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        i = 0;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be entry!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);
//PRINT1
            EV << "XML: " << dstMacAddr << endl << srcMacAddr << endl
                      << dstIpAddr << endl << srcIpAddr << endl << inPort
                      << endl << outPort << endl;
            EV << "PIN: " << appEthData->getDest() << endl
                      << appEthData->getSrc() << endl
                      << appIpv4Data->getDestAddress() << endl
                      << appIpv4Data->getSrcAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(dstMacAddr, appEthData->getDest().str().c_str())
                    or strcmp(srcMacAddr, appEthData->getSrc().str().c_str())
                    or strcmp(srcIpAddr,
                            appIpv4Data->getSrcAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appIpv4Data->getDestAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
        }

//NEW FLOW (Flow Mode msg)
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
        payloadMatch->setDl_dst(MacAddress(dstMacAddr));
        payloadMatch->setDl_src(MacAddress(srcMacAddr));
        payloadMatch->setDl_type(appEthData->getTypeOrLength());
        payloadMatch->setNw_dst(Ipv4Address(srcIpAddr));
        payloadMatch->setNw_src(Ipv4Address(dstIpAddr));
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

        flModSend++;
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

        ipV4Send++;
        packOutSend++;

        send(outPacket1, "socketOut");
        return;

    }
//////////////////ARP
    if (appEthData->getTypeOrLength() == ETHERTYPE_ARP) {
        EV << "ARP!" << endl;

        auto& appArpData = queue.pop<ArpPacket>(b(-1), Chunk::PF_ALLOW_NULLPTR);
        i = 0;
        if (appArpData->getOpcode() == ARP_REQUEST)
            arpReqRec++;
        if (appArpData->getOpcode() == ARP_REPLY) {
            arpRepRec++;
            //Oh its arp spoofing-> ill shut down the port!
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
            itSM = switchMap.find((char*)sw.c_str());
            portmod->setHw_addr(itSM->second->getPortHw(appPktInMsg->getIn_port()));
            portmod->setConfig(PORT_DOWN+NO_FWD+NO_PACKET_IN);
            portmod->setMask(0x00000061);//PORT_DOWN,NO_FWD,NO_PCK_IN
            outPacket->insertAtBack(portmod);
            send(outPacket,"socketOut");
            //logged about attack
            if (log2file) {
                string filestr = "logs/" + string(getParentModule()->getName())
                        + "_ErrorLog.log";
                ofstream file(filestr, ios::app);
                auto timex = system_clock::to_time_t(system_clock::now());
                file << "WARNING!!> " << ctime(&timex) << "   Switch: " << sw
                        << " src: " << appArpData->getSrcIpAddress() << " ("
                        << appArpData->getSrcMacAddress() << ") "
                        << " Possible ARP_SPOOFING threat (arp_reply)." << endl
                        << " Target: " << appArpData->getDestIpAddress()
                        << endl;
                file.close();
            }
            return;
        }
        const char* dstMacAddr, *srcMacAddr, *srcIpAddr, *dstIpAddr;
        uint16_t inPort, outPort;
        while ((unsigned) i < entries.size()) {
            if (strcmp(entries[i]->getTagName(), "entry")) {
                error(
                        "In XML flows bad name of child under switch -> should be \"entry\"!");
                return;
            }
            dstMacAddr =
                    entries[i]->getFirstChildWithTag("mac-dst")->getNodeValue();
            srcMacAddr =
                    entries[i]->getFirstChildWithTag("mac-src")->getNodeValue();
            srcIpAddr =
                    entries[i]->getFirstChildWithTag("ip-src")->getNodeValue();
            dstIpAddr =
                    entries[i]->getFirstChildWithTag("ip-dst")->getNodeValue();
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("in-port")->getNodeValue(),
                    &inPort);
            str_to_uint16(
                    entries[i]->getFirstChildWithTag("out-port")->getNodeValue(),
                    &outPort);

            EV << "XML: " << srcMacAddr << endl << srcIpAddr << endl
                      << dstIpAddr << endl << inPort << endl << outPort << endl;
            EV << "PIN: " << appArpData->getSrcMacAddress() << endl
                      << appArpData->getSrcIpAddress() << endl
                      << appArpData->getDestIpAddress() << endl
                      << appPktInMsg->getIn_port() << endl;

            if (strcmp(srcMacAddr, appArpData->getSrcMacAddress().str().c_str())
                    or strcmp(srcIpAddr,
                            appArpData->getSrcIpAddress().str().c_str())
                    or strcmp(dstIpAddr,
                            appArpData->getDestIpAddress().str().c_str())
                    or (inPort != appPktInMsg->getIn_port())) {
            } else {
                EV << "Found Match for i=" << i << endl;
                break;
            }
            i++;
            if (i >= entries.size()) {
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
                return;
            }
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
        ethData->setSrc(MacAddress(dstMacAddr));
        ethData->setTypeOrLength(ETHERTYPE_ARP);
        outPacket->insertAtBack(ethData);
        auto arpRep = makeShared<ArpPacket>();
        arpRep->setDestIpAddress(appArpData->getSrcIpAddress());
        arpRep->setDestMacAddress(appArpData->getSrcMacAddress());
        arpRep->setSrcIpAddress(appArpData->getDestIpAddress());
        arpRep->setSrcMacAddress(MacAddress(dstMacAddr));
        arpRep->setOpcode(ARP_REPLY);
        outPacket->insertAtBack(arpRep);

        arpRepSend++;
        packOutSend++;

        send(outPacket, "socketOut");
        return;
    }

//////////////////IPv6
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
        EV << "IPV6" << endl;
        ipV6Rec++;
        //TODO
        return;
    }

}

