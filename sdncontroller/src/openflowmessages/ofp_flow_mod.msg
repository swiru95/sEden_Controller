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

enum ofp_flow_mod_command {
    OFPFC_ADD=0x0000;              
    OFPFC_MODIFY=0x0001;           
    OFPFC_MODIFY_STRICT=0x0002;    
    OFPFC_DELETE=0x0003;           
    OFPFC_DELETE_STRICT=0x0004;    
};

class Ofp_flow_mod extends FieldsChunk{
 	uint64_t cookie;
	uint16_t command;
	uint16_t idle_timeout;
	uint16_t hard_timeout;
	uint16_t priority;
	uint32_t buffer_id;
	uint16_t out_port;
	uint16_t flags;
	chunkLength=B(24);   
}