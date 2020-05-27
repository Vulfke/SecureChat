#include "usertable.h"

UserTable::UserTable()
{

}

void UserTable::insert(UserIdBaseType userId, UserInfo* user)
{
    table.insert({userId, user});
}

void UserTable::erase(UserIdBaseType userId)
{
    table.erase(userId);
}

UserInfo *UserTable::get(UserIdBaseType userId)
{
    if(table.count(userId)) {
        return table[userId];
    }
    return new UserInfo(); // returning nil object precisely
}
