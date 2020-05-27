#ifndef CLIENT_H
#define CLIENT_H

#include <QUdpSocket>
#include <QObject>
#include "ibytearray.h"
#include "utils.h"

namespace client {

    class Client : public QObject
    {
        Q_OBJECT
    public:
        Client();
        void init();
        void send(AddressBaseType address, IByteArray* bytes);
        void check();
    private:
        QUdpSocket* socket;
    };
}

#endif // CLIENT_H
