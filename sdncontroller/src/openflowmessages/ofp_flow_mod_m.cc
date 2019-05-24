//
// Generated file, do not edit! Created by nedtool 5.4 from openflowmessages/ofp_flow_mod.msg.
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
#include "ofp_flow_mod_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ofp_flow_mod_command");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ofp_flow_mod_command"));
    e->insert(OFPFC_ADD, "OFPFC_ADD");
    e->insert(OFPFC_MODIFY, "OFPFC_MODIFY");
    e->insert(OFPFC_MODIFY_STRICT, "OFPFC_MODIFY_STRICT");
    e->insert(OFPFC_DELETE, "OFPFC_DELETE");
    e->insert(OFPFC_DELETE_STRICT, "OFPFC_DELETE_STRICT");
)

Register_Class(Ofp_flow_mod)

Ofp_flow_mod::Ofp_flow_mod() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(24));

}

Ofp_flow_mod::Ofp_flow_mod(const Ofp_flow_mod& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

Ofp_flow_mod::~Ofp_flow_mod()
{
}

Ofp_flow_mod& Ofp_flow_mod::operator=(const Ofp_flow_mod& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void Ofp_flow_mod::copy(const Ofp_flow_mod& other)
{
    this->cookie = other.cookie;
    this->command = other.command;
    this->idle_timeout = other.idle_timeout;
    this->hard_timeout = other.hard_timeout;
    this->priority = other.priority;
    this->buffer_id = other.buffer_id;
    this->out_port = other.out_port;
    this->flags = other.flags;
}

void Ofp_flow_mod::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->cookie);
    doParsimPacking(b,this->command);
    doParsimPacking(b,this->idle_timeout);
    doParsimPacking(b,this->hard_timeout);
    doParsimPacking(b,this->priority);
    doParsimPacking(b,this->buffer_id);
    doParsimPacking(b,this->out_port);
    doParsimPacking(b,this->flags);
}

void Ofp_flow_mod::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cookie);
    doParsimUnpacking(b,this->command);
    doParsimUnpacking(b,this->idle_timeout);
    doParsimUnpacking(b,this->hard_timeout);
    doParsimUnpacking(b,this->priority);
    doParsimUnpacking(b,this->buffer_id);
    doParsimUnpacking(b,this->out_port);
    doParsimUnpacking(b,this->flags);
}

uint64_t Ofp_flow_mod::getCookie() const
{
    return this->cookie;
}

void Ofp_flow_mod::setCookie(uint64_t cookie)
{
    handleChange();
    this->cookie = cookie;
}

uint16_t Ofp_flow_mod::getCommand() const
{
    return this->command;
}

void Ofp_flow_mod::setCommand(uint16_t command)
{
    handleChange();
    this->command = command;
}

uint16_t Ofp_flow_mod::getIdle_timeout() const
{
    return this->idle_timeout;
}

void Ofp_flow_mod::setIdle_timeout(uint16_t idle_timeout)
{
    handleChange();
    this->idle_timeout = idle_timeout;
}

uint16_t Ofp_flow_mod::getHard_timeout() const
{
    return this->hard_timeout;
}

void Ofp_flow_mod::setHard_timeout(uint16_t hard_timeout)
{
    handleChange();
    this->hard_timeout = hard_timeout;
}

uint16_t Ofp_flow_mod::getPriority() const
{
    return this->priority;
}

void Ofp_flow_mod::setPriority(uint16_t priority)
{
    handleChange();
    this->priority = priority;
}

uint32_t Ofp_flow_mod::getBuffer_id() const
{
    return this->buffer_id;
}

void Ofp_flow_mod::setBuffer_id(uint32_t buffer_id)
{
    handleChange();
    this->buffer_id = buffer_id;
}

uint16_t Ofp_flow_mod::getOut_port() const
{
    return this->out_port;
}

void Ofp_flow_mod::setOut_port(uint16_t out_port)
{
    handleChange();
    this->out_port = out_port;
}

uint16_t Ofp_flow_mod::getFlags() const
{
    return this->flags;
}

void Ofp_flow_mod::setFlags(uint16_t flags)
{
    handleChange();
    this->flags = flags;
}

