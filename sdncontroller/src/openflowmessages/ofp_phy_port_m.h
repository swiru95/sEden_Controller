//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_phy_port.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_OFP_PHY_PORT_M_H
#define __INET_OFP_PHY_PORT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace inet {

class Ofp_phy_port;
class Ofp_port_mode;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Enum generated from <tt>openflowmessages/ofp_phy_port.msg:21</tt> by nedtool.
 * <pre>
 * enum phy_port_id
 * {
 *     MAX = 0xFF00;
 *     IN_PORT = 0xFFF8;
 *     TABLE = 0xFFF9;
 *     NORMAL = 0xFFFA;
 *     FLOOD = 0xFFFB;
 *     ALL = 0xFFFC;
 *     CONTROLLER = 0xFFFD;
 *     LOCAL = 0xFFFE;
 *     NONE = 0xFFFF;
 * }
 * </pre>
 */
enum phy_port_id {
    MAX = 0xFF00,
    IN_PORT = 0xFFF8,
    TABLE = 0xFFF9,
    NORMAL = 0xFFFA,
    FLOOD = 0xFFFB,
    ALL = 0xFFFC,
    CONTROLLER = 0xFFFD,
    LOCAL = 0xFFFE,
    NONE = 0xFFFF
};

/**
 * Enum generated from <tt>openflowmessages/ofp_phy_port.msg:32</tt> by nedtool.
 * <pre>
 * enum phy_port_config
 * {
 *     PORT_DOWN = 0x00000001;
 *     NO_STP = 0x00000002;
 *     NO_RECV = 0x00000004;
 *     NO_RECV_STP = 0x00000008;
 *     NO_FLOOD = 0x00000010;
 *     NO_FWD = 0x00000020;
 *     NO_PACKET_IN = 0x00000040;
 * }
 * </pre>
 */
enum phy_port_config {
    PORT_DOWN = 0x00000001,
    NO_STP = 0x00000002,
    NO_RECV = 0x00000004,
    NO_RECV_STP = 0x00000008,
    NO_FLOOD = 0x00000010,
    NO_FWD = 0x00000020,
    NO_PACKET_IN = 0x00000040
};

/**
 * Enum generated from <tt>openflowmessages/ofp_phy_port.msg:41</tt> by nedtool.
 * <pre>
 * enum phy_port_state
 * {
 *     STP_LSITEN = 0x00000000;
 *     LINK_DOWN = 0x00000001;
 *     STP_LEARN = 0x00000002;
 *     STP_FORWARD = 0x00000004;
 *     STP_BLOCK = 0x00000008;
 *     STP_MASK = 0x00000010;
 * }
 * </pre>
 */
enum phy_port_state {
    STP_LSITEN = 0x00000000,
    LINK_DOWN = 0x00000001,
    STP_LEARN = 0x00000002,
    STP_FORWARD = 0x00000004,
    STP_BLOCK = 0x00000008,
    STP_MASK = 0x00000010
};

/**
 * Enum generated from <tt>openflowmessages/ofp_phy_port.msg:49</tt> by nedtool.
 * <pre>
 * enum phy_port_feature
 * {
 *     TEN_MB_HD = 0x00000001;
 *     TEN_MB_FD = 0x00000002;
 *     HUN_MB_HD = 0x00000004;
 *     HUN_MB_FD = 0x00000008;
 *     GB_HD = 0x00000010;
 *     GB_FD = 0x00000020;
 *     TEN_GB_FD = 0x00000040;
 *     COOPER = 0x00000080;
 *     FIBER = 0x00000100;
 *     AUTONEG = 0x00000200;
 *     PAUSE = 0x00000400;
 *     PAUSE_ASYM = 0x00000800;
 * }
 * </pre>
 */
enum phy_port_feature {
    TEN_MB_HD = 0x00000001,
    TEN_MB_FD = 0x00000002,
    HUN_MB_HD = 0x00000004,
    HUN_MB_FD = 0x00000008,
    GB_HD = 0x00000010,
    GB_FD = 0x00000020,
    TEN_GB_FD = 0x00000040,
    COOPER = 0x00000080,
    FIBER = 0x00000100,
    AUTONEG = 0x00000200,
    PAUSE = 0x00000400,
    PAUSE_ASYM = 0x00000800
};

