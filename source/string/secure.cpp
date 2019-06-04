/*!
    \file secure.cpp
    \brief Secure string implementation
    \author Ivan Shynkarenka
    \date 04.06.2019
    \copyright MIT License
*/

#include "string/secure.h"

#if defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
#include <string.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

namespace CppCommon {

void SecureZeroMemoryBuffer(void* buffer, size_t size)
{
#if defined(__APPLE__)
    memset_s(buffer, size, 0, size);
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    explicit_bzero(buffer, size);
#elif defined(_WIN32) || defined(_WIN64)
    SecureZeroMemory(buffer, size);
#else
    #error Unsupported platform
#endif
}

} // namespace CppCommon
