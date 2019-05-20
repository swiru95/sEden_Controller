/*
 * OfpactionheadSerializer.cc
 *
 *  Created on: Mar 3, 2019
 *      Author: root
 */

#include "OfpactionheadSerializer.h"
#include "ofp_actions_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_action_head, Ofp_actionheadSerializer);
Register_Serializer(Ofp_output_action, Ofp_outputactionSerializer);
Register_Serializer(Ofp_enqueue_action, Ofp_enqueueactionSerializer);
Register_Serializer(Ofp_setvlanvid_action, Ofp_setvlanvidactionSerializer);
Register_Serializer(Ofp_setnwaddr_action, Ofp_setnwaddractionSerializer);
Register_Serializer(Ofp_vendor_action, Ofp_vendoractionSerializer);
Register_Serializer(Ofp_setvlanpcp_action, Ofp_setvlanpcpactionSerializer);
Register_Serializer(Ofp_setnwtos_action, Ofp_setnwtosactionSerializer);
Register_Serializer(Ofp_setdladdr_action, Ofp_setdladdractionSerializer);
Register_Serializer(Ofp_settcport_action, Ofp_settcportactionSerializer);

void Ofp_actionheadSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_action_head>(chunk);
    stream.writeUint16Be(B(msg->getType()).get());
    stream.writeUint16Be(B(msg->getLength()).get());
}

const Ptr<Chunk> Ofp_actionheadSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_action_head>();
    msg->setType(stream.readUint16Be());
    msg->setLength(stream.readUint16Be());
    return msg;
}

void Ofp_outputactionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_output_action>(chunk);
    stream.writeUint16Be(B(msg->getPort()).get());
    stream.writeUint16Be(B(msg->getMax_len()).get());
}

const Ptr<Chunk> Ofp_outputactionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_output_action>();
    msg->setPort(stream.readUint16Be());
    msg->setMax_len(stream.readUint16Be());
    return msg;
}

void Ofp_enqueueactionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_enqueue_action>(chunk);
    stream.writeUint16Be(B(msg->getPort()).get());
    stream.writeUint16Be(B(msg->getPad1()).get());
    stream.writeUint32Be(B(msg->getPad2()).get());
    stream.writeUint32Be(B(msg->getQueue_id()).get());
}

const Ptr<Chunk> Ofp_enqueueactionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_enqueue_action>();
    msg->setPort(stream.readUint16Be());
    msg->setPad1(stream.readUint16Be());
    msg->setPad2(stream.readUint32Be());
    msg->setQueue_id(stream.readUint32Be());
    return msg;
}

void Ofp_setvlanvidactionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_setvlanvid_action>(chunk);
    stream.writeUint16Be(B(msg->getVlan_vid()).get());
    stream.writeUint16Be(B(msg->getPad()).get());
}

const Ptr<Chunk> Ofp_setvlanvidactionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_setvlanvid_action>();
    msg->setVlan_vid(stream.readUint16Be());
    msg->setPad(stream.readUint16Be());
    return msg;
}

void Ofp_setnwaddractionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_setnwaddr_action>(chunk);
    stream.writeIpv4Address(msg->getNw_addr());
}

const Ptr<Chunk> Ofp_setnwaddractionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_setnwaddr_action>();
    msg->setNw_addr(stream.readIpv4Address());
    return msg;
}

void Ofp_vendoractionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_vendor_action>(chunk);
    stream.writeUint32Be(B(msg->getVendor()).get());
}

const Ptr<Chunk> Ofp_vendoractionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_vendor_action>();
    msg->setVendor(stream.readUint32Be());
    return msg;
}

void Ofp_setvlanpcpactionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_setvlanpcp_action>(chunk);
    stream.writeUint8(B(msg->getVlan_pc()).get());
    stream.writeUint8(B(msg->getPad1()).get());
    stream.writeUint16Be(B(msg->getPad2()).get());
}

const Ptr<Chunk> Ofp_setvlanpcpactionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_setvlanpcp_action>();
    msg->setVlan_pc(stream.readUint8());
    msg->setPad1(stream.readUint8());
    msg->setPad2(stream.readUint16Be());
    return msg;
}

void Ofp_setnwtosactionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_setnwtos_action>(chunk);
    stream.writeUint8(B(msg->getNw_tos()).get());
    stream.writeUint8(B(msg->getPad1()).get());
    stream.writeUint16Be(B(msg->getPad2()).get());
}

const Ptr<Chunk> Ofp_setnwtosactionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_setnwtos_action>();
    msg->setNw_tos(stream.readUint8());
    msg->setPad1(stream.readUint8());
    msg->setPad2(stream.readUint16Be());
    return msg;
}

void Ofp_setdladdractionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_setdladdr_action>(chunk);
    stream.writeMacAddress(msg->getDl_addr());
    stream.writeUint16Be(B(msg->getPad1()).get());
    stream.writeUint32Be(B(msg->getPad2()).get());
}

const Ptr<Chunk> Ofp_setdladdractionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_setdladdr_action>();
    msg->setDl_addr(stream.readMacAddress());
    msg->setPad1(stream.readUint16Be());
    msg->setPad2(stream.readUint32Be());
    return msg;
}

void Ofp_settcportactionSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_settcport_action>(chunk);
    stream.writeUint16Be(B(msg->getPort()).get());
    stream.writeUint16Be(B(msg->getPad()).get());
}

const Ptr<Chunk> Ofp_settcportactionSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_settcport_action>();
    msg->setPort(stream.readUint16Be());
    msg->setPad(stream.readUint16Be());
    return msg;
}
