#ifndef USERTABLE_H
#define USERTABLE_H

#include "collectioninterfaces.h"
#include <map>

class UserTable : public IUserTable {
public:
    UserTable();
public:
    void insert(UserIdBaseType userId, UserInfo* user) override;
    void erase(UserIdBaseType userId) override;
    UserInfo * get(UserIdBaseType userId) override;
private:
    std::map<UserIdBaseType, UserInfo*> table;

};

#endif // USERTABLE_H
