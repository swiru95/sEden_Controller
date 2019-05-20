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

enum Ofp_er_type{
 	HELLO_FAILED=0X0000;
 	BAD_REQUEST=0X0001;
 	BAD_ACTION=0X0002;
 	FLOW_MOD_FAILED=0X0003;     
 	PORT_MOD_FAILED=0X0004;
 	QUEUE_OP_FAILED=0X0005;
};
enum Of_hf_er_code{
    //HF
    HF_INCOMPATIBLE=0X0000;
    HF_EPERM=0X0001;
};
enum Of_br_er_code{
    //BR
    BR_BAD_VERSION=0X0000;
    BR_BAD_TYPE=0X0001;
    BR_BAD_STAT=0X0002;
    BR_BAD_VENDOR=0X0003;
    BR_BAD_SUBTYPE=0X0004;
    BR_EPERM=0X0005;
    BR_BAD_LENGTH=0X0006;
    BR_BUFFER_EMPTY=0X0007;
    BR_BUFFER_UKNOWN=0X0008;
};
enum Of_ba_er_code{
	//BA
	BA_BAD_TYPE=0X0000;
	BA_BAD_LENGTH=0X0001;
	BA_BAD_VENDOR=0X0002;
	BA_BAD_VENDOR_TYPE=0X0003;
	BA_BAD_OUT_PORT=0X0004;
	BA_BAD_ARGUMENTS=0X0005;
	BA_EPERM=0X0006;
	BA_TOO_MANY=0X0007;
	BA_BAD_QUEUE=0X0008;
};
enum Of_ofmf_er_code{	
	//OFMF
	FMF_ALL_TABLES_FULL=0x0000;  
	FMF_OVERLAP=0x0001;
	FMF_EPERM=0x0002;
	FMF_BAD_EMERG_TIMEOUT=0x0003;
	FMF_BAD_COMMAND=0x0004;
	FMF_UNSUPPORTED=0x0005;
};
enum Of_opmf_er_code {
    //OPMF
    PMF_BAD_PORT=0x0001;
    PMF_BAD_HW_ADDR=0x0002;
};
enum Of_oqof_er_code {
	//OQOF
	QOF_BAD_PORT=0x0000;          
	QOF_BAD_QUEUE=0x0001;
    QOF_EPERM=0x0002;  
};

class Ofp_error extends FieldsChunk {

	uint16_t type;
	uint16_t code;

	chunkLength=B(4);
}
