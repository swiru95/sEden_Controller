/*
 * OfpMachSerializer.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: root
 */

#include "OfpmatchSerializer.h"

#include "ofp_match_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_match, Ofp_matchSerializer);

void Ofp_matchSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_match>(chunk);
    stream.writeUint32Be(B(msg->getWildcards()).get());
    stream.writeUint16Be(B(msg->getIn_port()).get());
    stream.writeMacAddress(msg->getDl_src());
    stream.writeMacAddress(msg->getDl_dst());
    stream.writeUint16Be(B(msg->getDl_vlan()).get());
    stream.writeUint8(B(msg->getDl_vlan_pcp()).get());
    stream.writeUint8(B(msg->getPad1(0)).get());
    stream.writeUint16Be(B(msg->getDl_type()).get());
    stream.writeUint8(B(msg->getNw_tos()).get());
    stream.writeUint8(B(msg->getNw_proto()).get());
    stream.writeUint8(B(msg->getPad2(0)).get());
    stream.writeUint8(B(msg->getPad2(1)).get());
    stream.writeIpv4Address(msg->getNw_src());
    stream.writeIpv4Address(msg->getNw_dst());
    stream.writeUint16Be(B(msg->getTp_src()).get());
    stream.writeUint16Be(B(msg->getTp_dst()).get());
    //TODO

}

const Ptr<Chunk> Ofp_matchSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_match>();
    msg->setWildcards(stream.readUint32Be());
    msg->setIn_port(stream.readUint16Be());
    msg->setDl_src(stream.readMacAddress());
    msg->setDl_dst(stream.readMacAddress());
    msg->setDl_vlan(stream.readUint16Be());
    msg->setDl_vlan_pcp(stream.readUint8());
    msg->setPad1(0, stream.readUint8());
    msg->setDl_type(stream.readUint16Be());
    msg->setNw_tos(stream.readUint8());
    msg->setNw_proto(stream.readUint8());
    msg->setPad2(0, stream.readUint8());
    msg->setPad2(1, stream.readUint8());
    msg->setNw_src(stream.readIpv4Address());
    msg->setNw_dst(stream.readIpv4Address());
    msg->setTp_src(stream.readUint16Be());
    msg->setTp_dst(stream.readUint16Be());

    //TODO

    return msg;

}
