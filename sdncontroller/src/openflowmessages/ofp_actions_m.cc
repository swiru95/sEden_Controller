//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_actions.msg.
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
#include "ofp_actions_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::action_type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::action_type"));
    e->insert(OUTPUT_ACTION, "OUTPUT_ACTION");
    e->insert(SET_VLAN_VID, "SET_VLAN_VID");
    e->insert(SET_VLAN_PCP, "SET_VLAN_PCP");
    e->insert(STRIP_VLAN, "STRIP_VLAN");
    e->insert(SET_DL_SRC, "SET_DL_SRC");
    e->insert(SET_DL_DST, "SET_DL_DST");
    e->insert(SET_NW_SRC, "SET_NW_SRC");
    e->insert(SET_NW_DST, "SET_NW_DST");
    e->insert(SET_NW_TOS, "SET_NW_TOS");
    e->insert(SET_TP_SRC, "SET_TP_SRC");
    e->insert(SET_TP_DST, "SET_TP_DST");
    e->insert(ENQUEUE_ACTION, "ENQUEUE_ACTION");
    e->insert(VENDOR_ACTION, "VENDOR_ACTION");
)

Register_Class(Ofp_action_head)

Ofp_action_head::Ofp_action_head() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_action_head::Ofp_action_head(const Ofp_action_head& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_action_head::~Ofp_action_head()
{
}

Ofp_action_head& Ofp_action_head::operator=(const Ofp_action_head& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_action_head::copy(const Ofp_action_head& other)
{
    this->type = other.type;
    this->length = other.length;
}

void Ofp_action_head::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->length);
}

void Ofp_action_head::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->length);
}

uint16_t Ofp_action_head::getType() const
{
    return this->type;
}

void Ofp_action_head::setType(uint16_t type)
{
    handleChange();
    this->type = type;
}

uint16_t Ofp_action_head::getLength() const
{
    return this->length;
}

void Ofp_action_head::setLength(uint16_t length)
{
    handleChange();
    this->length = length;
}

class Ofp_action_headDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_length,
    };
  public:
    Ofp_action_headDescriptor();
    virtual ~Ofp_action_headDescriptor();

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

Register_ClassDescriptor(Ofp_action_headDescriptor)

Ofp_action_headDescriptor::Ofp_action_headDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_action_head)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_action_headDescriptor::~Ofp_action_headDescriptor()
{
    delete[] propertynames;
}

bool Ofp_action_headDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_action_head *>(obj)!=nullptr;
}

const char **Ofp_action_headDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_action_headDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_action_headDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ofp_action_headDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_length
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_action_headDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "length",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ofp_action_headDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_action_headDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_type
        "uint16_t",    // FIELD_length
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_action_headDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_action_headDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_action_headDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_action_head *pp = (Ofp_action_head *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_action_headDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_action_head *pp = (Ofp_action_head *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_action_headDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_action_head *pp = (Ofp_action_head *)object; (void)pp;
    switch (field) {
        case FIELD_type: return ulong2string(pp->getType());
        case FIELD_length: return ulong2string(pp->getLength());
        default: return "";
    }
}

bool Ofp_action_headDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_action_head *pp = (Ofp_action_head *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2ulong(value)); return true;
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_action_headDescriptor::getFieldStructName(int field) const
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

void *Ofp_action_headDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_action_head *pp = (Ofp_action_head *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_output_action)

Ofp_output_action::Ofp_output_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_output_action::Ofp_output_action(const Ofp_output_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_output_action::~Ofp_output_action()
{
}

Ofp_output_action& Ofp_output_action::operator=(const Ofp_output_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_output_action::copy(const Ofp_output_action& other)
{
    this->port = other.port;
    this->max_len = other.max_len;
}

void Ofp_output_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->port);
    doParsimPacking(b,this->max_len);
}

void Ofp_output_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->port);
    doParsimUnpacking(b,this->max_len);
}

uint16_t Ofp_output_action::getPort() const
{
    return this->port;
}