class Ofp_flow_modDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_cookie,
        FIELD_command,
        FIELD_idle_timeout,
        FIELD_hard_timeout,
        FIELD_priority,
        FIELD_buffer_id,
        FIELD_out_port,
        FIELD_flags,
    };
  public:
    Ofp_flow_modDescriptor();
    virtual ~Ofp_flow_modDescriptor();

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

Register_ClassDescriptor(Ofp_flow_modDescriptor)

Ofp_flow_modDescriptor::Ofp_flow_modDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ofp_flow_mod)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

Ofp_flow_modDescriptor::~Ofp_flow_modDescriptor()
{
    delete[] propertynames;
}

bool Ofp_flow_modDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ofp_flow_mod *>(obj)!=nullptr;
}

const char **Ofp_flow_modDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ofp_flow_modDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ofp_flow_modDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int Ofp_flow_modDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_cookie
        FD_ISEDITABLE,    // FIELD_command
        FD_ISEDITABLE,    // FIELD_idle_timeout
        FD_ISEDITABLE,    // FIELD_hard_timeout
        FD_ISEDITABLE,    // FIELD_priority
        FD_ISEDITABLE,    // FIELD_buffer_id
        FD_ISEDITABLE,    // FIELD_out_port
        FD_ISEDITABLE,    // FIELD_flags
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *Ofp_flow_modDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cookie",
        "command",
        "idle_timeout",
        "hard_timeout",
        "priority",
        "buffer_id",
        "out_port",
        "flags",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int Ofp_flow_modDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "cookie") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "command") == 0) return base+1;
    if (fieldName[0] == 'i' && strcmp(fieldName, "idle_timeout") == 0) return base+2;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hard_timeout") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "priority") == 0) return base+4;
    if (fieldName[0] == 'b' && strcmp(fieldName, "buffer_id") == 0) return base+5;
    if (fieldName[0] == 'o' && strcmp(fieldName, "out_port") == 0) return base+6;
    if (fieldName[0] == 'f' && strcmp(fieldName, "flags") == 0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ofp_flow_modDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_cookie
        "uint16_t",    // FIELD_command
        "uint16_t",    // FIELD_idle_timeout
        "uint16_t",    // FIELD_hard_timeout
        "uint16_t",    // FIELD_priority
        "uint32_t",    // FIELD_buffer_id
        "uint16_t",    // FIELD_out_port
        "uint16_t",    // FIELD_flags
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **Ofp_flow_modDescriptor::getFieldPropertyNames(int field) const
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

const char *Ofp_flow_modDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ofp_flow_modDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ofp_flow_mod *pp = (Ofp_flow_mod *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ofp_flow_modDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_flow_mod *pp = (Ofp_flow_mod *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ofp_flow_modDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ofp_flow_mod *pp = (Ofp_flow_mod *)object; (void)pp;
    switch (field) {
        case FIELD_cookie: return uint642string(pp->getCookie());
        case FIELD_command: return ulong2string(pp->getCommand());
        case FIELD_idle_timeout: return ulong2string(pp->getIdle_timeout());
        case FIELD_hard_timeout: return ulong2string(pp->getHard_timeout());
        case FIELD_priority: return ulong2string(pp->getPriority());
        case FIELD_buffer_id: return ulong2string(pp->getBuffer_id());
        case FIELD_out_port: return ulong2string(pp->getOut_port());
        case FIELD_flags: return ulong2string(pp->getFlags());
        default: return "";
    }
}

bool Ofp_flow_modDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ofp_flow_mod *pp = (Ofp_flow_mod *)object; (void)pp;
    switch (field) {
        case FIELD_cookie: pp->setCookie(string2uint64(value)); return true;
        case FIELD_command: pp->setCommand(string2ulong(value)); return true;
        case FIELD_idle_timeout: pp->setIdle_timeout(string2ulong(value)); return true;
        case FIELD_hard_timeout: pp->setHard_timeout(string2ulong(value)); return true;
        case FIELD_priority: pp->setPriority(string2ulong(value)); return true;
        case FIELD_buffer_id: pp->setBuffer_id(string2ulong(value)); return true;
        case FIELD_out_port: pp->setOut_port(string2ulong(value)); return true;
        case FIELD_flags: pp->setFlags(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ofp_flow_modDescriptor::getFieldStructName(int field) const
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

void *Ofp_flow_modDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ofp_flow_mod *pp = (Ofp_flow_mod *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

