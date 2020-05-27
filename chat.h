#ifndef CHAT_H
#define CHAT_H


#include <map>
#include "chatroom.h"
#include "utils.h"
typedef std::string ChatRoomId;

class Chat
{
public:
    Chat();
    void AddMessage(ChatRoomId chatId, Message* message);
    void AddUser(ChatRoomId chatId, UserInfo* user);
    void RemoveUser(ChatRoomId chatId, UserIdBaseType userId);
private:
    std::map<ChatRoomId, ChatRoom*> m_chatRoomTable;
};

#endif // CHAT_H
