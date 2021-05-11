
#pragma once

#if !defined(_WIN32)
#error This library targets Microsoft Windows only
#endif

#if !defined(_WINDOWS_)
#include <windows.h>
#endif

#include <cstdio>

#if !defined(LOG_OUTPUT_FORMAT_LENGTH)
#define LOG_OUTPUT_FORMAT_LENGTH 256
#endif

#if !defined(LOG_OUTPUT_STRING_LENGTH)
#define LOG_OUTPUT_STRING_LENGTH 1024
#endif

#define Trace(Format, ...) Log("TRACE", Format, __VA_ARGS__)
#define Debug(Format, ...) Log("DEBUG", Format, __VA_ARGS__)
#define  Info(Format, ...) Log(" INFO", Format, __VA_ARGS__)
#define  Warn(Format, ...) Log(" WARN", Format, __VA_ARGS__)
#define Error(Format, ...) Log("ERROR", Format, __VA_ARGS__)

/** Outputs a formatted message to the Visual Studio output window
 *
 * @param Marker A string that marks the message intent
 * @param Format The string format specifier
 * @param ... The variadic argument list
 */
static void __stdcall Log(const char* Marker, const char* Format, ...)
{
    va_list Args;
    va_start(Args, Format);

    char OutputFormat[LOG_OUTPUT_FORMAT_LENGTH];
    sprintf_s(OutputFormat, "%s %s\n", Marker, Format);

    char OutputString[LOG_OUTPUT_STRING_LENGTH];
    vsnprintf(OutputString, sizeof(OutputString), OutputFormat, Args);

    va_end(Args);

    OutputDebugStringA(OutputString);
}
