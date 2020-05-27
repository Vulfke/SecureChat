#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "ipackage.h"

class IMessageHandler
{
public:
    virtual void Handle(IPackage* package)=0;
public:
    virtual ~IMessageHandler()=default;
};

#endif // MESSAGEHANDLER_H
