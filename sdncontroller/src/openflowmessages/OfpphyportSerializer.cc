/*
 * OfpphyportSerializer.cc
 *
 *  Created on: Feb 28, 2019
 *      Author: root
 */

#include "ofp_phy_port_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"
#include "OfpphyportSerializer.h"

using namespace inet;

Register_Serializer(Ofp_phy_port, Ofp_phyportSerializer);
Register_Serializer(Ofp_port_mode, Ofp_portModeSerializer);


void Ofp_phyportSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_phy_port>(chunk);
    stream.writeUint16Be(B(msg->getPort_no()).get());
   stream.writeMacAddress(msg->getHw_addr());
    for (int i = 0; i < 16; i++)
        stream.writeByte(B(msg->getName(i)).get());
    stream.writeUint32Be(B(msg->getConfig()).get());
    stream.writeUint32Be(B(msg->getState()).get());
    stream.writeUint32Be(B(msg->getCurr()).get());
    stream.writeUint32Be(B(msg->getAdvertised()).get());
    stream.writeUint32Be(B(msg->getSupported()).get());
    stream.writeUint32Be(B(msg->getPeer()).get());

}

const Ptr<Chunk> Ofp_phyportSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_phy_port>();
    msg->setPort_no(stream.readUint16Be());
    msg->setHw_addr(stream.readMacAddress());
    for (int i = 0; i < 16; i++)
        msg->setName(i, stream.readByte());
    msg->setConfig(stream.readUint32Be());
    msg->setState(stream.readUint32Be());
    msg->setCurr(stream.readUint32Be());
    msg->setAdvertised(stream.readUint32Be());
    msg->setSupported(stream.readUint32Be());
    msg->setPeer(stream.readUint32Be());

    return msg;

}

void Ofp_portModeSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_port_mode>(chunk);
    stream.writeUint16Be(B(msg->getPort_no()).get());
    stream.writeMacAddress(msg->getHw_addr());
    stream.writeUint32Be(B(msg->getConfig()).get());
    stream.writeUint32Be(B(msg->getMask()).get());
    stream.writeUint32Be(B(msg->getAdvertise()).get());
    stream.writeUint32Be(B(msg->getPad()).get());

}

const Ptr<Chunk> Ofp_portModeSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_port_mode>();
    msg->setPort_no(stream.readUint16Be());
    msg->setHw_addr(stream.readMacAddress());
    msg->setConfig(stream.readUint32Be());
    msg->setMask(stream.readUint32Be());
    msg->setAdvertise(stream.readUint32Be());
    msg->setPad(stream.readUint32Be());

    return msg;
}
