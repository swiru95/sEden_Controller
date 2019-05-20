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
import inet.common.INETDefs;
import inet.common.Units;
import inet.common.packet.chunk.Chunk;

namespace inet;

enum Flag_conf{
  OFPC_FRAG_NORMAL   = 0x0000;//NORMAL
  OFPC_FRAG_DROP     = 0x0001;//DROP
  OFPC_FRAG_REASM    = 0x0002;//REASEMBLE
  OFPC_FRAG_MASK     = 0x0003;//FRAG MASK
};

class Ofp_set_config extends FieldsChunk {
    
    uint16_t flag;
    uint16_t len;
    chunkLength=B(4);

}