void Ofp_output_action::setPort(uint16_t port)
{
    handleChange();
    this->port = port;
}

uint16_t Ofp_output_action::getMax_len() const
{
    return this->max_len;
}

void Ofp_output_action::setMax_len(uint16_t max_len)
{
    handleChange();
    this->max_len = max_len;
}

class Ofp_output_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_port,
        FIELD_max_len,
    };
  public:
    Ofp_output_actionDescriptor();
    virtual ~Ofp_output_actionDescriptor();

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

Register_ClassDescriptor(Ofp_output_actionDescriptor)

Ofp_output_actionDescriptor::Ofp_output_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_output_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_output_actionDescriptor::~Ofp_output_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_output_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_output_action *>(obj)!=nullptr;
}

const char **Ofp_output_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_output_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_output_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ofp_output_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_port
        FD_ISEDITABLE,    // FIELD_max_len
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_output_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "port",
        "max_len",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ofp_output_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "max_len") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_output_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_port
        "uint16_t",    // FIELD_max_len
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_output_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_output_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_output_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_output_action *pp = (Ofp_output_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_output_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_output_action *pp = (Ofp_output_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_output_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_output_action *pp = (Ofp_output_action *)object; (void)pp;
    switch (field) {
        case FIELD_port: return ulong2string(pp->getPort());
        case FIELD_max_len: return ulong2string(pp->getMax_len());
        default: return "";
    }
}

bool Ofp_output_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_output_action *pp = (Ofp_output_action *)object; (void)pp;
    switch (field) {
        case FIELD_port: pp->setPort(string2ulong(value)); return true;
        case FIELD_max_len: pp->setMax_len(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_output_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_output_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_output_action *pp = (Ofp_output_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_enqueue_action)

Ofp_enqueue_action::Ofp_enqueue_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(6));

}

Ofp_enqueue_action::Ofp_enqueue_action(const Ofp_enqueue_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_enqueue_action::~Ofp_enqueue_action()
{
}

Ofp_enqueue_action& Ofp_enqueue_action::operator=(const Ofp_enqueue_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_enqueue_action::copy(const Ofp_enqueue_action& other)
{
    this->port = other.port;
    this->pad1 = other.pad1;
    this->pad2 = other.pad2;
    this->queue_id = other.queue_id;
}

void Ofp_enqueue_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->port);
    doParsimPacking(b,this->pad1);
    doParsimPacking(b,this->pad2);
    doParsimPacking(b,this->queue_id);
}

void Ofp_enqueue_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->port);
    doParsimUnpacking(b,this->pad1);
    doParsimUnpacking(b,this->pad2);
    doParsimUnpacking(b,this->queue_id);
}

uint16_t Ofp_enqueue_action::getPort() const
{
    return this->port;
}

void Ofp_enqueue_action::setPort(uint16_t port)
{
    handleChange();
    this->port = port;
}

uint16_t Ofp_enqueue_action::getPad1() const
{
    return this->pad1;
}

void Ofp_enqueue_action::setPad1(uint16_t pad1)
{
    handleChange();
    this->pad1 = pad1;
}

uint32_t Ofp_enqueue_action::getPad2() const
{
    return this->pad2;
}

void Ofp_enqueue_action::setPad2(uint32_t pad2)
{
    handleChange();
    this->pad2 = pad2;
}

uint32_t Ofp_enqueue_action::getQueue_id() const
{
    return this->queue_id;
}

void Ofp_enqueue_action::setQueue_id(uint32_t queue_id)
{
    handleChange();
    this->queue_id = queue_id;
}

class Ofp_enqueue_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_port,
        FIELD_pad1,
        FIELD_pad2,
        FIELD_queue_id,
    };
  public:
    Ofp_enqueue_actionDescriptor();
    virtual ~Ofp_enqueue_actionDescriptor();

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

Register_ClassDescriptor(Ofp_enqueue_actionDescriptor)

Ofp_enqueue_actionDescriptor::Ofp_enqueue_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_enqueue_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_enqueue_actionDescriptor::~Ofp_enqueue_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_enqueue_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_enqueue_action *>(obj)!=nullptr;
}

