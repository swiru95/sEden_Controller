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
enum kind{
    ECHO_INTERVAL_TIMER=0; 
  	ECHO_CANCEL_TIMER=1;
  	PORT_BLOCK_TIMER=2;
  	FEATURE_WAIT_TIMER=3;
	HELLO_WAIT_TIMER=4;  	
};
message timer{
 	uint8_t type;
 	int connId;
}