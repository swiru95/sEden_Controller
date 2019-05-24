//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_phy_port.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "ofp_phy_port_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::phy_port_id");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::phy_port_id"));
    e->insert(MAX, "MAX");
    e->insert(IN_PORT, "IN_PORT");
    e->insert(TABLE, "TABLE");
    e->insert(NORMAL, "NORMAL");
    e->insert(FLOOD, "FLOOD");
    e->insert(ALL, "ALL");
    e->insert(CONTROLLER, "CONTROLLER");
    e->insert(LOCAL, "LOCAL");
    e->insert(NONE, "NONE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::phy_port_config");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::phy_port_config"));
    e->insert(PORT_DOWN, "PORT_DOWN");
    e->insert(NO_STP, "NO_STP");
    e->insert(NO_RECV, "NO_RECV");
    e->insert(NO_RECV_STP, "NO_RECV_STP");
    e->insert(NO_FLOOD, "NO_FLOOD");
    e->insert(NO_FWD, "NO_FWD");
    e->insert(NO_PACKET_IN, "NO_PACKET_IN");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::phy_port_state");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::phy_port_state"));
    e->insert(STP_LSITEN, "STP_LSITEN");
    e->insert(LINK_DOWN, "LINK_DOWN");
    e->insert(STP_LEARN, "STP_LEARN");
    e->insert(STP_FORWARD, "STP_FORWARD");
    e->insert(STP_BLOCK, "STP_BLOCK");
    e->insert(STP_MASK, "STP_MASK");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::phy_port_feature");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::phy_port_feature"));
    e->insert(TEN_MB_HD, "TEN_MB_HD");
    e->insert(TEN_MB_FD, "TEN_MB_FD");
    e->insert(HUN_MB_HD, "HUN_MB_HD");
    e->insert(HUN_MB_FD, "HUN_MB_FD");
    e->insert(GB_HD, "GB_HD");
    e->insert(GB_FD, "GB_FD");
    e->insert(TEN_GB_FD, "TEN_GB_FD");
    e->insert(COOPER, "COOPER");
    e->insert(FIBER, "FIBER");
    e->insert(AUTONEG, "AUTONEG");
    e->insert(PAUSE, "PAUSE");
    e->insert(PAUSE_ASYM, "PAUSE_ASYM");
)

Register_Class(Ofp_phy_port)

Ofp_phy_port::Ofp_phy_port() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(48));

}

Ofp_phy_port::Ofp_phy_port(const Ofp_phy_port& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_phy_port::~Ofp_phy_port()
{
}

Ofp_phy_port& Ofp_phy_port::operator=(const Ofp_phy_port& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_phy_port::copy(const Ofp_phy_port& other)
{
    this->port_no = other.port_no;
    this->hw_addr = other.hw_addr;
    for (size_t i = 0; i < 16; i++) {
        this->name[i] = other.name[i];
    }
    this->config = other.config;
    this->state = other.state;
    this->curr = other.curr;
    this->advertised = other.advertised;
    this->supported = other.supported;
    this->peer = other.peer;
}

void Ofp_phy_port::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->port_no);
    doParsimPacking(b,this->hw_addr);
    doParsimArrayPacking(b,this->name,16);
    doParsimPacking(b,this->config);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->curr);
    doParsimPacking(b,this->advertised);
    doParsimPacking(b,this->supported);
    doParsimPacking(b,this->peer);
}

void Ofp_phy_port::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->port_no);
    doParsimUnpacking(b,this->hw_addr);
    doParsimArrayUnpacking(b,this->name,16);
    doParsimUnpacking(b,this->config);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->curr);
    doParsimUnpacking(b,this->advertised);
    doParsimUnpacking(b,this->supported);
    doParsimUnpacking(b,this->peer);
}

uint16_t Ofp_phy_port::getPort_no() const
{
    return this->port_no;
}