const char **Ofp_enqueue_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_enqueue_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_enqueue_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ofp_enqueue_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_port
        FD_ISEDITABLE,    // FIELD_pad1
        FD_ISEDITABLE,    // FIELD_pad2
        FD_ISEDITABLE,    // FIELD_queue_id
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_enqueue_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "port",
        "pad1",
        "pad2",
        "queue_id",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int Ofp_enqueue_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad1") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad2") == 0) return base+2;
    if (fieldName[0] == 'q' && strcmp(fieldName, "queue_id") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_enqueue_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_port
        "uint16_t",    // FIELD_pad1
        "uint32_t",    // FIELD_pad2
        "uint32_t",    // FIELD_queue_id
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_enqueue_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_enqueue_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_enqueue_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_enqueue_action *pp = (Ofp_enqueue_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_enqueue_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_enqueue_action *pp = (Ofp_enqueue_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_enqueue_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_enqueue_action *pp = (Ofp_enqueue_action *)object; (void)pp;
    switch (field) {
        case FIELD_port: return ulong2string(pp->getPort());
        case FIELD_pad1: return ulong2string(pp->getPad1());
        case FIELD_pad2: return ulong2string(pp->getPad2());
        case FIELD_queue_id: return ulong2string(pp->getQueue_id());
        default: return "";
    }
}

bool Ofp_enqueue_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_enqueue_action *pp = (Ofp_enqueue_action *)object; (void)pp;
    switch (field) {
        case FIELD_port: pp->setPort(string2ulong(value)); return true;
        case FIELD_pad1: pp->setPad1(string2ulong(value)); return true;
        case FIELD_pad2: pp->setPad2(string2ulong(value)); return true;
        case FIELD_queue_id: pp->setQueue_id(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_enqueue_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_enqueue_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_enqueue_action *pp = (Ofp_enqueue_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_setvlanvid_action)

Ofp_setvlanvid_action::Ofp_setvlanvid_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_setvlanvid_action::Ofp_setvlanvid_action(const Ofp_setvlanvid_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_setvlanvid_action::~Ofp_setvlanvid_action()
{
}

Ofp_setvlanvid_action& Ofp_setvlanvid_action::operator=(const Ofp_setvlanvid_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_setvlanvid_action::copy(const Ofp_setvlanvid_action& other)
{
    this->vlan_vid = other.vlan_vid;
    this->pad = other.pad;
}

void Ofp_setvlanvid_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->vlan_vid);
    doParsimPacking(b,this->pad);
}

void Ofp_setvlanvid_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->vlan_vid);
    doParsimUnpacking(b,this->pad);
}

uint16_t Ofp_setvlanvid_action::getVlan_vid() const
{
    return this->vlan_vid;
}

void Ofp_setvlanvid_action::setVlan_vid(uint16_t vlan_vid)
{
    handleChange();
    this->vlan_vid = vlan_vid;
}

uint16_t Ofp_setvlanvid_action::getPad() const
{
    return this->pad;
}

void Ofp_setvlanvid_action::setPad(uint16_t pad)
{
    handleChange();
    this->pad = pad;
}

class Ofp_setvlanvid_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_vlan_vid,
        FIELD_pad,
    };
  public:
    Ofp_setvlanvid_actionDescriptor();
    virtual ~Ofp_setvlanvid_actionDescriptor();

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

Register_ClassDescriptor(Ofp_setvlanvid_actionDescriptor)

Ofp_setvlanvid_actionDescriptor::Ofp_setvlanvid_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_setvlanvid_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_setvlanvid_actionDescriptor::~Ofp_setvlanvid_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_setvlanvid_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_setvlanvid_action *>(obj)!=nullptr;
}

