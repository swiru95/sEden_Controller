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

namespace inet;
enum phy_port_id{
  	  MAX=0xFF00;
  	  IN_PORT=0xFFF8;
  	  TABLE=0xFFF9;
  	  NORMAL=0xFFFA;
  	  FLOOD=0xFFFB;
  	  ALL=0xFFFC;
  	  CONTROLLER=0xFFFD;
  	  LOCAL=0xFFFE;
  	  NONE=0xFFFF;
};
enum phy_port_config{
	PORT_DOWN    = 0x00000001;
	NO_STP       = 0x00000002;
	NO_RECV      = 0x00000004;
	NO_RECV_STP  = 0x00000008;
	NO_FLOOD     = 0x00000010;
	NO_FWD       = 0x00000020;
	NO_PACKET_IN = 0x00000040;
};
enum phy_port_state{
 	STP_LSITEN=0x00000000;
 	LINK_DOWN=0x00000001;
 	STP_LEARN=0x00000002;
 	STP_FORWARD=0x00000004;
 	STP_BLOCK=0x00000008;
 	STP_MASK =0x00000010;  
};
enum phy_port_feature{
 	TEN_MB_HD=0x00000001;
	TEN_MB_FD=0x00000002;
	HUN_MB_HD=0x00000004;
	HUN_MB_FD=0x00000008;
	GB_HD=0x00000010;
	GB_FD=0x00000020;
	TEN_GB_FD=0x00000040;
	COOPER=0x00000080;
	FIBER=0x00000100;
	AUTONEG=0x00000200;
	PAUSE=0x00000400;
	PAUSE_ASYM=0x00000800;
};
class Ofp_phy_port extends FieldsChunk{
	uint16_t port_no;
	MacAddress hw_addr;
	char name[16];
	uint32_t config;
	uint32_t state;
	uint32_t curr;
	uint32_t advertised;
	uint32_t supported;
	uint32_t peer;
	chunkLength=B(48);
}
class Ofp_port_mode extends FieldsChunk{
	uint16_t port_no;
	MacAddress hw_addr;
	uint32_t config;
	uint32_t mask;
	uint32_t advertise;
	uint64_t pad=0;
	chunkLength=B(24);
}