void Ofp_phy_port::setPort_no(uint16_t port_no)
{
    handleChange();
    this->port_no = port_no;
}

const MacAddress& Ofp_phy_port::getHw_addr() const
{
    return this->hw_addr;
}

void Ofp_phy_port::setHw_addr(const MacAddress& hw_addr)
{
    handleChange();
    this->hw_addr = hw_addr;
}

size_t Ofp_phy_port::getNameArraySize() const
{
    return 16;
}

char Ofp_phy_port::getName(size_t k) const
{
    if (k >= 16) throw omnetpp::cRuntimeError("Array of size 16 indexed by %lu", (unsigned long)k);
    return this->name[k];
}

void Ofp_phy_port::setName(size_t k, char name)
{
    if (k >= 16) throw omnetpp::cRuntimeError("Array of size 16 indexed by %lu", (unsigned long)k);
    handleChange();
    this->name[k] = name;
}

uint32_t Ofp_phy_port::getConfig() const
{
    return this->config;
}

void Ofp_phy_port::setConfig(uint32_t config)
{
    handleChange();
    this->config = config;
}

uint32_t Ofp_phy_port::getState() const
{
    return this->state;
}

void Ofp_phy_port::setState(uint32_t state)
{
    handleChange();
    this->state = state;
}

uint32_t Ofp_phy_port::getCurr() const
{
    return this->curr;
}

void Ofp_phy_port::setCurr(uint32_t curr)
{
    handleChange();
    this->curr = curr;
}

uint32_t Ofp_phy_port::getAdvertised() const
{
    return this->advertised;
}

void Ofp_phy_port::setAdvertised(uint32_t advertised)
{
    handleChange();
    this->advertised = advertised;
}

uint32_t Ofp_phy_port::getSupported() const
{
    return this->supported;
}

void Ofp_phy_port::setSupported(uint32_t supported)
{
    handleChange();
    this->supported = supported;
}

uint32_t Ofp_phy_port::getPeer() const
{
    return this->peer;
}

void Ofp_phy_port::setPeer(uint32_t peer)
{
    handleChange();
    this->peer = peer;
}

class Ofp_phy_portDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_port_no,
        FIELD_hw_addr,
        FIELD_name,
        FIELD_config,
        FIELD_state,
        FIELD_curr,
        FIELD_advertised,
        FIELD_supported,
        FIELD_peer,
    };
  public:
    Ofp_phy_portDescriptor();
    virtual ~Ofp_phy_portDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ofp_phy_portDescriptor)

Ofp_phy_portDescriptor::Ofp_phy_portDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_phy_port)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_phy_portDescriptor::~Ofp_phy_portDescriptor()
{
    delete[] propertynames;
}

bool Ofp_phy_portDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_phy_port *>(obj)!=nullptr;
}

const char **Ofp_phy_portDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_phy_portDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_phy_portDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ofp_phy_portDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_port_no
        0,    // FIELD_hw_addr
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_name
        FD_ISEDITABLE,    // FIELD_config
        FD_ISEDITABLE,    // FIELD_state
        FD_ISEDITABLE,    // FIELD_curr
        FD_ISEDITABLE,    // FIELD_advertised
        FD_ISEDITABLE,    // FIELD_supported
        FD_ISEDITABLE,    // FIELD_peer
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_phy_portDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "port_no",
        "hw_addr",
        "name",
        "config",
        "state",
        "curr",
        "advertised",
        "supported",
        "peer",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int Ofp_phy_portDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port_no") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hw_addr") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "name") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "config") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "state") == 0) return base+4;
    if (fieldName[0] == 'c' && strcmp(fieldName, "curr") == 0) return base+5;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertised") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "supported") == 0) return base+7;
    if (fieldName[0] == 'p' && strcmp(fieldName, "peer") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_phy_portDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_port_no
        "inet::MacAddress",    // FIELD_hw_addr
        "char",    // FIELD_name
        "uint32_t",    // FIELD_config
        "uint32_t",    // FIELD_state
        "uint32_t",    // FIELD_curr
        "uint32_t",    // FIELD_advertised
        "uint32_t",    // FIELD_supported
        "uint32_t",    // FIELD_peer
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_phy_portDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ofp_phy_portDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ofp_phy_portDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_phy_port *pp = (Ofp_phy_port *)object; (void)pp;
    switch (field) {
        case FIELD_name: return 16;
        default: return 0;
    }
}

