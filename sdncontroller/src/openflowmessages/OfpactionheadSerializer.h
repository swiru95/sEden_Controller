/*
 * OfpactionheadSerializer.h
 *
 *  Created on: Mar 3, 2019
 *      Author: root
 */

#ifndef OPENFLOWMESSAGES_OFPACTIONHEADSERIALIZER_H_
#define OPENFLOWMESSAGES_OFPACTIONHEADSERIALIZER_H_
#include "inet/common/packet/serializer/FieldsChunkSerializer.h"
using namespace inet;

class Ofp_actionheadSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_actionheadSerializer(): FieldsChunkSerializer(){
    }
};
class Ofp_outputactionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_outputactionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_enqueueactionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_enqueueactionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_setvlanvidactionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_setvlanvidactionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_setnwaddractionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_setnwaddractionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_vendoractionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_vendoractionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_setvlanpcpactionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_setvlanpcpactionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_setnwtosactionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_setnwtosactionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_setdladdractionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_setdladdractionSerializer(): FieldsChunkSerializer(){
    }
};

class Ofp_settcportactionSerializer : public FieldsChunkSerializer {
protected:
    virtual void serialize(MemoryOutputStream& stream,
            const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const
            override;
public:
    Ofp_settcportactionSerializer(): FieldsChunkSerializer(){
    }
};

#endif /* OPENFLOWMESSAGES_OFPACTIONHEADSERIALIZER_H_ */
