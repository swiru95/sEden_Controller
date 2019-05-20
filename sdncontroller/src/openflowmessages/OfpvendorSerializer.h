/*
 * OfpvendorSerializer.h
 *
 *  Created on: Feb 27, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPVENDORSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPVENDORSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
namespace inet {

class Ofp_vendorSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_vendorSerializer() :
            FieldsChunkSerializer() {
    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPVENDORSERIALIZER_H_ */
