//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_header.msg.
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
#include "ofp_header_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ofp_version");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ofp_version"));
    e->insert(OFPV_v100, "OFPV_v100");
    e->insert(OFPV_v110, "OFPV_v110");
    e->insert(OFPV_v120, "OFPV_v120");
    e->insert(OFPV_v130, "OFPV_v130");
    e->insert(OFPV_v140, "OFPV_v140");
    e->insert(OFPV_v150, "OFPV_v150");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ofp_type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ofp_type"));
    e->insert(OFPT_HELLO, "OFPT_HELLO");
    e->insert(OFPT_ERROR, "OFPT_ERROR");
    e->insert(OFPT_ECHO_REQUEST, "OFPT_ECHO_REQUEST");
    e->insert(OFPT_ECHO_REPLY, "OFPT_ECHO_REPLY");
    e->insert(OFPT_VENDOR, "OFPT_VENDOR");
    e->insert(OFPT_FEATURES_REQUEST, "OFPT_FEATURES_REQUEST");
    e->insert(OFPT_FEATURES_REPLY, "OFPT_FEATURES_REPLY");
    e->insert(OFPT_GET_CONFIG_REQUEST, "OFPT_GET_CONFIG_REQUEST");
    e->insert(OFPT_GET_CONFIG_REPLY, "OFPT_GET_CONFIG_REPLY");
    e->insert(OFPT_SET_CONFIG, "OFPT_SET_CONFIG");
    e->insert(OFPT_PACKET_IN, "OFPT_PACKET_IN");
    e->insert(OFPT_FLOW_REMOVED, "OFPT_FLOW_REMOVED");
    e->insert(OFPT_PORT_STATUS, "OFPT_PORT_STATUS");
    e->insert(OFPT_PACKET_OUT, "OFPT_PACKET_OUT");
    e->insert(OFPT_FLOW_MOD, "OFPT_FLOW_MOD");
    e->insert(OFPT_PORT_MOD, "OFPT_PORT_MOD");
    e->insert(OFPT_STATS_REQUEST, "OFPT_STATS_REQUEST");
    e->insert(OFPT_STATS_REPLY, "OFPT_STATS_REPLY");
    e->insert(OFPT_BARRIER_REQUEST, "OFPT_BARRIER_REQUEST");
    e->insert(OFPT_BARRIER_REPLY, "OFPT_BARRIER_REPLY");
    e->insert(OFPT_QUEUE_GET_CONFIG_REQUEST, "OFPT_QUEUE_GET_CONFIG_REQUEST");
    e->insert(OFPT_QUEUE_GET_CONFIG_REPLY, "OFPT_QUEUE_GET_CONFIG_REPLY");
)

Register_Class(Ofp_header)

Ofp_header::Ofp_header() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(8));

}

Ofp_header::Ofp_header(const Ofp_header& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_header::~Ofp_header()
{
}

Ofp_header& Ofp_header::operator=(const Ofp_header& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_header::copy(const Ofp_header& other)
{
    this->version = other.version;
    this->type = other.type;
    this->length = other.length;
    this->xid = other.xid;
}

void Ofp_header::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->xid);
}

void Ofp_header::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->xid);
}

uint8_t Ofp_header::getVersion() const
{
    return this->version;
}

void Ofp_header::setVersion(uint8_t version)
{
    handleChange();
    this->version = version;
}

uint8_t Ofp_header::getType() const
{
    return this->type;
}

void Ofp_header::setType(uint8_t type)
{
    handleChange();
    this->type = type;
}

uint16_t Ofp_header::getLength() const
{
    return this->length;
}

void Ofp_header::setLength(uint16_t length)
{
    handleChange();
    this->length = length;
}

uint32_t Ofp_header::getXid() const
{
    return this->xid;
}

void Ofp_header::setXid(uint32_t xid)
{
    handleChange();
    this->xid = xid;
}

class Ofp_headerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_version,
        FIELD_type,
        FIELD_length,
        FIELD_xid,
    };
  public:
    Ofp_headerDescriptor();
    virtual ~Ofp_headerDescriptor();

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

Register_ClassDescriptor(Ofp_headerDescriptor)

Ofp_headerDescriptor::Ofp_headerDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_header)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_headerDescriptor::~Ofp_headerDescriptor()
{
    delete[] propertynames;
}

bool Ofp_headerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_header *>(obj)!=nullptr;
}

const char **Ofp_headerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_headerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_headerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ofp_headerDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_xid
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_headerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "type",
        "length",
        "xid",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ofp_headerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "version") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+1;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+2;
    if (fieldName[0] == 'x' && strcmp(fieldName, "xid") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_headerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_version
        "uint8_t",    // FIELD_type
        "uint16_t",    // FIELD_length
        "uint32_t",    // FIELD_xid
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_headerDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_headerDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_headerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_header *pp = (Ofp_header *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_headerDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_header *pp = (Ofp_header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_headerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_header *pp = (Ofp_header *)object; (void)pp;
    switch (field) {
        case FIELD_version: return ulong2string(pp->getVersion());
        case FIELD_type: return ulong2string(pp->getType());
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_xid: return ulong2string(pp->getXid());
        default: return "";
    }
}

bool Ofp_headerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_header *pp = (Ofp_header *)object; (void)pp;
    switch (field) {
        case FIELD_version: pp->setVersion(string2ulong(value)); return true;
        case FIELD_type: pp->setType(string2ulong(value)); return true;
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        case FIELD_xid: pp->setXid(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_headerDescriptor::getFieldStructName(int field) const
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

void *Ofp_headerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_header *pp = (Ofp_header *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet
