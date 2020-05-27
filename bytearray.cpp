#include "bytearray.h"

ByteArray::ByteArray()
{

}

ByteArray::ByteArray(const uint8_t *data, uint32_t size)
{
    m_data.resize(size);
    std::copy(data, data + size, m_data.begin());
}

ByteArray::ByteArray(char *data, uint32_t size)
{
    m_data.resize(size);
    std::copy(data, data+size, m_data.begin());
}

const uint8_t *ByteArray::data() const
{
    return m_data.data();
}

uint32_t ByteArray::size() const
{
    return m_data.size();
}

ByteArray &ByteArray::concat(ByteArray&& other)
{
    int size = m_data.size();
    m_data.resize(m_data.size() + other.size());
    std::copy(other.data(), other.data() + other.size(), m_data.begin() + size);
    return *this;
}

ByteArray &ByteArray::concat(const ByteArray& other)
{
    int size = m_data.size();
    m_data.resize(m_data.size() + other.size());
    std::copy(other.data(), other.data() + other.size(), m_data.begin() + size);
    return *this;
}

ByteArray &ByteArray::concat(uint32_t value)
{
    uint8_t mask = 255;
    for(int i = 0; i < 4; i++) {
        m_data.push_back(mask & value);
        value >>= 8;
    }
    return *this;
}

ByteArray &ByteArray::concat(uint16_t value)
{
    uint8_t mask = 255;
    for(int i = 0; i < 2; i++) {
        m_data.push_back(mask & value);
        value >>= 8;
    }
    return *this;
}

ByteArray &ByteArray::concat(uint8_t value)
{
    m_data.push_back(value);
    return *this;
}

ByteArray &ByteArray::concat(std::string value)
{
    for(auto x : value) {
        m_data.push_back((uint8_t)x);
    }
    return *this;
}

