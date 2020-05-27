#include "utils.h"
#include "bytearray.h"


/****************************************************
 *                 Support functions                *
 ****************************************************/

auto bytesToUint32(const uint8_t* start) {
  uint32_t result = 0;
  uint8_t j = 0;
  for(auto i = start; j < (1 << 4); i++, j += 8) {
      result += (uint32_t)i[0] << j; // equals (*i)
  }
  return result;
}

auto bytesToUint16(const uint8_t* start) {
  uint16_t result = 0;
  uint8_t j = 0;
  for(auto i = start; j < (1 << 2); i++, j += 8) {
      result += (uint32_t)i[0] << j;
  }
  return result;
}

template<typename TBaseContainer>
auto bytesToContainer(const uint8_t* start, const uint8_t* finish) {
    TBaseContainer result;
    for(auto i = start; i != finish; i++) {
        result.push_back(typename TBaseContainer::value_type(*i));
    }
    return result;
}

/*****************************************************/

UserInfo::UserInfo(UserIdBaseType userId, AddressBaseType address, PortBaseType port)
{
    m_userId = userId;
    m_address = address;
    m_port = port;
}

UserIdBaseType UserInfo::UserID() const
{
    return m_userId;
}

AddressBaseType UserInfo::Address() const
{
    return m_address;
}

PortBaseType UserInfo::Port() const
{
    return m_port;
}

IByteArray *UserInfo::ToByteArray() const
{
    ByteArray* array = new ByteArray();

    array->concat((uint32_t)m_userId.size()).
           concat(m_userId).
           concat((uint32_t)m_address.size()).
           concat(m_address).
           concat(m_port);

    return (IByteArray*)array;
}

void UserInfo::Load(IByteArray *data)
{

    auto start = data->data(), finish = data->data() + 4;
    auto idSize = bytesToUint32(start);

    start = finish; finish += idSize;
    auto userId = bytesToContainer<UserIdBaseType>(start, finish);

    start = finish; finish += 4;
    auto addressSize = bytesToUint32(start);

    start = finish; finish += addressSize;
    auto address = bytesToContainer<AddressBaseType>(start, finish);

    start = finish; finish += 2;
    auto port = bytesToUint16(start);

    m_userId  = userId;
    m_address = address;
    m_port    = port;
}

Message::Message(UserIdBaseType userId, MessageBaseType msg)
{
    m_userId = userId;
    m_msg = msg;
}

UserIdBaseType Message::UserID() const
{
    return m_userId;
}

MessageBaseType Message::Msg() const
{
    return m_msg;
}

IByteArray *Message::ToByteArray() const
{
    ByteArray* array = new ByteArray();
    array->concat((uint32_t)m_userId.size()).
           concat(m_userId).
           concat((uint32_t)m_msg.size()).
           concat(m_msg);

    return (IByteArray*)array;
}

void Message::Load(IByteArray *data)
{
    auto start = data->data(), finish = data->data() + 4;
    auto idSize = bytesToUint32(start);

    start = finish; finish += idSize;
    auto userId = bytesToContainer<UserIdBaseType>(start, finish);

    start = finish; finish += 4;
    auto msgSize = bytesToUint32(start);

    start = finish; finish += msgSize;
    auto msg = bytesToContainer<MessageBaseType>(start, finish);

    m_userId = userId;
    m_msg    = msg;
}

AddRequest::AddRequest(UserInfo user): m_user(user) // could be problems with rvalue constructor
{}

UserInfo AddRequest::User() const
{
    return m_user;
}

IByteArray *AddRequest::ToByteArray() const
{
    return m_user.ToByteArray();
}

void AddRequest::Load(IByteArray *data)
{
    m_user.Load(data);
}

RemRequest::RemRequest(const UserIdBaseType& userId)
{
    m_userId = userId;
}

UserIdBaseType RemRequest::UserID() const
{
    return m_userId;
}

IByteArray *RemRequest::ToByteArray() const
{
    ByteArray* array = new ByteArray();
    array->concat((uint32_t)m_userId.size()).concat(m_userId);

    return (IByteArray*)array;
}

void RemRequest::Load(IByteArray *data)
{
    auto start = data->data(), finish = data->data() + 4;
    auto idSize = bytesToUint32(start);

    start = finish; finish += idSize;
    auto userId = bytesToContainer<UserIdBaseType>(start, finish);

    m_userId = userId;
}

Package::Package(PACKAGE_TYPE type, IByteArray *data)
{
    m_type = type;
    m_data = data;
}

IByteArray *Package::data() const
{
    return m_data;
}

IByteArray *Package::ToByteArray() const
{
    ByteArray* array = new ByteArray();
    array->concat((uint8_t)m_type).
           concat(std::move(ByteArray(m_data->data(), m_data->size())));

    return (IByteArray*)array;
}

void Package::Load(IByteArray *data)
{
    auto type = (PACKAGE_TYPE)(*data->data());
    auto ndata = new ByteArray(data->data() + 1, data->size() - 1);

    m_type = type;
    m_data = (IByteArray*)ndata;
}

PACKAGE_TYPE Package::type() const
{
    return m_type;
}