const char *Ofp_phy_portDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_phy_port *pp = (Ofp_phy_port *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_phy_portDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_phy_port *pp = (Ofp_phy_port *)object; (void)pp;
    switch (field) {
        case FIELD_port_no: return ulong2string(pp->getPort_no());
        case FIELD_hw_addr: return pp->getHw_addr().str();
        case FIELD_name: return long2string(pp->getName(i));
        case FIELD_config: return ulong2string(pp->getConfig());
        case FIELD_state: return ulong2string(pp->getState());
        case FIELD_curr: return ulong2string(pp->getCurr());
        case FIELD_advertised: return ulong2string(pp->getAdvertised());
        case FIELD_supported: return ulong2string(pp->getSupported());
        case FIELD_peer: return ulong2string(pp->getPeer());
        default: return "";
    }
}

bool Ofp_phy_portDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_phy_port *pp = (Ofp_phy_port *)object; (void)pp;
    switch (field) {
        case FIELD_port_no: pp->setPort_no(string2ulong(value)); return true;
        case FIELD_name: pp->setName(i,string2long(value)); return true;
        case FIELD_config: pp->setConfig(string2ulong(value)); return true;
        case FIELD_state: pp->setState(string2ulong(value)); return true;
        case FIELD_curr: pp->setCurr(string2ulong(value)); return true;
        case FIELD_advertised: pp->setAdvertised(string2ulong(value)); return true;
        case FIELD_supported: pp->setSupported(string2ulong(value)); return true;
        case FIELD_peer: pp->setPeer(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_phy_portDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ofp_phy_portDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_phy_port *pp = (Ofp_phy_port *)object; (void)pp;
    switch (field) {
        case FIELD_hw_addr: return toVoidPtr(&pp->getHw_addr()); break;
        default: return nullptr;
    }
}

Register_Class(Ofp_port_mode)

Ofp_port_mode::Ofp_port_mode() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(24));

}

Ofp_port_mode::Ofp_port_mode(const Ofp_port_mode& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_port_mode::~Ofp_port_mode()
{
}

Ofp_port_mode& Ofp_port_mode::operator=(const Ofp_port_mode& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_port_mode::copy(const Ofp_port_mode& other)
{
    this->port_no = other.port_no;
    this->hw_addr = other.hw_addr;
    this->config = other.config;
    this->mask = other.mask;
    this->advertise = other.advertise;
    this->pad = other.pad;
}

void Ofp_port_mode::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->port_no);
    doParsimPacking(b,this->hw_addr);
    doParsimPacking(b,this->config);
    doParsimPacking(b,this->mask);
    doParsimPacking(b,this->advertise);
    doParsimPacking(b,this->pad);
}

void Ofp_port_mode::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->port_no);
    doParsimUnpacking(b,this->hw_addr);
    doParsimUnpacking(b,this->config);
    doParsimUnpacking(b,this->mask);
    doParsimUnpacking(b,this->advertise);
    doParsimUnpacking(b,this->pad);
}

uint16_t Ofp_port_mode::getPort_no() const
{
    return this->port_no;
}

void Ofp_port_mode::setPort_no(uint16_t port_no)
{
    handleChange();
    this->port_no = port_no;
}

const MacAddress& Ofp_port_mode::getHw_addr() const
{
    return this->hw_addr;
}

void Ofp_port_mode::setHw_addr(const MacAddress& hw_addr)
{
    handleChange();
    this->hw_addr = hw_addr;
}

