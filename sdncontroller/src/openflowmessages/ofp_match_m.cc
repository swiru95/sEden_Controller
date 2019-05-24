//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_match.msg.
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
#include "ofp_match_m.h"

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

Register_Class(Ofp_match)

Ofp_match::Ofp_match() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(40));

}

Ofp_match::Ofp_match(const Ofp_match& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_match::~Ofp_match()
{
}

Ofp_match& Ofp_match::operator=(const Ofp_match& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_match::copy(const Ofp_match& other)
{
    this->wildcards = other.wildcards;
    this->in_port = other.in_port;
    this->dl_src = other.dl_src;
    this->dl_dst = other.dl_dst;
    this->dl_vlan = other.dl_vlan;
    this->dl_vlan_pcp = other.dl_vlan_pcp;
    for (size_t i = 0; i < 1; i++) {
        this->pad1[i] = other.pad1[i];
    }
    this->dl_type = other.dl_type;
    this->nw_tos = other.nw_tos;
    this->nw_proto = other.nw_proto;
    for (size_t i = 0; i < 2; i++) {
        this->pad2[i] = other.pad2[i];
    }
    this->nw_src = other.nw_src;
    this->nw_dst = other.nw_dst;
    this->tp_src = other.tp_src;
    this->tp_dst = other.tp_dst;
}

void Ofp_match::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->wildcards);
    doParsimPacking(b,this->in_port);
    doParsimPacking(b,this->dl_src);
    doParsimPacking(b,this->dl_dst);
    doParsimPacking(b,this->dl_vlan);
    doParsimPacking(b,this->dl_vlan_pcp);
    doParsimArrayPacking(b,this->pad1,1);
    doParsimPacking(b,this->dl_type);
    doParsimPacking(b,this->nw_tos);
    doParsimPacking(b,this->nw_proto);
    doParsimArrayPacking(b,this->pad2,2);
    doParsimPacking(b,this->nw_src);
    doParsimPacking(b,this->nw_dst);
    doParsimPacking(b,this->tp_src);
    doParsimPacking(b,this->tp_dst);
}

void Ofp_match::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->wildcards);
    doParsimUnpacking(b,this->in_port);
    doParsimUnpacking(b,this->dl_src);
    doParsimUnpacking(b,this->dl_dst);
    doParsimUnpacking(b,this->dl_vlan);
    doParsimUnpacking(b,this->dl_vlan_pcp);
    doParsimArrayUnpacking(b,this->pad1,1);
    doParsimUnpacking(b,this->dl_type);
    doParsimUnpacking(b,this->nw_tos);
    doParsimUnpacking(b,this->nw_proto);
    doParsimArrayUnpacking(b,this->pad2,2);
    doParsimUnpacking(b,this->nw_src);
    doParsimUnpacking(b,this->nw_dst);
    doParsimUnpacking(b,this->tp_src);
    doParsimUnpacking(b,this->tp_dst);
}

uint32_t Ofp_match::getWildcards() const
{
    return this->wildcards;
}

void Ofp_match::setWildcards(uint32_t wildcards)
{
    handleChange();
    this->wildcards = wildcards;
}

uint16_t Ofp_match::getIn_port() const
{
    return this->in_port;
}

void Ofp_match::setIn_port(uint16_t in_port)
{
    handleChange();
    this->in_port = in_port;
}

const MacAddress& Ofp_match::getDl_src() const
{
    return this->dl_src;
}

void Ofp_match::setDl_src(const MacAddress& dl_src)
{
    handleChange();
    this->dl_src = dl_src;
}

const MacAddress& Ofp_match::getDl_dst() const
{
    return this->dl_dst;
}

void Ofp_match::setDl_dst(const MacAddress& dl_dst)
{
    handleChange();
    this->dl_dst = dl_dst;
}

uint16_t Ofp_match::getDl_vlan() const
{
    return this->dl_vlan;
}

void Ofp_match::setDl_vlan(uint16_t dl_vlan)
{
    handleChange();
    this->dl_vlan = dl_vlan;
}

uint8_t Ofp_match::getDl_vlan_pcp() const
{
    return this->dl_vlan_pcp;
}

void Ofp_match::setDl_vlan_pcp(uint8_t dl_vlan_pcp)
{
    handleChange();
    this->dl_vlan_pcp = dl_vlan_pcp;
}

size_t Ofp_match::getPad1ArraySize() const
{
    return 1;
}

uint8_t Ofp_match::getPad1(size_t k) const
{
    if (k >= 1) throw omnetpp::cRuntimeError("Array of size 1 indexed by %lu", (unsigned long)k);
    return this->pad1[k];
}

