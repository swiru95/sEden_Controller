/*
 * OfpfeatureSerializer.cc
 *
 *  Created on: Feb 28, 2019
 *      Author: root
 */

#include "OfpfeatureSerializer.h"
#include "ofp_feature_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_feature, Ofp_featureSerializer);

void Ofp_featureSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
    const auto& msg = staticPtrCast<const Ofp_feature>(chunk);
    stream.writeUint64Be(B(msg->getDatapath_id()).get());
    stream.writeUint32Be(B(msg->getN_buffers()).get());
    stream.writeUint8(B(msg->getN_tables()).get());
    for (int i = 0; i < 3; i++)
        stream.writeUint8(B(msg->getPad(i)).get());
    stream.writeUint32Be(B(msg->getCapabilities()).get());
    stream.writeUint32Be(B(msg->getActions()).get());
}

const Ptr<Chunk> Ofp_featureSerializer::deserialize(
        MemoryInputStream& stream) const {
    auto msg = makeShared<Ofp_feature>();
    msg->setDatapath_id(stream.readUint64Be());
    msg->setN_buffers(stream.readUint32Be());
    msg->setN_tables(stream.readUint8());
    for (int i = 0; i < 3; i++)
        msg->setPad(i, stream.readUint8());
    msg->setCapabilities(stream.readUint32Be());
    msg->setActions(stream.readUint32Be());

    return msg;
}