uint32_t Ofp_port_mode::getConfig() const
{
    return this->config;
}

void Ofp_port_mode::setConfig(uint32_t config)
{
    handleChange();
    this->config = config;
}

uint32_t Ofp_port_mode::getMask() const
{
    return this->mask;
}

void Ofp_port_mode::setMask(uint32_t mask)
{
    handleChange();
    this->mask = mask;
}

uint32_t Ofp_port_mode::getAdvertise() const
{
    return this->advertise;
}

void Ofp_port_mode::setAdvertise(uint32_t advertise)
{
    handleChange();
    this->advertise = advertise;
}

uint64_t Ofp_port_mode::getPad() const
{
    return this->pad;
}

void Ofp_port_mode::setPad(uint64_t pad)
{
    handleChange();
    this->pad = pad;
}

class Ofp_port_modeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_port_no,
        FIELD_hw_addr,
        FIELD_config,
        FIELD_mask,
        FIELD_advertise,
        FIELD_pad,
    };
  public:
    Ofp_port_modeDescriptor();
    virtual ~Ofp_port_modeDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Ofp_port_modeDescriptor)

Ofp_port_modeDescriptor::Ofp_port_modeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_port_mode)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_port_modeDescriptor::~Ofp_port_modeDescriptor()
{
    delete[] propertynames;
}

bool Ofp_port_modeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_port_mode *>(obj)!=nullptr;
}

const char **Ofp_port_modeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_port_modeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_port_modeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ofp_port_modeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_port_no
        0,    // FIELD_hw_addr
        FD_ISEDITABLE,    // FIELD_config
        FD_ISEDITABLE,    // FIELD_mask
        FD_ISEDITABLE,    // FIELD_advertise
        FD_ISEDITABLE,    // FIELD_pad
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_port_modeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "port_no",
        "hw_addr",
        "config",
        "mask",
        "advertise",
        "pad",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ofp_port_modeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port_no") == 0) return base+0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hw_addr") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "config") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mask") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "advertise") == 0) return base+4;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_port_modeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_port_no
        "inet::MacAddress",    // FIELD_hw_addr
        "uint32_t",    // FIELD_config
        "uint32_t",    // FIELD_mask
        "uint32_t",    // FIELD_advertise
        "uint64_t",    // FIELD_pad
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_port_modeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Ofp_port_modeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Ofp_port_modeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_port_mode *pp = (Ofp_port_mode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_port_modeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_port_mode *pp = (Ofp_port_mode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_port_modeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_port_mode *pp = (Ofp_port_mode *)object; (void)pp;
    switch (field) {
        case FIELD_port_no: return ulong2string(pp->getPort_no());
        case FIELD_hw_addr: return pp->getHw_addr().str();
        case FIELD_config: return ulong2string(pp->getConfig());
        case FIELD_mask: return ulong2string(pp->getMask());
        case FIELD_advertise: return ulong2string(pp->getAdvertise());
        case FIELD_pad: return uint642string(pp->getPad());
        default: return "";
    }
}

bool Ofp_port_modeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_port_mode *pp = (Ofp_port_mode *)object; (void)pp;
    switch (field) {
        case FIELD_port_no: pp->setPort_no(string2ulong(value)); return true;
        case FIELD_config: pp->setConfig(string2ulong(value)); return true;
        case FIELD_mask: pp->setMask(string2ulong(value)); return true;
        case FIELD_advertise: pp->setAdvertise(string2ulong(value)); return true;
        case FIELD_pad: pp->setPad(string2uint64(value)); return true;
        default: return false;
    }
}

const char *Ofp_port_modeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Ofp_port_modeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_port_mode *pp = (Ofp_port_mode *)object; (void)pp;
    switch (field) {
        case FIELD_hw_addr: return toVoidPtr(&pp->getHw_addr()); break;
        default: return nullptr;
    }
}

} // namespace inet

