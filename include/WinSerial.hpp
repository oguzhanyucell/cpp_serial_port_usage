#ifndef WINSERIAL_HPP
#define WINSERIAL_HPP

#include "ISerial.hpp"
#include <windows.h>

class WinSerial : public ISerial
{
public:
    WinSerial() = default;
    ~WinSerial() override;

    ErrorCode openPort(const char* portName) override;
    void closePort() override;

    ErrorCode writePort(const char* data, size_t len) override;
    ErrorCode readPort(char* buffer, size_t len) override;
    
    bool isOpen() const override;

private:
    HANDLE hSerial_ = INVALID_HANDLE_VALUE;
    bool isOpen_;
    std::string portName_;
};

#endif // WINSERIAL_HPP