const char **Ofp_setvlanvid_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_setvlanvid_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_setvlanvid_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ofp_setvlanvid_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_vlan_vid
        FD_ISEDITABLE,    // FIELD_pad
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_setvlanvid_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vlan_vid",
        "pad",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ofp_setvlanvid_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vlan_vid") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_setvlanvid_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_vlan_vid
        "uint16_t",    // FIELD_pad
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_setvlanvid_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_setvlanvid_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_setvlanvid_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanvid_action *pp = (Ofp_setvlanvid_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_setvlanvid_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanvid_action *pp = (Ofp_setvlanvid_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_setvlanvid_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanvid_action *pp = (Ofp_setvlanvid_action *)object; (void)pp;
    switch (field) {
        case FIELD_vlan_vid: return ulong2string(pp->getVlan_vid());
        case FIELD_pad: return ulong2string(pp->getPad());
        default: return "";
    }
}

bool Ofp_setvlanvid_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanvid_action *pp = (Ofp_setvlanvid_action *)object; (void)pp;
    switch (field) {
        case FIELD_vlan_vid: pp->setVlan_vid(string2ulong(value)); return true;
        case FIELD_pad: pp->setPad(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_setvlanvid_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_setvlanvid_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanvid_action *pp = (Ofp_setvlanvid_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_setnwaddr_action)

Ofp_setnwaddr_action::Ofp_setnwaddr_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_setnwaddr_action::Ofp_setnwaddr_action(const Ofp_setnwaddr_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_setnwaddr_action::~Ofp_setnwaddr_action()
{
}

Ofp_setnwaddr_action& Ofp_setnwaddr_action::operator=(const Ofp_setnwaddr_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_setnwaddr_action::copy(const Ofp_setnwaddr_action& other)
{
    this->nw_addr = other.nw_addr;
}

void Ofp_setnwaddr_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->nw_addr);
}

void Ofp_setnwaddr_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->nw_addr);
}

const Ipv4Address& Ofp_setnwaddr_action::getNw_addr() const
{
    return this->nw_addr;
}

void Ofp_setnwaddr_action::setNw_addr(const Ipv4Address& nw_addr)
{
    handleChange();
    this->nw_addr = nw_addr;
}

class Ofp_setnwaddr_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_nw_addr,
    };
  public:
    Ofp_setnwaddr_actionDescriptor();
    virtual ~Ofp_setnwaddr_actionDescriptor();

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

Register_ClassDescriptor(Ofp_setnwaddr_actionDescriptor)

Ofp_setnwaddr_actionDescriptor::Ofp_setnwaddr_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_setnwaddr_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_setnwaddr_actionDescriptor::~Ofp_setnwaddr_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_setnwaddr_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_setnwaddr_action *>(obj)!=nullptr;
}

const char **Ofp_setnwaddr_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_setnwaddr_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_setnwaddr_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ofp_setnwaddr_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_nw_addr
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_setnwaddr_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nw_addr",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ofp_setnwaddr_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nw_addr") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_setnwaddr_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_nw_addr
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_setnwaddr_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_setnwaddr_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_setnwaddr_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwaddr_action *pp = (Ofp_setnwaddr_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_setnwaddr_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwaddr_action *pp = (Ofp_setnwaddr_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_setnwaddr_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwaddr_action *pp = (Ofp_setnwaddr_action *)object; (void)pp;
    switch (field) {
        case FIELD_nw_addr: return pp->getNw_addr().str();
        default: return "";
    }
}

bool Ofp_setnwaddr_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwaddr_action *pp = (Ofp_setnwaddr_action *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ofp_setnwaddr_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_setnwaddr_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwaddr_action *pp = (Ofp_setnwaddr_action *)object; (void)pp;
    switch (field) {
        case FIELD_nw_addr: return toVoidPtr(&pp->getNw_addr()); break;
        default: return nullptr;
    }
}

Register_Class(Ofp_vendor_action)

Ofp_vendor_action::Ofp_vendor_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_vendor_action::Ofp_vendor_action(const Ofp_vendor_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_vendor_action::~Ofp_vendor_action()
{
}

Ofp_vendor_action& Ofp_vendor_action::operator=(const Ofp_vendor_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_vendor_action::copy(const Ofp_vendor_action& other)
{
    this->vendor = other.vendor;
}

void Ofp_vendor_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->vendor);
}

void Ofp_vendor_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->vendor);
}

