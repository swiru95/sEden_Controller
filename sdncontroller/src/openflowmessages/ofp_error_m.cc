//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_error.msg.
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
#include "ofp_error_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ofp_er_type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ofp_er_type"));
    e->insert(HELLO_FAILED, "HELLO_FAILED");
    e->insert(BAD_REQUEST, "BAD_REQUEST");
    e->insert(BAD_ACTION, "BAD_ACTION");
    e->insert(FLOW_MOD_FAILED, "FLOW_MOD_FAILED");
    e->insert(PORT_MOD_FAILED, "PORT_MOD_FAILED");
    e->insert(QUEUE_OP_FAILED, "QUEUE_OP_FAILED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Of_hf_er_code");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Of_hf_er_code"));
    e->insert(HF_INCOMPATIBLE, "HF_INCOMPATIBLE");
    e->insert(HF_EPERM, "HF_EPERM");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Of_br_er_code");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Of_br_er_code"));
    e->insert(BR_BAD_VERSION, "BR_BAD_VERSION");
    e->insert(BR_BAD_TYPE, "BR_BAD_TYPE");
    e->insert(BR_BAD_STAT, "BR_BAD_STAT");
    e->insert(BR_BAD_VENDOR, "BR_BAD_VENDOR");
    e->insert(BR_BAD_SUBTYPE, "BR_BAD_SUBTYPE");
    e->insert(BR_EPERM, "BR_EPERM");
    e->insert(BR_BAD_LENGTH, "BR_BAD_LENGTH");
    e->insert(BR_BUFFER_EMPTY, "BR_BUFFER_EMPTY");
    e->insert(BR_BUFFER_UKNOWN, "BR_BUFFER_UKNOWN");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Of_ba_er_code");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Of_ba_er_code"));
    e->insert(BA_BAD_TYPE, "BA_BAD_TYPE");
    e->insert(BA_BAD_LENGTH, "BA_BAD_LENGTH");
    e->insert(BA_BAD_VENDOR, "BA_BAD_VENDOR");
    e->insert(BA_BAD_VENDOR_TYPE, "BA_BAD_VENDOR_TYPE");
    e->insert(BA_BAD_OUT_PORT, "BA_BAD_OUT_PORT");
    e->insert(BA_BAD_ARGUMENTS, "BA_BAD_ARGUMENTS");
    e->insert(BA_EPERM, "BA_EPERM");
    e->insert(BA_TOO_MANY, "BA_TOO_MANY");
    e->insert(BA_BAD_QUEUE, "BA_BAD_QUEUE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Of_ofmf_er_code");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Of_ofmf_er_code"));
    e->insert(FMF_ALL_TABLES_FULL, "FMF_ALL_TABLES_FULL");
    e->insert(FMF_OVERLAP, "FMF_OVERLAP");
    e->insert(FMF_EPERM, "FMF_EPERM");
    e->insert(FMF_BAD_EMERG_TIMEOUT, "FMF_BAD_EMERG_TIMEOUT");
    e->insert(FMF_BAD_COMMAND, "FMF_BAD_COMMAND");
    e->insert(FMF_UNSUPPORTED, "FMF_UNSUPPORTED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Of_opmf_er_code");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Of_opmf_er_code"));
    e->insert(PMF_BAD_PORT, "PMF_BAD_PORT");
    e->insert(PMF_BAD_HW_ADDR, "PMF_BAD_HW_ADDR");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Of_oqof_er_code");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Of_oqof_er_code"));
    e->insert(QOF_BAD_PORT, "QOF_BAD_PORT");
    e->insert(QOF_BAD_QUEUE, "QOF_BAD_QUEUE");
    e->insert(QOF_EPERM, "QOF_EPERM");
)

Register_Class(Ofp_error)

Ofp_error::Ofp_error() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_error::Ofp_error(const Ofp_error& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_error::~Ofp_error()
{
}

Ofp_error& Ofp_error::operator=(const Ofp_error& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_error::copy(const Ofp_error& other)
{
    this->type = other.type;
    this->code = other.code;
}

void Ofp_error::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->code);
}

void Ofp_error::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->code);
}

uint16_t Ofp_error::getType() const
{
    return this->type;
}

void Ofp_error::setType(uint16_t type)
{
    handleChange();
    this->type = type;
}

uint16_t Ofp_error::getCode() const
{
    return this->code;
}

void Ofp_error::setCode(uint16_t code)
{
    handleChange();
    this->code = code;
}

class Ofp_errorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_code,
    };
  public:
    Ofp_errorDescriptor();
    virtual ~Ofp_errorDescriptor();

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

Register_ClassDescriptor(Ofp_errorDescriptor)

Ofp_errorDescriptor::Ofp_errorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_error)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_errorDescriptor::~Ofp_errorDescriptor()
{
    delete[] propertynames;
}

bool Ofp_errorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_error *>(obj)!=nullptr;
}

const char **Ofp_errorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_errorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_errorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ofp_errorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_code
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_errorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "code",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ofp_errorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_errorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_type
        "uint16_t",    // FIELD_code
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_errorDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_errorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_errorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_error *pp = (Ofp_error *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_errorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_error *pp = (Ofp_error *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_errorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_error *pp = (Ofp_error *)object; (void)pp;
    switch (field) {
        case FIELD_type: return ulong2string(pp->getType());
        case FIELD_code: return ulong2string(pp->getCode());
        default: return "";
    }
}

bool Ofp_errorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_error *pp = (Ofp_error *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2ulong(value)); return true;
        case FIELD_code: pp->setCode(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_errorDescriptor::getFieldStructName(int field) const
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

void *Ofp_errorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_error *pp = (Ofp_error *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

