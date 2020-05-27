#ifndef SERVERSTATE
#define SERVERSTATE

#include "ipackage.h"
#include "ibytearray.h"
#include "utils.h"
#include <QDebug>
#include <QThreadPool>
#include <functional>
#include <atomic>
#include "app.h"
#include "notificationservice.h"

class Task : public QRunnable {
public:
    Task(std::function<void()>&& fun) {
        m_task = std::move(fun);
    }

    ~Task()=default;

    void run() {
        m_task();
    }
private:
    std::function<void()> m_task;
};

class ServerStateHandler {
public:
    ServerStateHandler()=default;
    ~ServerStateHandler()=default;

    void Handle(IPackage* package) {

        switch(package->type()) {

        case PACKAGE_TYPE::MESSAGE:
            handleMessage(package);
            break;

        case PACKAGE_TYPE::ADD_REQUEST:
            handleAddRequest(package);
            break;

        case PACKAGE_TYPE::REM_REQUEST:
            handleRemRequest(package);
            break;

        default:
            handleUnknown();
        };
    }

private:

    void handleMessage(IPackage* package) {
        auto task = [this, package]() {
            auto chat = app->Chat();
            auto data = package->data();
            Message* msg = new Message();
            msg->Load(data);

            chat->AddMessage(0, msg);
            notificationService->Notify(package);
        };

        pool->start(new Task(task));
    }

    void handleAddRequest(IPackage* package) {

        auto task = [this, package]() {
            auto chat = app->Chat();
            auto data = package->data();
            auto addRequest = new AddRequest();
            addRequest->Load(data);
            auto userInfo = new UserInfo(addRequest->User());

            chat->AddUser(0, userInfo);
            notificationService->AddPeer(addRequest->User());
            notificationService->Notify(package);
        };

        pool->start(new Task(task));
    }

    void handleRemRequest(IPackage* package) {
        auto task = [this, package]() {
            auto chat = app->Chat();
            auto data = package->data();
            RemRequest* remRequest = new RemRequest();
            remRequest->Load(data);

            chat->RemUser(0, remRequest->UserID());
            notificationService->RemPeer(remRequest->UserID());
            notificationService->Notify(package);
        };

        pool->start(new Task(task));
    }

    void handleUnknown() {
        auto task = []() {
            qDebug() << "Unknown package!" << endl;
        };

        pool->start(new Task(task));
    }

private:
    App* app;
    NotificationService* notificationService;
    QThreadPool* pool;
};

#endif // SERVERSTATE

