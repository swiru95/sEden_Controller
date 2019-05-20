/*
 * OfppacketinSerializer.h
 *
 *  Created on: Mar 6, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPPACKETINSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPPACKETINSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
namespace inet {

class Ofp_packetinSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;

public:
    Ofp_packetinSerializer() :
            FieldsChunkSerializer() {

    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPPACKETINSERIALIZER_H_ */
