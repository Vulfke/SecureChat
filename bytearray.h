#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include "ibytearray.h"
#include <vector>
#include <string>

class ByteArray : public IByteArray
{
public:
    ByteArray();
    ByteArray(const uint8_t* data, uint32_t size);
    ByteArray(char* data, uint32_t size);
    ~ByteArray()=default;

public: // interface functions
    const uint8_t* data() const override;
    uint32_t size() const override;

public: // own methods
    ByteArray &concat(ByteArray&& other);
    ByteArray &concat(const ByteArray& other);
    ByteArray &concat(uint32_t value);
    ByteArray &concat(uint16_t value);
    ByteArray &concat(uint8_t value);
    ByteArray &concat(std::string value);

private:
    std::vector<uint8_t> m_data;

};

#endif // BYTEARRAY_H
