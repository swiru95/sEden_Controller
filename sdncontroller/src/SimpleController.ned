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

package sdncontroller;
import inet.applications.contract.IApp;
//
// ~SimpleController is heritaged from IApp
// Module works like SDN controller which supports OFPv100 protocol.
// You can edit, add your own applications
// Applications already done:
//    App1,App2,App3,App4
// (Descryption of apps are in api.cc)
//
simple SimpleController like IApp
{
    parameters:
        //Controller socket parameters
        string localAddress = default(""); // local address; may be left empty ("")
        int localPort = default(6633);     // localPort number to listen on
        //Some openflow and controllerStateFlow params
        double echoInterval @unit(ms)=default(100ms);//EchoMessage interval (not too much!)
        double echoCancelInterval @unit(ms)=default(500ms);//waiting for EchoReqMsg interval
        double helloWaitInterval @unit(ms)=default(1000ms);//waiting for Hello in HelloWaitingState
		double featuresWaitInterval @unit(ms)=default(500ms);//waiting for Features in FeatureWaitState        
        int time_idle=default(5); //Idle time for ofp matches
        int time_hard=default(0); //Hard time for ofp matches
        bool log2file=default(false); //Logging errors to file   
        							  //File is placed in simulations/logs .log ext.  
		//You can run Wireshark to capture some packets and monitor the flows        
        bool runWireshark=default(false); //running Wireshark
        bool anyWiresharkCaptureInterface=default(true); //set wireshark capturing interface filter to "any"
        string wiresharkCaptureInterface="local"; //which interface is going to be listened (local=**.ext[0].*.device)
        //You can run Mininet from Omnet
        bool runMininet=default(true); //running Mininet
        string mntopo=default(""); // you can specify your own topology in *.py files in simulations/mnnets 
        						   //and there you can just write name of file without py extention
        string application=default(""); //name of application
        //For app1,2,4 xml is used
        volatile xml flows=default(xmldoc("")); //xml flow for app1
        //There is an App3 where Database is used you can specify parameters to connect.
        string dbIpAddr=default("localhost");//IP address of DB
        string dbPort=default("6603"); //DB port
        string dbName=default(""); //name of DB
        string dbUser=default(""); //Name of DB user
        string dbPassword=default(""); //DB password (optional)
        //TO be done: logging errors not to file but to DB table! WoW
        string dbErrorName=default(""); //Database of Errors //not done yet
        //statistics
    	@signal[StateS](type=long);
    	@signal[pkS](type=cPacket?);
        @statistic[StateT](source=StateS; record=vector);
        @statistic[packSize](source=packetBytes(pkS); record=sum,vector);
        
    gates:
        input socketIn @labels(TcpCommand/up);
        output socketOut @labels(TcpCommand/down);
}
