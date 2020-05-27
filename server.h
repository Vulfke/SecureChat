#ifndef SERVER_H
#define SERVER_H

#include <app.h>
#include <QUdpSocket>
#include <QObject>

namespace server {
    class Server : public QObject
    {
        Q_OBJECT
    public:
        Server(QObject *parent);
        ~Server()=default;
        void Start();
    private slots:
        void readyRead();

    private:
        App* m_app;
        QUdpSocket* socket;
    };
}

#endif // SERVER_H
