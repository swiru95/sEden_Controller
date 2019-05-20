/*
 * OfpflowmodSerializer.cc
 *
 *  Created on: Mar 3, 2019
 *      Author: root
 */

#include "OfpflowmodSerializer.h"
#include "ofp_flow_mod_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

Register_Serializer(Ofp_flow_mod,Ofp_flowmodSerializer);

void Ofp_flowmodSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_flow_mod>(chunk);
    stream.writeUint64Be(B(msg->getCookie()).get());
    stream.writeUint16Be(B(msg->getCommand()).get());
    stream.writeUint16Be(B(msg->getIdle_timeout()).get());
    stream.writeUint16Be(B(msg->getHard_timeout()).get());
    stream.writeUint16Be(B(msg->getPriority()).get());
    stream.writeUint32Be(B(msg->getBuffer_id()).get());
    stream.writeUint16Be(B(msg->getOut_port()).get());
    stream.writeUint16Be(B(msg->getFlags()).get());
}

const Ptr<Chunk> Ofp_flowmodSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_flow_mod>();
    msg->setCookie(stream.readUint64Be());
    msg->setCommand(stream.readUint16Be());
    msg->setIdle_timeout(stream.readUint16Be());
    msg->setHard_timeout(stream.readUint16Be());
    msg->setPriority(stream.readUint16Be());
    msg->setBuffer_id(stream.readUint32Be());
    msg->setOut_port(stream.readUint16Be());
    msg->setFlags(stream.readUint16Be());

    return msg;

}