void Ofp_match::setPad1(size_t k, uint8_t pad1)
{
    if (k >= 1) throw omnetpp::cRuntimeError("Array of size 1 indexed by %lu", (unsigned long)k);
    handleChange();
    this->pad1[k] = pad1;
}

uint16_t Ofp_match::getDl_type() const
{
    return this->dl_type;
}

void Ofp_match::setDl_type(uint16_t dl_type)
{
    handleChange();
    this->dl_type = dl_type;
}

uint8_t Ofp_match::getNw_tos() const
{
    return this->nw_tos;
}

void Ofp_match::setNw_tos(uint8_t nw_tos)
{
    handleChange();
    this->nw_tos = nw_tos;
}

uint8_t Ofp_match::getNw_proto() const
{
    return this->nw_proto;
}

void Ofp_match::setNw_proto(uint8_t nw_proto)
{
    handleChange();
    this->nw_proto = nw_proto;
}

size_t Ofp_match::getPad2ArraySize() const
{
    return 2;
}

uint8_t Ofp_match::getPad2(size_t k) const
{
    if (k >= 2) throw omnetpp::cRuntimeError("Array of size 2 indexed by %lu", (unsigned long)k);
    return this->pad2[k];
}

void Ofp_match::setPad2(size_t k, uint8_t pad2)
{
    if (k >= 2) throw omnetpp::cRuntimeError("Array of size 2 indexed by %lu", (unsigned long)k);
    handleChange();
    this->pad2[k] = pad2;
}

const Ipv4Address& Ofp_match::getNw_src() const
{
    return this->nw_src;
}

void Ofp_match::setNw_src(const Ipv4Address& nw_src)
{
    handleChange();
    this->nw_src = nw_src;
}

const Ipv4Address& Ofp_match::getNw_dst() const
{
    return this->nw_dst;
}

void Ofp_match::setNw_dst(const Ipv4Address& nw_dst)
{
    handleChange();
    this->nw_dst = nw_dst;
}

uint16_t Ofp_match::getTp_src() const
{
    return this->tp_src;
}

void Ofp_match::setTp_src(uint16_t tp_src)
{
    handleChange();
    this->tp_src = tp_src;
}

uint16_t Ofp_match::getTp_dst() const
{
    return this->tp_dst;
}

void Ofp_match::setTp_dst(uint16_t tp_dst)
{
    handleChange();
    this->tp_dst = tp_dst;
}

class Ofp_matchDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_wildcards,
        FIELD_in_port,
        FIELD_dl_src,
        FIELD_dl_dst,
        FIELD_dl_vlan,
        FIELD_dl_vlan_pcp,
        FIELD_pad1,
        FIELD_dl_type,
        FIELD_nw_tos,
        FIELD_nw_proto,
        FIELD_pad2,
        FIELD_nw_src,
        FIELD_nw_dst,
        FIELD_tp_src,
        FIELD_tp_dst,
    };
  public:
    Ofp_matchDescriptor();
    virtual ~Ofp_matchDescriptor();

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

Register_ClassDescriptor(Ofp_matchDescriptor)

Ofp_matchDescriptor::Ofp_matchDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_match)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_matchDescriptor::~Ofp_matchDescriptor()
{
    delete[] propertynames;
}

bool Ofp_matchDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_match *>(obj)!=nullptr;
}

const char **Ofp_matchDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_matchDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_matchDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int Ofp_matchDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_wildcards
        FD_ISEDITABLE,    // FIELD_in_port
        0,    // FIELD_dl_src
        0,    // FIELD_dl_dst
        FD_ISEDITABLE,    // FIELD_dl_vlan
        FD_ISEDITABLE,    // FIELD_dl_vlan_pcp
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_pad1
        FD_ISEDITABLE,    // FIELD_dl_type
        FD_ISEDITABLE,    // FIELD_nw_tos
        FD_ISEDITABLE,    // FIELD_nw_proto
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_pad2
        0,    // FIELD_nw_src
        0,    // FIELD_nw_dst
        FD_ISEDITABLE,    // FIELD_tp_src
        FD_ISEDITABLE,    // FIELD_tp_dst
    };
    return (field >= 0 && field < 15) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_matchDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "wildcards",
        "in_port",
        "dl_src",
        "dl_dst",
        "dl_vlan",
        "dl_vlan_pcp",
        "pad1",
        "dl_type",
        "nw_tos",
        "nw_proto",
        "pad2",
        "nw_src",
        "nw_dst",
        "tp_src",
        "tp_dst",
    };
    return (field >= 0 && field < 15) ? fieldNames[field] : nullptr;
}

