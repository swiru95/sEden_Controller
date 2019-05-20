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

enum feature_capabilities{
 	FLOW_STATS=0x00000001;
 	TABLE_STATS=0x00000002;
 	PORT_STATS=0x00000004;
 	STP=0x00000008;
 	RESERVED=0x00000010;
 	IP_REASM=0x00000020;
 	QUEUE_STATS=0x00000040;
 	ARP_MATCH_IP=0x00000080;   
};
enum feature_actions{
  OFPF_OUTPUT=0x00000001;
  OFPF_SET_VLAN_VID=0x00000002;
  OFPF_SET_VLAN_PCP=0x00000004;
  OFPF_STRIP_VLAN=0x00000008;
  OFPF_SET_DL_SRC=0x00000010;
  OFPF_SET_DL_DST=0x00000020;
  OFPF_SET_NW_SRC=0x00000040;
  OFPF_SET_NW_DST=0x00000080;
  OFPF_SET_NW_TOS=0x00000100;
  OFPF_SET_TP_SRC=0x00000200;
  OFPF_SET_TP_DST=0x00000400;
  OFPF_ENQUEUE=0x00000800;  
};

class Ofp_feature extends FieldsChunk {
 
 	uint64_t datapath_id;
 	uint32_t n_buffers;
 	uint8_t n_tables;
 	uint8_t pad[3];
 	uint32_t capabilities;
 	uint32_t actions;
 	chunkLength=B(24);
    
}