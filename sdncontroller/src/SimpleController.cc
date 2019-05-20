//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SimpleController.h"
#include <chrono>
using namespace chrono;

Define_Module(SimpleController);

void SimpleController::initialize(int stage) {
    cSimpleModule::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {

        echoInterval = (simtime_t) par("echoInterval").doubleValue();
        if (echoInterval < 0)
            error("echoInterval parameter cannot be negative.");
        helloWaitInterval = (simtime_t) par("helloWaitInterval").doubleValue();
        if (helloWaitInterval < 0)
            error("helloWaitInterval parameter cannot be negative.");
        featuresWaitInterval =
                (simtime_t) par("featuresWaitInterval").doubleValue();
        if (featuresWaitInterval < 0)
            error("featuresWaitInterval parameter cannot be negative.");
        echoCancelInterval =
                (simtime_t) par("echoCancelInterval").doubleValue();
        if (echoCancelInterval < 0)
            error("echoCancelInterval parameter cannot be negative.");
        tIdle = (uint16_t) par("time_idle").longValue();
        if (tIdle < 0)
            error("time_idle parameter cannot be negative.");
        tHard = (uint16_t) par("time_hard").longValue();
        if (tHard < 0)
            error("time_hard parameter cannot be negative.");
        application = par("application").stringValue();
        if (strcmp(application.c_str(), "") == 0)
            error(
                    "application parameter - sdncontroller needs an application.");
        if (strcmp(application.c_str(), "App3") == 0) {
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
        }

        //STATS
        helloRec = 0, helloSend = 0, echoReqRec = 0, echoReqSend = 0, echoRepRec =
                0, echoRepSend = 0, errorRec = 0, errorSend = 0, featSend = 0, featRec =
                0, getConReqSend = 0, getConRepRec = 0, setConSend = 0, packInRec =
                0, packOutSend = 0, flRemRec = 0, flModSend = 0, portStRec = 0, portModSend =
                0, statReqSend = 0, statRepRec = 0, barReqSend = 0, barRepRec =
                0;

        arpReqRec = 0, arpReqSend = 0, arpRepRec = 0, arpRepSend = 0, ipV4Rec =
                0, ipV4Send = 0, ipV6Rec = 0;

    } else if (stage == INITSTAGE_APPLICATION_LAYER) {
        const char * localAddress = par("localAddress").stringValue();
        int localPort = par("localPort").intValue();
        socket.setOutputGate(gate("socketOut"));
        socket.bind(
                localAddress[0] ?
                        L3AddressResolver().resolve(localAddress) : L3Address(),
                localPort);
        socket.listen();
        log2file = par("log2file").boolValue();
        if (log2file) {
            string filestr = "logs/" + string(getParentModule()->getName())
                    + "_ErrorLog.log";
            ofstream file(filestr);
            auto timex = system_clock::to_time_t(system_clock::now());
            file
                    << "Project created by @swiru95@ at Military University Of Technology."
                    << endl << "Log created at " << ctime(&timex)
                    << "SDN Controller is listening: "
                    << socket.getLocalAddress() << ":" << socket.getLocalPort()
                    << endl;
            file.close();
        }
        bool isOperational;
        NodeStatus *nodeStatus = dynamic_cast<NodeStatus *>(findContainingNode(
                this)->getSubmodule("status"));
        isOperational = (!nodeStatus)
                || nodeStatus->getState() == NodeStatus::UP;
        if (!isOperational)
            throw cRuntimeError(
                    "This module doesn't support starting in node DOWN state");
        state = CS_CLOSED;

        if (par("runWireshark").boolValue()) {
            auto inter =
                    getModuleByPath("host.ext[0].ext")->par("device").stringValue();
            if (par("anyWiresharkCaptureInterface").boolValue())
                inter = "any";
            if (strcmp(par("wiresharkCaptureInterface").stringValue(), "local"))
                inter = par("wiresharkCaptureInterface").stringValue();
            system(
                    format(
                            "x-terminal-emulator -e 'wireshark -i %s -f \"(host %s and port 6633) or (arp or icmp)\" -k'",
                            inter, localAddress).c_str());

        }
        if (par("runMininet").boolValue()) {
            EV << "Running Mininet." << endl;
            if (strcmp(par("mntopo").stringValue(), "") == 0) {
                system(
                        format(
                                "x-terminal-emulator -e 'mn --controller=remote,ip=%s,port=%d'",
                                localAddress, localPort).c_str());
            } else {
                auto topo = par("mntopo").stringValue();
                system(
                        format(
                                "x-terminal-emulator -e 'cd mnnets/; mn --custom %s.py --topo mytopo --controller=remote,ip=%s,port=%d'",
                                topo, localAddress, localPort).c_str());
            }
        }
    }

}
void SimpleController::handleMessage(cMessage *msg) {

    if (msg->isSelfMessage()) {
        handleSelfMessage(msg);
    } else if (msg->getKind() == TCP_I_PEER_CLOSED) {
        int connId =
                check_and_cast<Indication *>(msg)->getTag<SocketInd>()->getSocketId();
        delete msg;
        if (timersMap[connId]->isScheduled()) {
            cancelAndDelete(timersMap[connId]);
        }
        auto request = new Request("close", TCP_C_CLOSE);
        request->addTagIfAbsent<SocketReq>()->setSocketId(connId);
        sendBack(request);
    } else if (msg->getKind() == TCP_I_DATA
            || msg->getKind() == TCP_I_URGENT_DATA) {

        Packet *packet = check_and_cast<Packet *>(msg);
        int connId = packet->getTag<SocketInd>()->getSocketId();
        ChunkQueue &queue = socketQueue[connId];
        auto chunk = packet->peekDataAt(B(0), packet->getTotalLength());
        queue.push(chunk);
        //HEADER
        auto& appmsg = queue.pop<Ofp_header>(b(-1), Chunk::PF_ALLOW_NULLPTR);
        auto version = appmsg->getVersion();
        auto type = appmsg->getType();
        if (version == OFPV_v100 or version == OFPV_v110 or version == OFPV_v120
                or version == OFPV_v130 or version == OFPV_v140
                or version == OFPV_v150) {
            auto headLen = appmsg->getLength();
            auto xid = appmsg->getXid();
            if (state == CS_ESTABLISHED) {
                if (timersMap[connId]->isScheduled()) {
                    cancelEvent(timersMap[connId]);
                    timersMap[connId]->setType(ECHO_INTERVAL_TIMER);
                    scheduleAt(simTime() + echoInterval, timersMap[connId]);
                }
            }
            if (type == OFPT_HELLO) {
                helloRec++;
                sendHello(connId);
                sendFeatureReq(connId);
                if (timersMap[connId]->isScheduled()) {
                    cancelEvent(timersMap[connId]);
                    timersMap[connId]->setType(FEATURE_WAIT_TIMER);
                    scheduleAt(simTime() + featuresWaitInterval,
                            timersMap[connId]);
                }
                state = CS_FEATURE_WAIT;
            } else if (type == OFPT_ECHO_REPLY) {
                echoRepRec++;
            } else if (type == OFPT_ECHO_REQUEST and state == CS_ESTABLISHED) {
                echoReqRec++;
                sendEchoRep(connId, xid);
            } else if (type == OFPT_ERROR) {
                errorRec++;
                handleOfpError(queue, connId);
            } else if (type == OFPT_FEATURES_REPLY
                    and (state == CS_FEATURE_WAIT or state == CS_ESTABLISHED)) { //32B
                state = CS_ESTABLISHED;
                featRec++;
                handleOfpFeature(queue, connId, headLen);
                if (timersMap[connId]->isScheduled()) {
                    cancelEvent(timersMap[connId]);
                    timersMap[connId]->setType(ECHO_INTERVAL_TIMER);
                    scheduleAt(simTime() + echoInterval, timersMap[connId]);
                }
            } else if (type == OFPT_GET_CONFIG_REPLY) {
                getConRepRec++;
                handleOfpConfig(queue, connId);
            } else if (type == OFPT_PACKET_IN and state == CS_ESTABLISHED) {
                packInRec++;
                handleOfpPacketIn(queue, connId);
            } else if (type == OFPT_FLOW_REMOVED) {
                flRemRec++;
                handleOfpFlowRemoved(queue, connId);
            } else if (type == OFPT_PORT_STATUS) {
                portStRec++;
                handleOfpPortStatus(queue, connId);
            } else if (type == OFPT_STATS_REPLY) {
                statRepRec++;
                handleOfpStat(queue, connId);
            } else if (type == OFPT_QUEUE_GET_CONFIG_REPLY) {
            }
        } else {
            //TODO Security Risk (if it will be other fake OFP msg (version doestn exists)
            std::string st =
                    "NOT OFLOW MSG!! SimpleCOntroller Ln115! ConnectionId: ";
            st.append(std::to_string(connId));
            perror(st.c_str());
        }
        queue.clear();
        delete msg;
    } else if (msg->getKind() == TCP_I_AVAILABLE) {
        socket.processMessage(msg);
    } else if (msg->getKind() == TCP_I_ESTABLISHED) {
        EV << "ESTABLISHED!!!" << endl;
        state = CS_HELLO_WAIT;
        int connId =
                check_and_cast<Indication *>(msg)->getTag<SocketInd>()->getSocketId();
        EV << "1 CONNECTION AT: " << connId << endl;
        timersMap[connId] = new timer();
        timersMap[connId]->setConnId(connId);
        timersMap[connId]->setType(HELLO_WAIT_TIMER);
        scheduleAt(simTime() + helloWaitInterval, timersMap[connId]);
    } else {
        // some indication -- ignore
        EV_WARN << "drop msg: " << msg->getName() << ", kind:" << msg->getKind()
                       << "("
                       << cEnum::get("inet::TcpStatusInd")->getStringFor(
                               msg->getKind()) << ")\n";
        delete msg;
    }

}
void SimpleController::sendBack(cMessage *msg) {
    auto& tags = getTags(msg);
    tags.addTagIfAbsent<DispatchProtocolReq>()->setProtocol(&Protocol::tcp);
    send(msg, "socketOut");
}
void SimpleController::sendHello(int connId) {
    Packet *outPacket = new Packet("HELLO");
    outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
    outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
            &Protocol::tcp);
    outPacket->setKind(TCP_C_SEND);
    const auto& payload = makeShared<Ofp_header>();
    payload->setVersion(OFPV_v100);
    payload->setType(OFPT_HELLO);
    payload->setLength(0x0008);
    payload->setXid(getEnvir()->getUniqueNumber());
    outPacket->insertAtBack(payload);
    helloSend++;
    send(outPacket, "socketOut");
}
void SimpleController::sendEchoReq(int connId) {
    Packet *outPacket = new Packet("ECHO_REQ");
    outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
    outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
            &Protocol::tcp);
    outPacket->setKind(TCP_C_SEND);
    //HEADER
    const auto& payload = makeShared<Ofp_header>();
    payload->setVersion(OFPV_v100);
    payload->setType(OFPT_ECHO_REQUEST);
    payload->setLength(0x0008);
    payload->setXid(getEnvir()->getUniqueNumber());
    outPacket->insertAtBack(payload);
    echoReqSend++;
    //CAN BE OTHER
    send(outPacket, "socketOut");
}
void SimpleController::sendEchoRep(int connId, int xId) {
    Packet *outPacket = new Packet("ECHO REP");
    outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
    outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
            &Protocol::tcp);
    outPacket->setKind(TCP_C_SEND);
    //HEADER
    const auto& payload = makeShared<Ofp_header>();
    payload->setVersion(OFPV_v100);
    payload->setType(OFPT_ECHO_REPLY);
    payload->setLength(0x0008);
    payload->setXid(xId);
    outPacket->insertAtBack(payload);
    echoRepSend++;
    //CAN BE OTHER
    send(outPacket, "socketOut");
    return;
}
void SimpleController::handleOfpPacketIn(ChunkQueue& queue, int connId) {
    EV << "APPLICATION : " << application << endl;
    if (strcmp(application.c_str(), "App1") == 0) {
        app1(queue, connId);
    }
    if (strcmp(application.c_str(), "App2") == 0) {
        app2(queue, connId);
    }
    if (strcmp(application.c_str(), "App3") == 0) {
        app3(queue, connId);
    }
    if (strcmp(application.c_str(), "App4") == 0) {
        app4(queue, connId);
    }
    if (strcmp(application.c_str(), "App5") == 0) {
        app5(queue, connId);
    }
    if (strcmp(application.c_str(), "Simple_switch") == 0) {
        simpleSwitch(queue, connId);
    }
    return;
}
void SimpleController::handleOfpError(ChunkQueue& queue, int connId) {
    auto search = con2switch.find(connId);
    string sw = search->second;
    if (!strcmp("", sw.c_str())) {
        error("No switch!!!");
        return;
    }
    auto& appError = queue.pop<Ofp_error>(b(-1), Chunk::PF_ALLOW_NULLPTR);
    if (log2file) {
        string filestr = "logs/" + string(getParentModule()->getName())
                + "_ErrorLog.log";
        ofstream file(filestr, ios::app);

        auto timex = system_clock::to_time_t(system_clock::now());

        file << "OFP_MSG_ERROR> " << ctime(&timex) << "   From Switch: " << sw
                << " Number of Error: " << appError->getType() << " Type: "
                << appError->getCode() << endl;
        file.close();
    }
    return;
}
void SimpleController::handleOfpStat(ChunkQueue& queue, int connId) {
}
void SimpleController::handleOfpFeature(ChunkQueue& queue, int connId,
        uint16_t headLen) {
    auto& appFeature = queue.pop<Ofp_feature>(b(-1), Chunk::PF_ALLOW_NULLPTR);
    auto numPorts = (headLen - 32) / 48;
    auto& appPhyPort = queue.pop<Ofp_phy_port>(b(-1), Chunk::PF_ALLOW_NULLPTR);
    //switch
    int i = 0;
    char sname[16], pname[16];
    while (i < 16) {
        sname[i] = appPhyPort->getName(i);
        i++;
    }
    //todo if switch exists already!?:D
    switchMap[sname] = new SwitchProfile(appFeature->getDatapath_id(),
            appPhyPort->getHw_addr(), appPhyPort->getPort_no(), numPorts,
            connId);
    //todo if conn is already!?
    con2switch[connId] = sname;
    i = 0;
    int j = 0;
    while (i < numPorts - 1) {
        auto& appPhyPort = queue.pop<Ofp_phy_port>(b(-1),
                Chunk::PF_ALLOW_NULLPTR);
        while (j < 16) {
            pname[j] = appPhyPort->getName(j);
            j++;
        }
        switchMap[sname]->setEthPorts(pname);
        switchMap[sname]->setPortHw(appPhyPort->getPort_no(),
                appPhyPort->getHw_addr());
        i++;
    }
    return;
}
void SimpleController::handleOfpFlowRemoved(ChunkQueue& queue, int connId) {
}
void SimpleController::handleOfpConfig(ChunkQueue& queue, int connId) {
}
void SimpleController::handleOfpPortStatus(ChunkQueue& queue, int connId) {
}
void SimpleController::sendBarrierReq(int connId) {
    Packet *outPacket = new Packet("BARRIER_REQ");
    outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
    outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
            &Protocol::tcp);
    outPacket->setKind(TCP_C_SEND);
    //HEADER
    const auto& payload = makeShared<Ofp_header>();
    payload->setVersion(OFPV_v100);
    payload->setType(OFPT_BARRIER_REQUEST);
    payload->setLength(OFP_HEADER_SIZE);
    payload->setXid(getEnvir()->getUniqueNumber());
    outPacket->insertAtBack(payload);
    echoReqSend++;
    //CAN BE OTHER
    send(outPacket, "socketOut");
}
void SimpleController::setConfig(int connId, uint16_t flag, uint16_t len) {
    Packet *outPacket = new Packet("SET_CONFIG");
    outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
    outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
            &Protocol::tcp);
    outPacket->setKind(TCP_C_SEND);
    const auto& payload = makeShared<Ofp_header>();
    payload->setVersion(OFPV_v100);
    payload->setType(OFPT_SET_CONFIG);
    payload->setLength(OFP_HEADER_SIZE + OFP_SET_CONFIG_SIZE);
    payload->setXid(getEnvir()->getUniqueNumber());
    outPacket->insertAtBack(payload);
    const auto& payload_c = makeShared<Ofp_set_config>();
    payload_c->setFlag(flag);
    payload_c->setLen(len);
    outPacket->insertAtBack(payload_c);
    send(outPacket, "socketOut");
}
void SimpleController::sendFeatureReq(int connId) {
    Packet *outPacket = new Packet("FEATURES_REQ");
    outPacket->addTagIfAbsent<SocketReq>()->setSocketId(connId);
    outPacket->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
            &Protocol::tcp);
    outPacket->setKind(TCP_C_SEND);
    const auto& payload = makeShared<Ofp_header>();
    payload->setVersion(OFPV_v100);
    payload->setType(OFPT_FEATURES_REQUEST);
    payload->setLength(OFP_HEADER_SIZE);
    payload->setXid(getEnvir()->getUniqueNumber());
    outPacket->insertAtBack(payload);
    send(outPacket, "socketOut");
    featSend++;
}
void SimpleController::handleSelfMessage(cMessage *msg) {
    timer* t = dynamic_cast<timer*>(msg);
    if (t) {
        auto type = t->getType();
        auto connId = t->getConnId();
        switch (type) {
        case ECHO_INTERVAL_TIMER: {
            sendEchoReq(connId);
            if (timersMap[connId]->isScheduled()) {
                cancelEvent(timersMap[connId]);
                timersMap[connId]->setType(ECHO_CANCEL_TIMER);
                scheduleAt(simTime() + echoCancelInterval, timersMap[connId]);
                return;
            }
            break;
        }
        case ECHO_CANCEL_TIMER: {
            auto request = new Request("close", TCP_C_CLOSE);
            request->addTagIfAbsent<SocketReq>()->setSocketId(connId);
            sendBack(request);
            itC2S = con2switch.find(connId);
            itSM = switchMap.find(itC2S->second);
            delete itSM->second;
            switchMap.erase(itSM);
            con2switch.erase(itC2S);
            itC2S = con2switch.begin();
            itSM = switchMap.begin();
            break;
        }
        case PORT_BLOCK_TIMER:
            //TODO Temporary blocking in apps or sth:D
            break;
        case FEATURE_WAIT_TIMER: {
            auto request = new Request("close", TCP_C_CLOSE);
            request->addTagIfAbsent<SocketReq>()->setSocketId(connId);
            sendBack(request);
            break;
        }
        case HELLO_WAIT_TIMER: {
            auto request = new Request("close", TCP_C_CLOSE);
            request->addTagIfAbsent<SocketReq>()->setSocketId(connId);
            sendBack(request);
            break;
        }
        }
        timersMap.erase(connId);
    } else {
        perror("BAD TIMER!");
    }
    delete msg;
    msg = nullptr;
}
void SimpleController::finish() {
    EV << "Had connection with:" << endl;
    itSM = switchMap.begin();
    while (itSM != switchMap.end()) {
        EV << itSM->second << endl;
        delete itSM->second;
        switchMap.erase(itSM);
        itSM = switchMap.begin();
    }
    recordScalar("Received HELLO", helloRec);
    recordScalar("Received ECHO_REQ", echoReqRec);
    recordScalar("Received ECHO_REP", echoRepRec);
    recordScalar("Received ERROR", errorRec);
    recordScalar("Received FEATURES_REP", featRec);
    recordScalar("Received CONFIG_REP", getConRepRec);
    recordScalar("Received PACKET_IN", packInRec);
    recordScalar("Received FLOW_REMOVED", flRemRec);
    recordScalar("Received PORT_STATUS_REP", portStRec);
    recordScalar("Received STATISTICS_REP", statRepRec);
    recordScalar("Received BARRIER_REP", barRepRec);

    recordScalar("Received ARP Requests via PACKET_IN payload", arpReqRec);
    recordScalar("Received ARP Replies via PACKET_IN payload", arpRepRec);
    recordScalar("Received IPv4 via PACKET_IN payload", ipV4Rec);

    recordScalar("Sent HELLO", helloSend);
    recordScalar("Sent ECHO_REQ", echoReqSend);
    recordScalar("Sent ECHO_REP", echoRepSend);
    recordScalar("Sent ERROR", errorRec);
    recordScalar("Sent FEATURES_REP", featSend);
    recordScalar("Sent CONFIG_REP", getConReqSend);
    recordScalar("Sent PACKET_OUT", packOutSend);
    recordScalar("Sent FLOW_MOD", flModSend);
    recordScalar("Sent STATISTICS_REP", statReqSend);
    recordScalar("Sent BARRIER_REP", barReqSend);

    recordScalar("Sent ARP Requests via PACKET_OUT payload", arpReqSend);
    recordScalar("Sent ARP Replies via PACKET_OUT payload", arpRepSend);
    recordScalar("Sent IPv4 via PACKET_OUT payload", ipV4Send);

}
