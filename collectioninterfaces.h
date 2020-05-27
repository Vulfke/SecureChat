#ifndef COLLECTIONINTERFACES_H
#define COLLECTIONINTERFACES_H

#include "utils.h"
#include "iobserver.h"
#include <iterator>

class IMessageListModel {
public:
    virtual void Add(Message* message)=0;
public:
    virtual ~IMessageListModel()=default;
};

class IPeerCollection {
public:
    virtual void insert(UserIdBaseType userId, IObserver* user) = 0;
    virtual void erase(UserIdBaseType userId) = 0;
    virtual IObserver* get(UserIdBaseType userId) = 0;
    virtual void Notify(IPackage* package) = 0;
public:
    virtual ~IPeerCollection()=default;
};

class IUserTable {
public:
    virtual void insert(UserIdBaseType userId, UserInfo* user) = 0;
    virtual void erase(UserIdBaseType userId) = 0;
    virtual UserInfo* get(UserIdBaseType userId) = 0;
public:
    virtual ~IUserTable() = default;
};




#endif // COLLECTIONINTERFACES_H
