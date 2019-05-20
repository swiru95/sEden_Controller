/*
 * OfpMachSerializer.h
 *
 *  Created on: Feb 20, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_SERIALIZERS_OFPMACHSERIALIZER_H_
#define OPENFLOWMESSAGES_SERIALIZERS_OFPMACHSERIALIZER_H_

#include "inet/common/packet/serializer/FieldsChunkSerializer.h"

using namespace inet;

class Ofp_matchSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_matchSerializer() :
            FieldsChunkSerializer() {
    }
};

#endif /* OPENFLOWMESSAGES_SERIALIZERS_OFPMACHSERIALIZER_H_ */
