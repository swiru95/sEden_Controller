#include "SimpleController.h"

#include <sstream>
#include <chrono>
/**TODO
 *Suppose to work like normal switch but it wont, there is also an Error in Mininet or sth (line 31)
 *Should be 1<<3 according to specification of OFlowv100.
 */
void SimpleController::simpleSwitch(ChunkQueue& queue, int connId) {

    auto& appPktInMsg = queue.pop<Ofp_packet_in>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
    auto& appEthData = queue.pop<EthernetMacHeader>(b(-1),
            Chunk::PF_ALLOW_NULLPTR);
//////////////////ARP
    if (appEthData->getTypeOrLength() == ETHERTYPE_ARP) {
        EV << "ARP!" << endl;
        auto& appArpData = queue.pop<ArpPacket>(b(-1), Chunk::PF_ALLOW_NULLPTR);

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
        payloadMatch->setWildcards(1 << 2);
        payloadMatch->setDl_dst(appEthData->getSrc());
        outPacket->insertAtBack(payloadMatch);
        const auto& payloadFm = makeShared<Ofp_flow_mod>();
        payloadFm->setCookie(getEnvir()->getUniqueNumber());
        payloadFm->setCommand(OFPFC_ADD);
        payloadFm->setIdle_timeout(tIdle);
        payloadFm->setHard_timeout(tHard);
        payloadFm->setPriority(1);
        payloadFm->setBuffer_id(-1);
        payloadFm->setOut_port(appPktInMsg->getIn_port());
        payloadFm->setFlags(0);
        outPacket->insertAtBack(payloadFm);
        const auto& payloadAh = makeShared<Ofp_action_head>();
        payloadAh->setType(0);   //to swport
        len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
        payloadAh->setLength(len);
        outPacket->insertAtBack(payloadAh);
        const auto& payloadA = makeShared<Ofp_output_action>();
        payloadA->setPort(appPktInMsg->getIn_port());
        payloadA->setMax_len(0xFFFF);
        outPacket->insertAtBack(payloadA);

        send(outPacket, "socketOut");

        Packet *outPacket2 = new Packet("PACKET_OUT");
        outPacket2->addTagIfAbsent<SocketReq>()->setSocketId(connId);
        outPacket2->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(
                &Protocol::tcp);
        outPacket2->setKind(TCP_C_SEND);
        const auto& payload1 = makeShared<Ofp_header>();
        payload1->setVersion(OFPV_v100);
        payload1->setType(OFPT_PACKET_OUT);
        payload1->setXid(getEnvir()->getUniqueNumber());
        len = OFP_HEADER_SIZE + OFP_PACKET_OUT_SIZE
                + OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE
                + MAC_HEADER_SIZE + ARP_SIZE;
        payload1->setLength(len);
        outPacket2->insertAtBack(payload1);
        const auto& payload1PktOut = makeShared<Ofp_packet_out>();
        payload1PktOut->setBuffer_id(appPktInMsg->getBuffer_id());
        payload1PktOut->setIn_port(appPktInMsg->getIn_port());
        len = OFP_ACTIONS_HEAD_SIZE + OFP_OUTPUT_ACTION_SIZE;
        payload1PktOut->setActions_len(len);
        outPacket2->insertAtBack(payload1PktOut);
        const auto& payload1Ah = makeShared<Ofp_action_head>();
        payload1Ah->setType(OUTPUT_ACTION);   //to swport
        payload1Ah->setLength(len);
        outPacket2->insertAtBack(payload1Ah);
        const auto& payload1A = makeShared<Ofp_output_action>();

        if (appArpData->getOpcode() == ARP_REQUEST)
            payload1A->setPort(FLOOD);
        else
            payload1A->setPort(TABLE);

        payload1A->setMax_len(0xFFFF);
        outPacket2->insertAtBack(payload1A);
        outPacket2->insertAtBack(appEthData);
        outPacket2->insertAtBack(appArpData);

        send(outPacket2, "socketOut");
        return;
    }

//////////////////IPv6
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
        EV << "IPV6" << endl;

        return;
        //TODO
    }
}
