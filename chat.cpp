#include "chat.h"
#include <QDebug>
Chat::Chat()
{

}

void Chat::AddMessage(ChatRoomId chatId, Message *message)
{
    if(!m_chatRoomTable.count(chatId)) {
        qDebug() << "AddMessage:Chat with this Id is missed" << endl;
        return;
    }
    m_chatRoomTable.at(chatId)->AddMessage(message);
}

void Chat::AddUser(ChatRoomId chatId, UserInfo *user)
{
    if(!m_chatRoomTable.count(chatId)) {
        qDebug() << "AddUser:Chat with this Id is missed" << endl;
        return;
    }
    m_chatRoomTable.at(chatId)->AddUser(user);
}

void Chat::RemoveUser(ChatRoomId chatId, UserIdBaseType userId)
{
    if(!m_chatRoomTable.count(chatId)) {
        qDebug() << "RemoveUser:Chat with this Id is missed" << endl;
        return;
    }
    m_chatRoomTable.at(chatId)->RemUser(userId);
}
