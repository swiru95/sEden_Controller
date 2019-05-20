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
import inet.linklayer.common.MacAddress;
import inet.networklayer.contract.ipv4.Ipv4Address;

namespace inet;

enum action_type{
 OUTPUT_ACTION=0x0000;
 SET_VLAN_VID=0x0001;
 SET_VLAN_PCP=0x0002;
 STRIP_VLAN=0x0003;
 SET_DL_SRC=0x0004;
 SET_DL_DST=0x0005;
 SET_NW_SRC=0x0006;
 SET_NW_DST=0x0007;
 SET_NW_TOS=0x0008;
 SET_TP_SRC=0x0009;
 SET_TP_DST=0x000a;
 ENQUEUE_ACTION=0x000b;
 VENDOR_ACTION=0xffff;
};


class Ofp_action_head extends FieldsChunk {
 	uint16_t type;
 	uint16_t length;
 	chunkLength=B(4);   
}

////////////////////PAYLOADS_ACTIONS/////////////////////

class Ofp_output_action extends FieldsChunk {
	uint16_t port;
	uint16_t max_len;
	chunkLength=B(4);
}
class Ofp_enqueue_action extends FieldsChunk {
 	uint16_t port;
 	uint16_t pad1=0;
 	uint32_t pad2=0;
 	uint32_t queue_id;
 	chunkLength=B(6);  
}
class Ofp_setvlanvid_action extends FieldsChunk {
 	uint16_t vlan_vid;
 	uint16_t pad=0;
 	chunkLength=B(4);
}
class Ofp_setnwaddr_action extends FieldsChunk {
 	Ipv4Address nw_addr;
 	chunkLength=B(4);   
}
class Ofp_vendor_action extends FieldsChunk {
 	uint32_t vendor;
 	chunkLength=B(4);   
}
class Ofp_setvlanpcp_action extends FieldsChunk {
  	uint8_t vlan_pc;
  	uint8_t pad1=0;
  	uint16_t pad2=0;
  	chunkLength=B(4);
} 
class Ofp_setnwtos_action extends FieldsChunk {
    uint8_t nw_tos;
    uint8_t pad1=0;
  	uint16_t pad2=0;
  	chunkLength=B(4);
}
class Ofp_setdladdr_action extends FieldsChunk {
 	MacAddress dl_addr;
 	uint16_t pad1=0;
 	uint32_t pad2=0;
 	chunkLength=B(12);	
}
class Ofp_settcport_action extends FieldsChunk {
 	uint16_t port;
 	uint16_t pad;
 	chunkLength=B(4);   
}