uint32_t Ofp_vendor_action::getVendor() const
{
    return this->vendor;
}

void Ofp_vendor_action::setVendor(uint32_t vendor)
{
    handleChange();
    this->vendor = vendor;
}

class Ofp_vendor_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_vendor,
    };
  public:
    Ofp_vendor_actionDescriptor();
    virtual ~Ofp_vendor_actionDescriptor();

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

Register_ClassDescriptor(Ofp_vendor_actionDescriptor)

Ofp_vendor_actionDescriptor::Ofp_vendor_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_vendor_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_vendor_actionDescriptor::~Ofp_vendor_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_vendor_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_vendor_action *>(obj)!=nullptr;
}

const char **Ofp_vendor_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_vendor_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_vendor_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ofp_vendor_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_vendor
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_vendor_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vendor",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int Ofp_vendor_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vendor") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_vendor_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",    // FIELD_vendor
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_vendor_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_vendor_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_vendor_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_vendor_action *pp = (Ofp_vendor_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_vendor_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_vendor_action *pp = (Ofp_vendor_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_vendor_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_vendor_action *pp = (Ofp_vendor_action *)object; (void)pp;
    switch (field) {
        case FIELD_vendor: return ulong2string(pp->getVendor());
        default: return "";
    }
}

bool Ofp_vendor_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_vendor_action *pp = (Ofp_vendor_action *)object; (void)pp;
    switch (field) {
        case FIELD_vendor: pp->setVendor(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_vendor_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_vendor_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_vendor_action *pp = (Ofp_vendor_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_setvlanpcp_action)

Ofp_setvlanpcp_action::Ofp_setvlanpcp_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_setvlanpcp_action::Ofp_setvlanpcp_action(const Ofp_setvlanpcp_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_setvlanpcp_action::~Ofp_setvlanpcp_action()
{
}

Ofp_setvlanpcp_action& Ofp_setvlanpcp_action::operator=(const Ofp_setvlanpcp_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_setvlanpcp_action::copy(const Ofp_setvlanpcp_action& other)
{
    this->vlan_pc = other.vlan_pc;
    this->pad1 = other.pad1;
    this->pad2 = other.pad2;
}

void Ofp_setvlanpcp_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->vlan_pc);
    doParsimPacking(b,this->pad1);
    doParsimPacking(b,this->pad2);
}

void Ofp_setvlanpcp_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->vlan_pc);
    doParsimUnpacking(b,this->pad1);
    doParsimUnpacking(b,this->pad2);
}

uint8_t Ofp_setvlanpcp_action::getVlan_pc() const
{
    return this->vlan_pc;
}

void Ofp_setvlanpcp_action::setVlan_pc(uint8_t vlan_pc)
{
    handleChange();
    this->vlan_pc = vlan_pc;
}

uint8_t Ofp_setvlanpcp_action::getPad1() const
{
    return this->pad1;
}

void Ofp_setvlanpcp_action::setPad1(uint8_t pad1)
{
    handleChange();
    this->pad1 = pad1;
}

uint16_t Ofp_setvlanpcp_action::getPad2() const
{
    return this->pad2;
}

void Ofp_setvlanpcp_action::setPad2(uint16_t pad2)
{
    handleChange();
    this->pad2 = pad2;
}

class Ofp_setvlanpcp_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_vlan_pc,
        FIELD_pad1,
        FIELD_pad2,
    };
  public:
    Ofp_setvlanpcp_actionDescriptor();
    virtual ~Ofp_setvlanpcp_actionDescriptor();

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

Register_ClassDescriptor(Ofp_setvlanpcp_actionDescriptor)

Ofp_setvlanpcp_actionDescriptor::Ofp_setvlanpcp_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_setvlanpcp_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_setvlanpcp_actionDescriptor::~Ofp_setvlanpcp_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_setvlanpcp_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_setvlanpcp_action *>(obj)!=nullptr;
}

