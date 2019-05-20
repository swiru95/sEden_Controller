/*
 * OfpfeatureSerializer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPFEATURESERIALIZER_H_
#define OPENFLOWMESSAGES_OFPFEATURESERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
namespace inet {

class Ofp_featureSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;

public:
    Ofp_featureSerializer():FieldsChunkSerializer(){
    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPFEATURESERIALIZER_H_ */