/**
 * Class generated from <tt>openflowmessages/ofp_phy_port.msg:63</tt> by nedtool.
 * <pre>
 * class Ofp_phy_port extends FieldsChunk
 * {
 *     uint16_t port_no;
 *     MacAddress hw_addr;
 *     char name[16];
 *     uint32_t config;
 *     uint32_t state;
 *     uint32_t curr;
 *     uint32_t advertised;
 *     uint32_t supported;
 *     uint32_t peer;
 *     chunkLength = B(48);
 * }
 * </pre>
 */
class Ofp_phy_port : public ::inet::FieldsChunk
{
  protected:
    uint16_t port_no = 0;
    MacAddress hw_addr;
    char name[16] = {0};
    uint32_t config = 0;
    uint32_t state = 0;
    uint32_t curr = 0;
    uint32_t advertised = 0;
    uint32_t supported = 0;
    uint32_t peer = 0;

  private:
    void copy(const Ofp_phy_port& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Ofp_phy_port&);

  public:
    Ofp_phy_port();
    Ofp_phy_port(const Ofp_phy_port& other);
    virtual ~Ofp_phy_port();
    Ofp_phy_port& operator=(const Ofp_phy_port& other);
    virtual Ofp_phy_port *dup() const override {return new Ofp_phy_port(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getPort_no() const;
    virtual void setPort_no(uint16_t port_no);
    virtual const MacAddress& getHw_addr() const;
    virtual MacAddress& getHw_addrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<Ofp_phy_port*>(this)->getHw_addr());}
    virtual void setHw_addr(const MacAddress& hw_addr);
    virtual size_t getNameArraySize() const;
    virtual char getName(size_t k) const;
    virtual void setName(size_t k, char name);
    virtual uint32_t getConfig() const;
    virtual void setConfig(uint32_t config);
    virtual uint32_t getState() const;
    virtual void setState(uint32_t state);
    virtual uint32_t getCurr() const;
    virtual void setCurr(uint32_t curr);
    virtual uint32_t getAdvertised() const;
    virtual void setAdvertised(uint32_t advertised);
    virtual uint32_t getSupported() const;
    virtual void setSupported(uint32_t supported);
    virtual uint32_t getPeer() const;
    virtual void setPeer(uint32_t peer);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ofp_phy_port& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ofp_phy_port& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>openflowmessages/ofp_phy_port.msg:75</tt> by nedtool.
 * <pre>
 * class Ofp_port_mode extends FieldsChunk
 * {
 *     uint16_t port_no;
 *     MacAddress hw_addr;
 *     uint32_t config;
 *     uint32_t mask;
 *     uint32_t advertise;
 *     uint64_t pad = 0;
 *     chunkLength = B(24);
 * }
 * </pre>
 */
class Ofp_port_mode : public ::inet::FieldsChunk
{
  protected:
    uint16_t port_no = 0;
    MacAddress hw_addr;
    uint32_t config = 0;
    uint32_t mask = 0;
    uint32_t advertise = 0;
    uint64_t pad = 0;

  private:
    void copy(const Ofp_port_mode& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Ofp_port_mode&);

  public:
    Ofp_port_mode();
    Ofp_port_mode(const Ofp_port_mode& other);
    virtual ~Ofp_port_mode();
    Ofp_port_mode& operator=(const Ofp_port_mode& other);
    virtual Ofp_port_mode *dup() const override {return new Ofp_port_mode(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint16_t getPort_no() const;
    virtual void setPort_no(uint16_t port_no);
    virtual const MacAddress& getHw_addr() const;
    virtual MacAddress& getHw_addrForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<Ofp_port_mode*>(this)->getHw_addr());}
    virtual void setHw_addr(const MacAddress& hw_addr);
    virtual uint32_t getConfig() const;
    virtual void setConfig(uint32_t config);
    virtual uint32_t getMask() const;
    virtual void setMask(uint32_t mask);
    virtual uint32_t getAdvertise() const;
    virtual void setAdvertise(uint32_t advertise);
    virtual uint64_t getPad() const;
    virtual void setPad(uint64_t pad);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ofp_port_mode& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ofp_port_mode& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_OFP_PHY_PORT_M_H

