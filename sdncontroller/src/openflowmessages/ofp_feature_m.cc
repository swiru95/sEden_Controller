//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_feature.msg.
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
#include "ofp_feature_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::feature_capabilities");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::feature_capabilities"));
    e->insert(FLOW_STATS, "FLOW_STATS");
    e->insert(TABLE_STATS, "TABLE_STATS");
    e->insert(PORT_STATS, "PORT_STATS");
    e->insert(STP, "STP");
    e->insert(RESERVED, "RESERVED");
    e->insert(IP_REASM, "IP_REASM");
    e->insert(QUEUE_STATS, "QUEUE_STATS");
    e->insert(ARP_MATCH_IP, "ARP_MATCH_IP");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::feature_actions");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::feature_actions"));
    e->insert(OFPF_OUTPUT, "OFPF_OUTPUT");
    e->insert(OFPF_SET_VLAN_VID, "OFPF_SET_VLAN_VID");
    e->insert(OFPF_SET_VLAN_PCP, "OFPF_SET_VLAN_PCP");
    e->insert(OFPF_STRIP_VLAN, "OFPF_STRIP_VLAN");
    e->insert(OFPF_SET_DL_SRC, "OFPF_SET_DL_SRC");
    e->insert(OFPF_SET_DL_DST, "OFPF_SET_DL_DST");
    e->insert(OFPF_SET_NW_SRC, "OFPF_SET_NW_SRC");
    e->insert(OFPF_SET_NW_DST, "OFPF_SET_NW_DST");
    e->insert(OFPF_SET_NW_TOS, "OFPF_SET_NW_TOS");
    e->insert(OFPF_SET_TP_SRC, "OFPF_SET_TP_SRC");
    e->insert(OFPF_SET_TP_DST, "OFPF_SET_TP_DST");
    e->insert(OFPF_ENQUEUE, "OFPF_ENQUEUE");
)

Register_Class(Ofp_feature)

Ofp_feature::Ofp_feature() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(24));

}

Ofp_feature::Ofp_feature(const Ofp_feature& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_feature::~Ofp_feature()
{
}

Ofp_feature& Ofp_feature::operator=(const Ofp_feature& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_feature::copy(const Ofp_feature& other)
{
    this->datapath_id = other.datapath_id;
    this->n_buffers = other.n_buffers;
    this->n_tables = other.n_tables;
    for (size_t i = 0; i < 3; i++) {
        this->pad[i] = other.pad[i];
    }
    this->capabilities = other.capabilities;
    this->actions = other.actions;
}

void Ofp_feature::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->datapath_id);
    doParsimPacking(b,this->n_buffers);
    doParsimPacking(b,this->n_tables);
    doParsimArrayPacking(b,this->pad,3);
    doParsimPacking(b,this->capabilities);
    doParsimPacking(b,this->actions);
}

void Ofp_feature::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->datapath_id);
    doParsimUnpacking(b,this->n_buffers);
    doParsimUnpacking(b,this->n_tables);
    doParsimArrayUnpacking(b,this->pad,3);
    doParsimUnpacking(b,this->capabilities);
    doParsimUnpacking(b,this->actions);
}

uint64_t Ofp_feature::getDatapath_id() const
{
    return this->datapath_id;
}

void Ofp_feature::setDatapath_id(uint64_t datapath_id)
{
    handleChange();
    this->datapath_id = datapath_id;
}

uint32_t Ofp_feature::getN_buffers() const
{
    return this->n_buffers;
}

void Ofp_feature::setN_buffers(uint32_t n_buffers)
{
    handleChange();
    this->n_buffers = n_buffers;
}

uint8_t Ofp_feature::getN_tables() const
{
    return this->n_tables;
}

void Ofp_feature::setN_tables(uint8_t n_tables)
{
    handleChange();
    this->n_tables = n_tables;
}

size_t Ofp_feature::getPadArraySize() const
{
    return 3;
}

