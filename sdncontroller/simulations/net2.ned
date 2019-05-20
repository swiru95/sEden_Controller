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

package sdncontroller.simulations;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.Router;

import inet.node.ethernet.Eth100M;
import inet.node.inet.StandardHost;


//
// Generated network with random topology (5 nodes, 10 edges, seed=100).
//
network Network
{
    @display("bgb=592,348");
    submodules:
        router5: Router {
            @display("p=228,165");
        }
        router2: Router {
            @display("p=90,45");
        }
        router1: Router {
            @display("p=228,45");
        }
        router4: Router {
            @display("p=90,165");
        }
        router3: Router {
            @display("p=158,106");
        }
        controller: StandardHost {
            @display("p=507,33");
        }
        switch2extInt: EtherSwitch {
            @display("p=420,267");
        }
    connections:
        router5.ethg++ <--> Eth100M <--> router1.ethg++;
        router5.ethg++ <--> Eth100M <--> router4.ethg++;
        router5.ethg++ <--> Eth100M <--> router3.ethg++;
        router2.ethg++ <--> Eth100M <--> router1.ethg++;
        router2.ethg++ <--> Eth100M <--> router4.ethg++;
        router2.ethg++ <--> Eth100M <--> router3.ethg++;
        router1.ethg++ <--> Eth100M <--> router3.ethg++;
        router4.ethg++ <--> Eth100M <--> router3.ethg++;
        controller.ethg[0] <--> Eth100M <--> router1.ethg[0];
        router5.ethg[0] <--> Eth100M <--> switch2extInt.ethg++;
}
