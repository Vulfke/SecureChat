#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "ibytearray.h"
#include "ipackage.h"

/* Could be transfered to separate file with all the types used in the code */
typedef std::string UserIdBaseType;
typedef std::string MessageBaseType;
typedef std::string AddressBaseType;
typedef uint16_t PortBaseType;

class UserInfo {
public:
    UserInfo()=default;
    UserInfo(UserIdBaseType userId, AddressBaseType address, PortBaseType port);
    UserIdBaseType UserID() const;
    AddressBaseType Address() const;
    PortBaseType Port() const;
public:
    IByteArray* ToByteArray() const;
    void Load(IByteArray* data);
private:
    UserIdBaseType m_userId;
    AddressBaseType m_address;
    PortBaseType m_port;
};

class Message {
public:
    Message()=default;
    Message(UserIdBaseType userId, MessageBaseType msg);
    UserIdBaseType UserID() const;
    MessageBaseType Msg() const;
public:
    IByteArray* ToByteArray() const;
    void Load(IByteArray* data);
private:
    UserIdBaseType m_userId;
    MessageBaseType m_msg;
};

class AddRequest {
public:
    AddRequest()=default;
    AddRequest(UserInfo user);
    UserInfo User() const;
public:
    IByteArray* ToByteArray() const;
    void Load(IByteArray* data);
private:
    UserInfo m_user;
};

class RemRequest {
public:
    RemRequest()=default;
    RemRequest(const UserIdBaseType& UserId);
    UserIdBaseType UserID() const;
public:
    IByteArray* ToByteArray() const;
    void Load(IByteArray* data);
private:
    UserIdBaseType m_userId;
};

class Package : public IPackage {
public:
    Package()=default;
    Package(PACKAGE_TYPE type, IByteArray* data);
    PACKAGE_TYPE type() const override;
    IByteArray* data() const override;
public:
    IByteArray* ToByteArray() const;
    void Load(IByteArray* data);
private:
    PACKAGE_TYPE m_type;
    IByteArray* m_data;
};

#endif // UTILS_H

