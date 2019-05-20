/*
 * OfpsetconfigSerializer.h
 *
 *  Created on: Feb 25, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPSETCONFIGSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPSETCONFIGSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"

namespace inet {

class Ofp_setconfigSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_setconfigSerializer() :
            FieldsChunkSerializer() {
    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPSETCONFIGSERIALIZER_H_ */
