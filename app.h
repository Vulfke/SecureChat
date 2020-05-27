#ifndef APP_H
#define APP_H

#include "chat.h"
#include "imessagehandler.h"

class ILeaderService;
class IChat {
public:
    virtual void AddUser(UserInfo* user)=0;
    virtual void RemUser(UserIdBaseType userId)=0;
    virtual void AddMessage(Message* message)=0;

    virtual ~IChat()=0;
};

class App : public IMessageHandler
{
public:
    App();
    App& SetMessageHandler(IMessageHandler* messageHandler) {
        m_messageHandler = messageHandler;
        return *this;
    }
    App& SetLeaderService(ILeaderService* leaderService) {
        m_leaderService = leaderService;
        return *this;
    }
    App& SetChat(IChat* chat) {
        m_chat = chat;
        return *this;
    }
    IMessageHandler* MessageHandler() const {
        return m_messageHandler;
    }
    ILeaderService*  LeaderService() const {
        return m_leaderService;
    }
    IChat*           Chat() const {
        return m_chat;
    }
    void Handle(IPackage *package) override {
        m_messageHandler->Handle(package);
    }
private:
    IChat* m_chat;
    IMessageHandler* m_messageHandler;
    ILeaderService*  m_leaderService;

};

#endif // APP_H
