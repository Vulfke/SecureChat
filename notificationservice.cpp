#include "notificationservice.h"
#include "client.h"
#include <map>
#include <vector>

using client::Client;

class Observer : public IObserver {
public:
    Observer(UserInfo* user) {
        m_user = user;
    }
    void SetClient(Client* client) {
        m_client = client;
    }
    void Update(IPackage *package) override {
        m_client->send(m_user->Address(), package->data());
    }
private:
    UserInfo* m_user;
    Client* m_client;
};


class PeerTable : public IPeerCollection {
public:
    PeerTable()=default;
public:

    void insert(UserIdBaseType userId, IObserver *user) override {
        m_peers.insert({userId, user});
    }

    void erase(UserIdBaseType userId) override {
        m_peers.erase(userId);
    }

    IObserver * get(UserIdBaseType userId) override {
        if(!m_peers.count(userId)) {
            return new Observer(new UserInfo);
        }
        return m_peers[userId];
    }

    void Notify(IPackage* package) override {
        for(auto& [userId, observer] : m_peers) {
            observer->Update(package);
        }
    }

private:
    std::map<UserIdBaseType, IObserver*> m_peers;
};

NotificationService::NotificationService()
{
    m_peers = new PeerTable;
}

void NotificationService::Notify(IPackage *package)
{
    m_peers->Notify(package);

}

void NotificationService::AddPeer(UserInfo* user) {
    auto observer = new Observer(user);
    m_peers->insert(user->UserID(), observer);
}

void NotificationService::RemPeer(UserIdBaseType userId)
{
    m_peers->erase(userId);
}

