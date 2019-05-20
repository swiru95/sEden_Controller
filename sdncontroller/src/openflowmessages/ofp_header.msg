//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License; or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful;
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not; see http://www.gnu.org/licenses/.
// 

//
// Header on all OpenFlow packets
//
import inet.common.INETDefs;
import inet.common.Units;
import inet.common.packet.chunk.Chunk;

namespace inet;

enum Ofp_version {
 	OFPV_v100=0x01; //ok
 	OFPV_v110=0x02;
 	OFPV_v120=0x03;  
 	OFPV_v130=0x04;  
 	OFPV_v140=0x05;
 	OFPV_v150=0x06;       
};
enum Ofp_type {
    
    // Immutable messages.
    OFPT_HELLO=0x00; // Symmetric message */ ok
    OFPT_ERROR=0x01; // Symmetric message */ ok
    OFPT_ECHO_REQUEST=0x02; // Symmetric message */ ok
    OFPT_ECHO_REPLY=0x03; // Symmetric message */ ok
    OFPT_VENDOR=0x04; // Symmetric message */ ok

    // Switch configuration messages. */
    OFPT_FEATURES_REQUEST=0x05; // Controller/switch message */ ok
    OFPT_FEATURES_REPLY=0x06; // Controller/switch message */ ok
    OFPT_GET_CONFIG_REQUEST=0x07; // Controller/switch message */ ok
    OFPT_GET_CONFIG_REPLY=0x08; // Controller/switch message */ ok
    OFPT_SET_CONFIG=0x09; // Controller/switch message */ ok

    // Asynchronous messages. */
    OFPT_PACKET_IN=0x0A; // Async message */
    OFPT_FLOW_REMOVED=0x0B; // Async message */
    OFPT_PORT_STATUS=0x0C; // Async message */

    // Controller command messages. */
    OFPT_PACKET_OUT=0x0D; // Controller/switch message */
    OFPT_FLOW_MOD=0x0E; // Controller/switch message */
    OFPT_PORT_MOD=0x0F; // Controller/switch message */

    // Statistics messages. */
    OFPT_STATS_REQUEST=0x11; // Controller/switch message */
    OFPT_STATS_REPLY=0x12; // Controller/switch message */

    // Barrier messages. */
    OFPT_BARRIER_REQUEST=0x13; // Controller/switch message */ ok
    OFPT_BARRIER_REPLY=0x14; // Controller/switch message */ ok

    // Queue Configuration messages. */
    OFPT_QUEUE_GET_CONFIG_REQUEST=0x15; // Controller/switch message */
    OFPT_QUEUE_GET_CONFIG_REPLY=0x16;

};


class Ofp_header extends FieldsChunk {
    
    uint8_t version;
    uint8_t type;
    uint16_t length;
    uint32_t xid;
    chunkLength=B(8);

}
