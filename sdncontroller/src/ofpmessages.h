/*
 * ofpmessages.h
 *
 *  Created on: Mar 6, 2019
 *      Author: root
 */

#ifndef OFPMESSAGES_H_
#define OFPMESSAGES_H_

#include"openflowmessages/ofp_actions_m.h"
#include"openflowmessages/ofp_error_m.h"
#include"openflowmessages/ofp_feature_m.h"
#include"openflowmessages/ofp_flow_mod_m.h"
#include"openflowmessages/ofp_header_m.h"
#include"openflowmessages/ofp_match_m.h"
#include"openflowmessages/ofp_packet_in_m.h"
#include"openflowmessages/ofp_phy_port_m.h"
#include"openflowmessages/ofp_set_config_m.h"
#include"openflowmessages/ofp_vendor_m.h"

//Networking and OF field sizes
enum header_sizes { //IN BYTES
    //NETWORK
    MAC_HEADER_SIZE = 14,
    IPv4_HEADER_SIZE = 20,
    ARP_SIZE=28,
    TCP_HEADER_SIZE = 20,
    UDP_HEADER_SIZE = 8,
    //OPENFLOW
    OFP_HEADER_SIZE = 8,
    OFP_VENDOR_SIZE = 4,
    OFP_SET_CONFIG_SIZE = 4,
    OFP_PHY_PORT_SIZE = 48,
    OFP_PORT_MODE_SIZE=24,
    OFP_PACKET_IN_SIZE = 12,
    OFP_PACKET_OUT_SIZE = 8,
    OFP_MATCH_SIZE = 40,
    OFP_FLOW_MOD_SIZE = 24,
    OFP_FEATURE_SIZE = 24,
    OFP_ERROR_SIZE = 4,
    OFP_ACTIONS_HEAD_SIZE = 4,
    OFP_OUTPUT_ACTION_SIZE = 4,
    OFP_ENQUEUE_ACTION_SIZE = 6,
    OFP_SETVLANVID_ACTION_SIZE = 4,
    OFP_SETNWADDR_ACTION_SIZE = 4,
    OFP_VENDOR_ACTION_SIZE = 4,
    OFP_VLANPCP_ACTION_SIZE = 4,
    OFP_SETNWTOS_ACTION_SIZE = 4,
    OFP_SETDLADDR_ACTION_SIZE = 4,
    OFP_SETTCPORT_ACTION_SIZE = 4
};

#endif /* OFPMESSAGES_H_ */
