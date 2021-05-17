/*
MIT License

Copyright (c) 2021 Rodrigo Bento

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

///////////////////////////////////////////////////////////////////////////////

#if !defined(_WIN32)
#error This library targets Microsoft Windows only
#endif

///////////////////////////////////////////////////////////////////////////////

#if !defined(_WINDOWS_)
#include <windows.h>
#endif

///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////

#if !defined(LOG_OUTPUT_FORMAT_LENGTH)
#define LOG_OUTPUT_FORMAT_LENGTH 256
#endif

///////////////////////////////////////////////////////////////////////////////

#if !defined(LOG_OUTPUT_STRING_LENGTH)
#define LOG_OUTPUT_STRING_LENGTH 1024
#endif

///////////////////////////////////////////////////////////////////////////////

#define Message(Format, ...) Log(">>>", Format, __VA_ARGS__)
#define Trace(Format, ...) Log("TRC", Format, __VA_ARGS__)
#define Debug(Format, ...) Log("DBG", Format, __VA_ARGS__)
#define  Info(Format, ...) Log("INF", Format, __VA_ARGS__)
#define  Warn(Format, ...) Log("WRN", Format, __VA_ARGS__)
#define Error(Format, ...) Log("ERR", Format, __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////
