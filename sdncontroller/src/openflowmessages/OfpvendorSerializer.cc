/*
 * OfpvendorSerializer.cc
 *
 *  Created on: Feb 27, 2019
 *      Author: root
 */

#include "OfpvendorSerializer.h"
#include "ofp_vendor_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_vendor, Ofp_vendorSerializer);

void Ofp_vendorSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_vendor>(chunk);
    stream.writeUint32Be(B(msg->getVendor()).get());

}

const Ptr<Chunk> Ofp_vendorSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_vendor>();
    msg->setVendor(stream.readUint32Be());

    return msg;
}