const char **Ofp_setvlanpcp_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_setvlanpcp_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_setvlanpcp_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ofp_setvlanpcp_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_vlan_pc
        FD_ISEDITABLE,    // FIELD_pad1
        FD_ISEDITABLE,    // FIELD_pad2
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_setvlanpcp_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vlan_pc",
        "pad1",
        "pad2",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ofp_setvlanpcp_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vlan_pc") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad1") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad2") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_setvlanpcp_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_vlan_pc
        "uint8_t",    // FIELD_pad1
        "uint16_t",    // FIELD_pad2
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_setvlanpcp_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_setvlanpcp_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_setvlanpcp_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanpcp_action *pp = (Ofp_setvlanpcp_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_setvlanpcp_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanpcp_action *pp = (Ofp_setvlanpcp_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_setvlanpcp_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanpcp_action *pp = (Ofp_setvlanpcp_action *)object; (void)pp;
    switch (field) {
        case FIELD_vlan_pc: return ulong2string(pp->getVlan_pc());
        case FIELD_pad1: return ulong2string(pp->getPad1());
        case FIELD_pad2: return ulong2string(pp->getPad2());
        default: return "";
    }
}

bool Ofp_setvlanpcp_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanpcp_action *pp = (Ofp_setvlanpcp_action *)object; (void)pp;
    switch (field) {
        case FIELD_vlan_pc: pp->setVlan_pc(string2ulong(value)); return true;
        case FIELD_pad1: pp->setPad1(string2ulong(value)); return true;
        case FIELD_pad2: pp->setPad2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_setvlanpcp_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_setvlanpcp_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setvlanpcp_action *pp = (Ofp_setvlanpcp_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_setnwtos_action)

Ofp_setnwtos_action::Ofp_setnwtos_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_setnwtos_action::Ofp_setnwtos_action(const Ofp_setnwtos_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_setnwtos_action::~Ofp_setnwtos_action()
{
}

Ofp_setnwtos_action& Ofp_setnwtos_action::operator=(const Ofp_setnwtos_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_setnwtos_action::copy(const Ofp_setnwtos_action& other)
{
    this->nw_tos = other.nw_tos;
    this->pad1 = other.pad1;
    this->pad2 = other.pad2;
}

void Ofp_setnwtos_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->nw_tos);
    doParsimPacking(b,this->pad1);
    doParsimPacking(b,this->pad2);
}

void Ofp_setnwtos_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->nw_tos);
    doParsimUnpacking(b,this->pad1);
    doParsimUnpacking(b,this->pad2);
}

uint8_t Ofp_setnwtos_action::getNw_tos() const
{
    return this->nw_tos;
}

void Ofp_setnwtos_action::setNw_tos(uint8_t nw_tos)
{
    handleChange();
    this->nw_tos = nw_tos;
}

uint8_t Ofp_setnwtos_action::getPad1() const
{
    return this->pad1;
}

void Ofp_setnwtos_action::setPad1(uint8_t pad1)
{
    handleChange();
    this->pad1 = pad1;
}

uint16_t Ofp_setnwtos_action::getPad2() const
{
    return this->pad2;
}

void Ofp_setnwtos_action::setPad2(uint16_t pad2)
{
    handleChange();
    this->pad2 = pad2;
}

class Ofp_setnwtos_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_nw_tos,
        FIELD_pad1,
        FIELD_pad2,
    };
  public:
    Ofp_setnwtos_actionDescriptor();
    virtual ~Ofp_setnwtos_actionDescriptor();

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

Register_ClassDescriptor(Ofp_setnwtos_actionDescriptor)

Ofp_setnwtos_actionDescriptor::Ofp_setnwtos_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_setnwtos_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_setnwtos_actionDescriptor::~Ofp_setnwtos_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_setnwtos_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_setnwtos_action *>(obj)!=nullptr;
}

