#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "utils.h"

class IObserver {
public:
    virtual void Update(IPackage* package) = 0;
public:
    virtual ~IObserver()=default;
};


#endif // IOBSERVER_H
