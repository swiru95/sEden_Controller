//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_header.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_OFP_HEADER_M_H
#define __INET_OFP_HEADER_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace inet {

class Ofp_header;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk


namespace inet {

/**
 * Enum generated from <tt>openflowmessages/ofp_header.msg:25</tt> by nedtool.
 * <pre>
 * enum Ofp_version
 * {
 *     OFPV_v100 = 0x01; //ok
 *     OFPV_v110 = 0x02;
 *     OFPV_v120 = 0x03;
 *     OFPV_v130 = 0x04;
 *     OFPV_v140 = 0x05;
 *     OFPV_v150 = 0x06;
 * }
 * </pre>
 */
enum Ofp_version {
    OFPV_v100 = 0x01,
    OFPV_v110 = 0x02,
    OFPV_v120 = 0x03,
    OFPV_v130 = 0x04,
    OFPV_v140 = 0x05,
    OFPV_v150 = 0x06
};

/**
 * Enum generated from <tt>openflowmessages/ofp_header.msg:33</tt> by nedtool.
 * <pre>
 * enum Ofp_type
 * {
 *     // Immutable messages.
 *     OFPT_HELLO = 0x00; // Symmetric message    ok
 *     OFPT_ERROR = 0x01; // Symmetric message    ok
 *     OFPT_ECHO_REQUEST = 0x02; // Symmetric message    ok
 *     OFPT_ECHO_REPLY = 0x03; // Symmetric message    ok
 *     OFPT_VENDOR = 0x04; // Symmetric message    ok
 * 
 *     // Switch configuration messages.   
 *     OFPT_FEATURES_REQUEST = 0x05; // Controller/switch message    ok
 *     OFPT_FEATURES_REPLY = 0x06; // Controller/switch message    ok
 *     OFPT_GET_CONFIG_REQUEST = 0x07; // Controller/switch message    ok
 *     OFPT_GET_CONFIG_REPLY = 0x08; // Controller/switch message    ok
 *     OFPT_SET_CONFIG = 0x09; // Controller/switch message    ok
 * 
 *     // Asynchronous messages.   
 *     OFPT_PACKET_IN = 0x0A; // Async message   
 *     OFPT_FLOW_REMOVED = 0x0B; // Async message   
 *     OFPT_PORT_STATUS = 0x0C; // Async message   
 * 
 *     // Controller command messages.   
 *     OFPT_PACKET_OUT = 0x0D; // Controller/switch message   
 *     OFPT_FLOW_MOD = 0x0E; // Controller/switch message   
 *     OFPT_PORT_MOD = 0x0F; // Controller/switch message   
 * 
 *     // Statistics messages.   
 *     OFPT_STATS_REQUEST = 0x11; // Controller/switch message   
 *     OFPT_STATS_REPLY = 0x12; // Controller/switch message   
 * 
 *     // Barrier messages.   
 *     OFPT_BARRIER_REQUEST = 0x13; // Controller/switch message    ok
 *     OFPT_BARRIER_REPLY = 0x14; // Controller/switch message    ok
 * 
 *     // Queue Configuration messages.   
 *     OFPT_QUEUE_GET_CONFIG_REQUEST = 0x15; // Controller/switch message   
 *     OFPT_QUEUE_GET_CONFIG_REPLY = 0x16;
 * 
 * }
 * </pre>
 */
enum Ofp_type {
    OFPT_HELLO = 0x00,
    OFPT_ERROR = 0x01,
    OFPT_ECHO_REQUEST = 0x02,
    OFPT_ECHO_REPLY = 0x03,
    OFPT_VENDOR = 0x04,
    OFPT_FEATURES_REQUEST = 0x05,
    OFPT_FEATURES_REPLY = 0x06,
    OFPT_GET_CONFIG_REQUEST = 0x07,
    OFPT_GET_CONFIG_REPLY = 0x08,
    OFPT_SET_CONFIG = 0x09,
    OFPT_PACKET_IN = 0x0A,
    OFPT_FLOW_REMOVED = 0x0B,
    OFPT_PORT_STATUS = 0x0C,
    OFPT_PACKET_OUT = 0x0D,
    OFPT_FLOW_MOD = 0x0E,
    OFPT_PORT_MOD = 0x0F,
    OFPT_STATS_REQUEST = 0x11,
    OFPT_STATS_REPLY = 0x12,
    OFPT_BARRIER_REQUEST = 0x13,
    OFPT_BARRIER_REPLY = 0x14,
    OFPT_QUEUE_GET_CONFIG_REQUEST = 0x15,
    OFPT_QUEUE_GET_CONFIG_REPLY = 0x16
};

/**
 * Class generated from <tt>openflowmessages/ofp_header.msg:74</tt> by nedtool.
 * <pre>
 * class Ofp_header extends FieldsChunk
 * {
 *     uint8_t version;
 *     uint8_t type;
 *     uint16_t length;
 *     uint32_t xid;
 *     chunkLength = B(8);
 * 
 * }
 * </pre>
 */
class Ofp_header : public ::inet::FieldsChunk
{
  protected:
    uint8_t version = 0;
    uint8_t type = 0;
    uint16_t length = 0;
    uint32_t xid = 0;

  private:
    void copy(const Ofp_header& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Ofp_header&);

  public:
    Ofp_header();
    Ofp_header(const Ofp_header& other);
    virtual ~Ofp_header();
    Ofp_header& operator=(const Ofp_header& other);
    virtual Ofp_header *dup() const override {return new Ofp_header(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint8_t getVersion() const;
    virtual void setVersion(uint8_t version);
    virtual uint8_t getType() const;
    virtual void setType(uint8_t type);
    virtual uint16_t getLength() const;
    virtual void setLength(uint16_t length);
    virtual uint32_t getXid() const;
    virtual void setXid(uint32_t xid);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ofp_header& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ofp_header& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_OFP_HEADER_M_H