const char **Ofp_setnwtos_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_setnwtos_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_setnwtos_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ofp_setnwtos_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_nw_tos
        FD_ISEDITABLE,    // FIELD_pad1
        FD_ISEDITABLE,    // FIELD_pad2
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_setnwtos_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nw_tos",
        "pad1",
        "pad2",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ofp_setnwtos_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nw_tos") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad1") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad2") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_setnwtos_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_nw_tos
        "uint8_t",    // FIELD_pad1
        "uint16_t",    // FIELD_pad2
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_setnwtos_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_setnwtos_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_setnwtos_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwtos_action *pp = (Ofp_setnwtos_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_setnwtos_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwtos_action *pp = (Ofp_setnwtos_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_setnwtos_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwtos_action *pp = (Ofp_setnwtos_action *)object; (void)pp;
    switch (field) {
        case FIELD_nw_tos: return ulong2string(pp->getNw_tos());
        case FIELD_pad1: return ulong2string(pp->getPad1());
        case FIELD_pad2: return ulong2string(pp->getPad2());
        default: return "";
    }
}

bool Ofp_setnwtos_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwtos_action *pp = (Ofp_setnwtos_action *)object; (void)pp;
    switch (field) {
        case FIELD_nw_tos: pp->setNw_tos(string2ulong(value)); return true;
        case FIELD_pad1: pp->setPad1(string2ulong(value)); return true;
        case FIELD_pad2: pp->setPad2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_setnwtos_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_setnwtos_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setnwtos_action *pp = (Ofp_setnwtos_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ofp_setdladdr_action)

Ofp_setdladdr_action::Ofp_setdladdr_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(12));

}

Ofp_setdladdr_action::Ofp_setdladdr_action(const Ofp_setdladdr_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_setdladdr_action::~Ofp_setdladdr_action()
{
}

Ofp_setdladdr_action& Ofp_setdladdr_action::operator=(const Ofp_setdladdr_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_setdladdr_action::copy(const Ofp_setdladdr_action& other)
{
    this->dl_addr = other.dl_addr;
    this->pad1 = other.pad1;
    this->pad2 = other.pad2;
}

void Ofp_setdladdr_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->dl_addr);
    doParsimPacking(b,this->pad1);
    doParsimPacking(b,this->pad2);
}

void Ofp_setdladdr_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->dl_addr);
    doParsimUnpacking(b,this->pad1);
    doParsimUnpacking(b,this->pad2);
}

const MacAddress& Ofp_setdladdr_action::getDl_addr() const
{
    return this->dl_addr;
}

void Ofp_setdladdr_action::setDl_addr(const MacAddress& dl_addr)
{
    handleChange();
    this->dl_addr = dl_addr;
}

uint16_t Ofp_setdladdr_action::getPad1() const
{
    return this->pad1;
}

void Ofp_setdladdr_action::setPad1(uint16_t pad1)
{
    handleChange();
    this->pad1 = pad1;
}

uint32_t Ofp_setdladdr_action::getPad2() const
{
    return this->pad2;
}

void Ofp_setdladdr_action::setPad2(uint32_t pad2)
{
    handleChange();
    this->pad2 = pad2;
}

class Ofp_setdladdr_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_dl_addr,
        FIELD_pad1,
        FIELD_pad2,
    };
  public:
    Ofp_setdladdr_actionDescriptor();
    virtual ~Ofp_setdladdr_actionDescriptor();

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

Register_ClassDescriptor(Ofp_setdladdr_actionDescriptor)

Ofp_setdladdr_actionDescriptor::Ofp_setdladdr_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_setdladdr_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_setdladdr_actionDescriptor::~Ofp_setdladdr_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_setdladdr_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_setdladdr_action *>(obj)!=nullptr;
}

