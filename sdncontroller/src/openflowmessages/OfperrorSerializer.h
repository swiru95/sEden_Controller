/*
 * OfperrorSerializer.h
 *
 *  Created on: Feb 27, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPERRORSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPERRORSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"

namespace inet {

class Ofp_errorSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_errorSerializer() :
            FieldsChunkSerializer() {
    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPERRORSERIALIZER_H_ */
