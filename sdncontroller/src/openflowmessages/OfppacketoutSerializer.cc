/*
 * OfppacketoutSerializer.cc
 *
 *  Created on: Mar 6, 2019
 *      Author: root
 */

#include "OfppacketoutSerializer.h"
#include "ofp_packet_in_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_packet_out,Ofp_packetoutSerializer);

void Ofp_packetoutSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_packet_out>(chunk);
    stream.writeUint32Be(B(msg->getBuffer_id()).get());
    stream.writeUint16Be(B(msg->getIn_port()).get());
    stream.writeUint16Be(B(msg->getActions_len()).get());
}

const Ptr<Chunk> Ofp_packetoutSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_packet_out>();
    msg->setBuffer_id(stream.readUint32Be());
    msg->setIn_port(stream.readUint16Be());
    msg->setActions_len(stream.readUint16Be());
    return msg;
}
