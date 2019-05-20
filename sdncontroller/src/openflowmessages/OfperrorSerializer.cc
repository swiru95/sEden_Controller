/*
 * OfperrorSerializer.cpp
 *
 *  Created on: Feb 27, 2019
 *      Author: root
 */

#include "OfperrorSerializer.h"
#include "ofp_error_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

namespace inet {

Register_Serializer(Ofp_error, Ofp_errorSerializer);

void Ofp_errorSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_error>(chunk);
    stream.writeUint16Be(B(msg->getType()).get());
    stream.writeUint16Be(B(msg->getCode()).get());
}

const Ptr<Chunk> Ofp_errorSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_error>();
    msg->setType(stream.readUint16Be());
    msg->setCode(stream.readUint16Be());
    return msg;
}
}
