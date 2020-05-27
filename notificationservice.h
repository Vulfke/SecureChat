#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include "utils.h"
#include <vector>
#include <collectioninterfaces.h>


class NotificationService
{
public:
    NotificationService();
public:
    void Notify(IPackage* package);
    void AddPeer(UserInfo* userInfo);
    void RemPeer(UserIdBaseType userId);
private:
    IPeerCollection* m_peers;
};

#endif // NOTIFICATIONMANAGER_H
