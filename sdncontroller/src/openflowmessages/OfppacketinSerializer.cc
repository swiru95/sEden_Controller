/*
 * OfppacketinSerializer.cc
 *
 *  Created on: Mar 6, 2019
 *      Author: root
 */

#include "OfppacketinSerializer.h"
#include "ofp_packet_in_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_packet_in,Ofp_packetinSerializer);

void Ofp_packetinSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_packet_in>(chunk);
    stream.writeUint32Be(B(msg->getBuffer_id()).get());
    stream.writeUint16Be(B(msg->getTotal_len()).get());
    stream.writeUint16Be(B(msg->getIn_port()).get());
    stream.writeUint8(B(msg->getReason()).get());
    stream.writeUint8(B(msg->getPad()).get());
}

const Ptr<Chunk> Ofp_packetinSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_packet_in>();
    msg->setBuffer_id(stream.readUint32Be());
    msg->setTotal_len(stream.readUint16Be());
    msg->setIn_port(stream.readUint16Be());
    msg->setReason(stream.readUint8());
    msg->setPad(stream.readUint8());
    return msg;
}