uint8_t Ofp_feature::getPad(size_t k) const
{
    if (k >= 3) throw omnetpp::cRuntimeError("Array of size 3 indexed by %lu", (unsigned long)k);
    return this->pad[k];
}

void Ofp_feature::setPad(size_t k, uint8_t pad)
{
    if (k >= 3) throw omnetpp::cRuntimeError("Array of size 3 indexed by %lu", (unsigned long)k);
    handleChange();
    this->pad[k] = pad;
}

uint32_t Ofp_feature::getCapabilities() const
{
    return this->capabilities;
}

void Ofp_feature::setCapabilities(uint32_t capabilities)
{
    handleChange();
    this->capabilities = capabilities;
}

uint32_t Ofp_feature::getActions() const
{
    return this->actions;
}

void Ofp_feature::setActions(uint32_t actions)
{
    handleChange();
    this->actions = actions;
}

class Ofp_featureDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_datapath_id,
        FIELD_n_buffers,
        FIELD_n_tables,
        FIELD_pad,
        FIELD_capabilities,
        FIELD_actions,
    };
  public:
    Ofp_featureDescriptor();
    virtual ~Ofp_featureDescriptor();

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

Register_ClassDescriptor(Ofp_featureDescriptor)

Ofp_featureDescriptor::Ofp_featureDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_feature)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_featureDescriptor::~Ofp_featureDescriptor()
{
    delete[] propertynames;
}

bool Ofp_featureDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_feature *>(obj)!=nullptr;
}

const char **Ofp_featureDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_featureDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_featureDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ofp_featureDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_datapath_id
        FD_ISEDITABLE,    // FIELD_n_buffers
        FD_ISEDITABLE,    // FIELD_n_tables
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_pad
        FD_ISEDITABLE,    // FIELD_capabilities
        FD_ISEDITABLE,    // FIELD_actions
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_featureDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "datapath_id",
        "n_buffers",
        "n_tables",
        "pad",
        "capabilities",
        "actions",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ofp_featureDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "datapath_id") == 0) return base+0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "n_buffers") == 0) return base+1;
    if (fieldName[0] == 'n' && strcmp(fieldName, "n_tables") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "capabilities") == 0) return base+4;
    if (fieldName[0] == 'a' && strcmp(fieldName, "actions") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_featureDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_datapath_id
        "uint32_t",    // FIELD_n_buffers
        "uint8_t",    // FIELD_n_tables
        "uint8_t",    // FIELD_pad
        "uint32_t",    // FIELD_capabilities
        "uint32_t",    // FIELD_actions
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_featureDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_featureDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_featureDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_feature *pp = (Ofp_feature *)object; (void)pp;
    switch (field) {
        case FIELD_pad: return 3;
        default: return 0;
    }
}

const char *Ofp_featureDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_feature *pp = (Ofp_feature *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_featureDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_feature *pp = (Ofp_feature *)object; (void)pp;
    switch (field) {
        case FIELD_datapath_id: return uint642string(pp->getDatapath_id());
        case FIELD_n_buffers: return ulong2string(pp->getN_buffers());
        case FIELD_n_tables: return ulong2string(pp->getN_tables());
        case FIELD_pad: return ulong2string(pp->getPad(i));
        case FIELD_capabilities: return ulong2string(pp->getCapabilities());
        case FIELD_actions: return ulong2string(pp->getActions());
        default: return "";
    }
}

bool Ofp_featureDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_feature *pp = (Ofp_feature *)object; (void)pp;
    switch (field) {
        case FIELD_datapath_id: pp->setDatapath_id(string2uint64(value)); return true;
        case FIELD_n_buffers: pp->setN_buffers(string2ulong(value)); return true;
        case FIELD_n_tables: pp->setN_tables(string2ulong(value)); return true;
        case FIELD_pad: pp->setPad(i,string2ulong(value)); return true;
        case FIELD_capabilities: pp->setCapabilities(string2ulong(value)); return true;
        case FIELD_actions: pp->setActions(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_featureDescriptor::getFieldStructName(int field) const
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

void *Ofp_featureDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_feature *pp = (Ofp_feature *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

