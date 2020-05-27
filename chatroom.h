#ifndef CHATROOM_H
#define CHATROOM_H

#include "utils.h"
#include "collectioninterfaces.h"
#include <map>
#include <QObject>
#include <QAbstractListModel>

class ChatRoom
{
public:
    ChatRoom();
public:
    void AddUser(UserInfo* user);
    void RemUser(UserIdBaseType userId);
    void AddMessage(Message* message);
private:
    IMessageListModel* m_messageList;
    IUserTable* m_users;
};

#endif // CHATROOM_H
