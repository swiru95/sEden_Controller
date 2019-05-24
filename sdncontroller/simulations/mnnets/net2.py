"""Topo
Three directly connected host for one switch:

             host
  	      |

 host ---  switch --- host

Adding the 'topos' dict with a key/value pair to generate our newly defined
topology enables one to pass in '--topo=mytopo' from the command line.
"""

from mininet.topo import Topo

class MyTopo( Topo ):
    "Simple topology example."

    def __init__( self ):
        "Create custom topo."

        # Initialize topology
        Topo.__init__( self )

        # Add hosts and switches
        leftHost = self.addHost( 'h1',mac="aa:aa:aa:aa:aa:a1",ip="1.0.0.1/24")
        rightHost = self.addHost( 'h2',mac="aa:aa:aa:aa:aa:a2",ip="1.0.0.2/24")
	badHost = self.addHost( 'h3',mac="aa:aa:aa:aa:aa:a3",ip="1.0.0.3/24")
       	switch = self.addSwitch( 's1')

        # Add links
        self.addLink( leftHost, switch )
        self.addLink( switch, rightHost )
	self.addLink( switch, badHost )




topos = { 'mytopo': ( lambda: MyTopo() ) }

