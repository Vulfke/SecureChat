#include "chatroom.h"

ChatRoom::ChatRoom()
{

}

void ChatRoom::AddUser(UserInfo *user)
{

    m_users->insert(user->UserID(), user);
}

void ChatRoom::RemUser(UserIdBaseType userId)
{
    m_users->erase(userId);
}

void ChatRoom::AddMessage(Message *message)
{
    m_messageList->Add(message);
}


