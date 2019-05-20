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

enum reason {
 	NO_MATCH=0x00;
 	ACTION=0x01;
}
class Ofp_packet_in extends FieldsChunk {
 	uint32_t buffer_id;
 	uint16_t total_len;
 	uint16_t in_port;
 	uint8_t reason;
 	uint8_t pad=0x00;
 	chunkLength=B(12);
}

class Ofp_packet_out extends FieldsChunk {
 	uint32_t buffer_id;
 	uint16_t in_port;
 	uint16_t actions_len;
 	chunkLength=B(8);
}