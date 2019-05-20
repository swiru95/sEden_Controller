//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "OfpheaderSerializer.h"
#include "ofp_header_m.h"
#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"

using namespace inet;

Register_Serializer(Ofp_header, Ofp_headerSerializer);

void Ofp_headerSerializer::serialize(MemoryOutputStream& stream,
        const Ptr<const Chunk>& chunk) const {
 //   auto startPosition = stream.getLength();
    const auto& msg = staticPtrCast<const Ofp_header>(chunk);
    stream.writeUint8(B(msg->getVersion()).get());
    stream.writeUint8(B(msg->getType()).get());
    stream.writeUint16Be(B(msg->getLength()).get());
    stream.writeUint32Be(B(msg->getXid()).get());
}

const Ptr<Chunk> Ofp_headerSerializer::deserialize(
        MemoryInputStream& stream) const {
//    auto startPosition = stream.getPosition();
    auto msg = makeShared<Ofp_header>();
    msg->setVersion(stream.readUint8());
    msg->setType(stream.readUint8());
    msg->setLength(stream.readUint16Be());
    msg->setXid(stream.readUint32Be());
    return msg;

}
