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

class Ofp_match extends FieldsChunk {
    
    uint32_t wildcards;
    uint16_t in_port;
    MacAddress dl_src;
    MacAddress dl_dst;
    uint16_t dl_vlan;
    uint8_t dl_vlan_pcp;
    uint8_t pad1[1];
    uint16_t dl_type;
    uint8_t nw_tos;
    uint8_t nw_proto;
    uint8_t pad2[2];
    Ipv4Address nw_src;
    Ipv4Address nw_dst;
    uint16_t tp_src;
    uint16_t tp_dst;
    
    chunkLength=B(40);
}   
    
    