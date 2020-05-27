#ifndef BYTEARRAY
#define BYTEARRAY

#include <stdint.h>

class IByteArray {
public:
    virtual ~IByteArray() = default;
public:
    virtual const uint8_t* data() const = 0;
    virtual uint32_t size() const = 0;
};

#endif // BYTEARRAY

