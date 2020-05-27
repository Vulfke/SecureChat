#ifndef IPACKAGE
#define IPACKAGE

#include <stdint.h>
#include "ibytearray.h"

enum PACKAGE_TYPE : uint8_t {
    UNNAMED,
    MESSAGE,
    ADD_REQUEST,
    REM_REQUEST
};

class IPackage {
public:
    virtual PACKAGE_TYPE type() const = 0;
    virtual IByteArray* data() const = 0;
public:
    virtual ~IPackage() = default;

};

#endif // IPACKAGE

