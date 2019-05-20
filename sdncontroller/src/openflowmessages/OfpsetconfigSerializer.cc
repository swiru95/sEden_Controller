/*
 * OfpsetconfigSerializer.cc
 *
 *  Created on: Feb 25, 2019
 *      Author: root
 */
#include "OfpsetconfigSerializer.h"
#include "ofp_set_config_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;
/* namespace inet */
Register_Serializer(Ofp_set_config, Ofp_setconfigSerializer);

void Ofp_setconfigSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_set_config>(chunk);
    stream.writeUint16Be(B(msg->getFlag()).get());
    stream.writeUint16Be(B(msg->getLen()).get());
}

const Ptr<Chunk> Ofp_setconfigSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_set_config>();
    msg->setFlag(stream.readUint16Be());
    msg->setLen(stream.readUint16Be());

    return msg;
}