int Ofp_matchDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'w' && strcmp(fieldName, "wildcards") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "in_port") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dl_src") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dl_dst") == 0) return base+3;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dl_vlan") == 0) return base+4;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dl_vlan_pcp") == 0) return base+5;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad1") == 0) return base+6;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dl_type") == 0) return base+7;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nw_tos") == 0) return base+8;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nw_proto") == 0) return base+9;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad2") == 0) return base+10;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nw_src") == 0) return base+11;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nw_dst") == 0) return base+12;
    if (fieldName[0] == 't' && strcmp(fieldName, "tp_src") == 0) return base+13;
    if (fieldName[0] == 't' && strcmp(fieldName, "tp_dst") == 0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_matchDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_wildcards
        "uint16_t",    // FIELD_in_port
        "inet::MacAddress",    // FIELD_dl_src
        "inet::MacAddress",    // FIELD_dl_dst
        "uint16_t",    // FIELD_dl_vlan
        "uint8_t",    // FIELD_dl_vlan_pcp
        "uint8_t",    // FIELD_pad1
        "uint16_t",    // FIELD_dl_type
        "uint8_t",    // FIELD_nw_tos
        "uint8_t",    // FIELD_nw_proto
        "uint8_t",    // FIELD_pad2
        "inet::Ipv4Address",    // FIELD_nw_src
        "inet::Ipv4Address",    // FIELD_nw_dst
        "uint16_t",    // FIELD_tp_src
        "uint16_t",    // FIELD_tp_dst
    };
    return (field >= 0 && field < 15) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_matchDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_matchDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_matchDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_match *pp = (Ofp_match *)object; (void)pp;
    switch (field) {
        case FIELD_pad1: return 1;
        case FIELD_pad2: return 2;
        default: return 0;
    }
}

const char *Ofp_matchDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_match *pp = (Ofp_match *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_matchDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_match *pp = (Ofp_match *)object; (void)pp;
    switch (field) {
        case FIELD_wildcards: return ulong2string(pp->getWildcards());
        case FIELD_in_port: return ulong2string(pp->getIn_port());
        case FIELD_dl_src: return pp->getDl_src().str();
        case FIELD_dl_dst: return pp->getDl_dst().str();
        case FIELD_dl_vlan: return ulong2string(pp->getDl_vlan());
        case FIELD_dl_vlan_pcp: return ulong2string(pp->getDl_vlan_pcp());
        case FIELD_pad1: return ulong2string(pp->getPad1(i));
        case FIELD_dl_type: return ulong2string(pp->getDl_type());
        case FIELD_nw_tos: return ulong2string(pp->getNw_tos());
        case FIELD_nw_proto: return ulong2string(pp->getNw_proto());
        case FIELD_pad2: return ulong2string(pp->getPad2(i));
        case FIELD_nw_src: return pp->getNw_src().str();
        case FIELD_nw_dst: return pp->getNw_dst().str();
        case FIELD_tp_src: return ulong2string(pp->getTp_src());
        case FIELD_tp_dst: return ulong2string(pp->getTp_dst());
        default: return "";
    }
}

bool Ofp_matchDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_match *pp = (Ofp_match *)object; (void)pp;
    switch (field) {
        case FIELD_wildcards: pp->setWildcards(string2ulong(value)); return true;
        case FIELD_in_port: pp->setIn_port(string2ulong(value)); return true;
        case FIELD_dl_vlan: pp->setDl_vlan(string2ulong(value)); return true;
        case FIELD_dl_vlan_pcp: pp->setDl_vlan_pcp(string2ulong(value)); return true;
        case FIELD_pad1: pp->setPad1(i,string2ulong(value)); return true;
        case FIELD_dl_type: pp->setDl_type(string2ulong(value)); return true;
        case FIELD_nw_tos: pp->setNw_tos(string2ulong(value)); return true;
        case FIELD_nw_proto: pp->setNw_proto(string2ulong(value)); return true;
        case FIELD_pad2: pp->setPad2(i,string2ulong(value)); return true;
        case FIELD_tp_src: pp->setTp_src(string2ulong(value)); return true;
        case FIELD_tp_dst: pp->setTp_dst(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_matchDescriptor::getFieldStructName(int field) const
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

void *Ofp_matchDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_match *pp = (Ofp_match *)object; (void)pp;
    switch (field) {
        case FIELD_dl_src: return toVoidPtr(&pp->getDl_src()); break;
        case FIELD_dl_dst: return toVoidPtr(&pp->getDl_dst()); break;
        case FIELD_nw_src: return toVoidPtr(&pp->getNw_src()); break;
        case FIELD_nw_dst: return toVoidPtr(&pp->getNw_dst()); break;
        default: return nullptr;
    }
}

} // namespace inet

