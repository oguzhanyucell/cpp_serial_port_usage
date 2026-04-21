#include "WinSerial.hpp"

WinSerial::~WinSerial()
{
    closePort();
}

ErrorCode WinSerial::writePort(const char* data, size_t len)
{
    return ErrorCode::SUCCESS;
}

ErrorCode WinSerial::readPort(char* buffer, size_t len)
{
    return ErrorCode::SUCCESS;
}

ErrorCode WinSerial::openPort(const char* portName)
{
    std::string fullPortName = "\\\\.\\" + std::string(portName);
    hSerial_ = CreateFileA(fullPortName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hSerial_ == INVALID_HANDLE_VALUE)
    {
        DWORD error = GetLastError();
        if (error == ERROR_FILE_NOT_FOUND)
            return ErrorCode::PORT_NOT_FOUND;
        else if (error == ERROR_ACCESS_DENIED)
            return ErrorCode::PERMISSION_DENIED;
        else
            return ErrorCode::UNKNOWN_ERROR;
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial_, &dcbSerialParams))
    {
        CloseHandle(hSerial_);
        return ErrorCode::UNKNOWN_ERROR;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity   = NOPARITY;

    if (!SetCommState(hSerial_, &dcbSerialParams))
    {
        CloseHandle(hSerial_);
        return ErrorCode::UNKNOWN_ERROR;
    }

    isOpen_ = true;
    portName_ = portName;

    return ErrorCode::SUCCESS;
}

void WinSerial::closePort()
{
    if (isOpen_)
    {
        CloseHandle(hSerial_);
        hSerial_ = INVALID_HANDLE_VALUE;
        isOpen_ = false;
    }
}

bool WinSerial::isOpen() const
{
    return isOpen_;
}