const char **Ofp_setdladdr_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_setdladdr_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_setdladdr_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ofp_setdladdr_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_dl_addr
        FD_ISEDITABLE,    // FIELD_pad1
        FD_ISEDITABLE,    // FIELD_pad2
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_setdladdr_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dl_addr",
        "pad1",
        "pad2",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int Ofp_setdladdr_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dl_addr") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad1") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad2") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_setdladdr_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_dl_addr
        "uint16_t",    // FIELD_pad1
        "uint32_t",    // FIELD_pad2
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_setdladdr_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_setdladdr_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_setdladdr_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_setdladdr_action *pp = (Ofp_setdladdr_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_setdladdr_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setdladdr_action *pp = (Ofp_setdladdr_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_setdladdr_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setdladdr_action *pp = (Ofp_setdladdr_action *)object; (void)pp;
    switch (field) {
        case FIELD_dl_addr: return pp->getDl_addr().str();
        case FIELD_pad1: return ulong2string(pp->getPad1());
        case FIELD_pad2: return ulong2string(pp->getPad2());
        default: return "";
    }
}

bool Ofp_setdladdr_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_setdladdr_action *pp = (Ofp_setdladdr_action *)object; (void)pp;
    switch (field) {
        case FIELD_pad1: pp->setPad1(string2ulong(value)); return true;
        case FIELD_pad2: pp->setPad2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_setdladdr_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_setdladdr_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_setdladdr_action *pp = (Ofp_setdladdr_action *)object; (void)pp;
    switch (field) {
        case FIELD_dl_addr: return toVoidPtr(&pp->getDl_addr()); break;
        default: return nullptr;
    }
}

Register_Class(Ofp_settcport_action)

Ofp_settcport_action::Ofp_settcport_action() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(4));

}

Ofp_settcport_action::Ofp_settcport_action(const Ofp_settcport_action& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_settcport_action::~Ofp_settcport_action()
{
}

Ofp_settcport_action& Ofp_settcport_action::operator=(const Ofp_settcport_action& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_settcport_action::copy(const Ofp_settcport_action& other)
{
    this->port = other.port;
    this->pad = other.pad;
}

void Ofp_settcport_action::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->port);
    doParsimPacking(b,this->pad);
}

void Ofp_settcport_action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->port);
    doParsimUnpacking(b,this->pad);
}

uint16_t Ofp_settcport_action::getPort() const
{
    return this->port;
}

void Ofp_settcport_action::setPort(uint16_t port)
{
    handleChange();
    this->port = port;
}

uint16_t Ofp_settcport_action::getPad() const
{
    return this->pad;
}

void Ofp_settcport_action::setPad(uint16_t pad)
{
    handleChange();
    this->pad = pad;
}

class Ofp_settcport_actionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_port,
        FIELD_pad,
    };
  public:
    Ofp_settcport_actionDescriptor();
    virtual ~Ofp_settcport_actionDescriptor();

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

Register_ClassDescriptor(Ofp_settcport_actionDescriptor)

Ofp_settcport_actionDescriptor::Ofp_settcport_actionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_settcport_action)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_settcport_actionDescriptor::~Ofp_settcport_actionDescriptor()
{
    delete[] propertynames;
}

bool Ofp_settcport_actionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_settcport_action *>(obj)!=nullptr;
}

const char **Ofp_settcport_actionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_settcport_actionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_settcport_actionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ofp_settcport_actionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_port
        FD_ISEDITABLE,    // FIELD_pad
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_settcport_actionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "port",
        "pad",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int Ofp_settcport_actionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "port") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pad") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_settcport_actionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_port
        "uint16_t",    // FIELD_pad
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_settcport_actionDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_settcport_actionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_settcport_actionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_settcport_action *pp = (Ofp_settcport_action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_settcport_actionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_settcport_action *pp = (Ofp_settcport_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_settcport_actionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_settcport_action *pp = (Ofp_settcport_action *)object; (void)pp;
    switch (field) {
        case FIELD_port: return ulong2string(pp->getPort());
        case FIELD_pad: return ulong2string(pp->getPad());
        default: return "";
    }
}

bool Ofp_settcport_actionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_settcport_action *pp = (Ofp_settcport_action *)object; (void)pp;
    switch (field) {
        case FIELD_port: pp->setPort(string2ulong(value)); return true;
        case FIELD_pad: pp->setPad(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_settcport_actionDescriptor::getFieldStructName(int field) const
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

void *Ofp_settcport_actionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_settcport_action *pp = (Ofp_settcport_action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

