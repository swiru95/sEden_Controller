/*
 * OfpphyportSerializer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPPHYPORTSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPPHYPORTSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
namespace inet {

class Ofp_phyportSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_phyportSerializer() :
            FieldsChunkSerializer() {
    }
};
class Ofp_portModeSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_portModeSerializer() :
            FieldsChunkSerializer() {
    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPphyportSerializerSERIALIZER_H_ */
