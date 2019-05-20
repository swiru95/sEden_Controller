/*
 * OfpflowmodSerializer.h
 *
 *  Created on: Mar 3, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPFLOWMODSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPFLOWMODSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
using namespace inet;

class Ofp_flowmodSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_flowmodSerializer() :
            FieldsChunkSerializer() {
    }

};

#endif /* OPENFLOWMESSAGES_OFPFLOWMODSERIALIZER_H_ */
