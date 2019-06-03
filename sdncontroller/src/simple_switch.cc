#include "SimpleController.h"

#include <sstream>
#include <chrono>
/**TODO
 *Suppose to work like normal switch but it wont, there is also an Error in Mininet or sth (line 34)
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
        payload->setLength(len-10);
        outPacket->insertAtBack(payload);
        const auto& payloadMatch = makeShared<Ofp_match>();
        payloadMatch->setWildcards(1 << 2);
        payloadMatch->setDl_dst(appEthData->getSrc());
        outPacket->insertAtBack(payloadMatch);

        send(outPacket, "socketOut");
        return;
    }

//////////////////IPv6
    if (appEthData->getTypeOrLength() == ETHERTYPE_IPv6) {
        EV << "IPV6" << endl;

        return;
        //TODO
    }
}
