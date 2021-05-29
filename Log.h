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

////////////////////////////////////////////////////////////////////////////////

#if !defined(_WIN32)
#error This library targets Microsoft Windows only
#endif

////////////////////////////////////////////////////////////////////////////////

#if !defined(LOG_OUTPUT_ENABLED)

////////////////////////////////////////////////////////////////////////////////

#define NOOP ((void)0)

#define   Message(Format, ...) NOOP
#define     Trace(Format, ...) NOOP
#define     Debug(Format, ...) NOOP
#define      Info(Format, ...) NOOP
#define      Warn(Format, ...) NOOP 
#define     Error(Format, ...) NOOP
#define     Fatal(Format, ...) NOOP
#define LineBreak() NOOP

////////////////////////////////////////////////////////////////////////////////

#else

////////////////////////////////////////////////////////////////////////////////

#if !defined(LOG_OUTPUT_FORMAT_LENGTH)
#define LOG_OUTPUT_FORMAT_LENGTH 256
#endif

////////////////////////////////////////////////////////////////////////////////

#if !defined(LOG_OUTPUT_STRING_LENGTH)
#define LOG_OUTPUT_STRING_LENGTH 1024
#endif

////////////////////////////////////////////////////////////////////////////////

#if !defined(_WINDOWS_)
#undef APIENTRY
#include <windows.h>
#endif

////////////////////////////////////////////////////////////////////////////////

#include <cstdio>

////////////////////////////////////////////////////////////////////////////////

#define printf LogF /** printf outputs to Visual Studio Output window */

////////////////////////////////////////////////////////////////////////////////

#define Message(Format, ...) LogM(">>>", Format, __VA_ARGS__)
#define   Trace(Format, ...) LogM("TRC", Format, __VA_ARGS__)
#define   Debug(Format, ...) LogM("DBG", Format, __VA_ARGS__)
#define    Info(Format, ...) LogM("INF", Format, __VA_ARGS__)
#define    Warn(Format, ...) LogM("WRN", Format, __VA_ARGS__)
#define   Error(Format, ...) LogM("ERR", Format, __VA_ARGS__)
#define   Fatal(Format, ...) LogM("FTL", Format, __VA_ARGS__)

////////////////////////////////////////////////////////////////////////////////

static int __stdcall LogVA(const char* Format, va_list Args)
{
	char CharBuffer[LOG_OUTPUT_STRING_LENGTH];
	int NumCharsWritten = vsnprintf(CharBuffer, sizeof(CharBuffer), Format, Args);

	OutputDebugStringA(CharBuffer);

	return NumCharsWritten;
}

////////////////////////////////////////////////////////////////////////////////

static int __stdcall LogF(const char* Format, ...)
{
	va_list Args;
	va_start(Args, Format);

	int NumCharsWritten = LogVA(Format, Args);

	va_end(Args);

	return NumCharsWritten;
}

////////////////////////////////////////////////////////////////////////////////

static int __stdcall LogM(const char* Marker, const char* Format, ...)
{
	char MarkedFormat[LOG_OUTPUT_FORMAT_LENGTH];
	sprintf_s(MarkedFormat, "%s %s\n", Marker, Format);

	va_list Args;
	va_start(Args, Format);

	int NumCharsWritten = LogVA(MarkedFormat, Args);

	va_end(Args);

	return NumCharsWritten;
}

////////////////////////////////////////////////////////////////////////////////

static void __stdcall LineBreak()
{
	LogF("\n");
}

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
