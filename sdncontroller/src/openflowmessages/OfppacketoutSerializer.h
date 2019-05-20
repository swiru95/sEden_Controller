/*
 * OfppacketoutSerializer.h
 *
 *  Created on: Mar 6, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPpacketoutSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPpacketoutSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
namespace inet {

class Ofp_packetoutSerializer: public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;

public:
    Ofp_packetoutSerializer() :
            FieldsChunkSerializer() {

    }
};

} /* namespace inet */

#endif /* OPENFLOWMESSAGES_OFPpacketoutSERIALIZER_H_ */
