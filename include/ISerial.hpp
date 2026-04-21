#ifndef ISERIAL_HPP
#define ISERIAL_HPP

#include <cstddef>
#include <string>

enum class ErrorCode
{
    SUCCESS,
    PORT_NOT_FOUND,
    PERMISSION_DENIED,
    UNKNOWN_ERROR
};

class ISerial
{
public:
    virtual ~ISerial() = default;
    virtual ErrorCode writePort(const char* data, size_t len) = 0;
    virtual ErrorCode readPort(char* buffer, size_t len) = 0;
    virtual ErrorCode openPort(const char* portName) = 0;
    virtual void closePort() = 0;
    virtual bool isOpen() const = 0;
};

#endif // ISERIAL_HPP