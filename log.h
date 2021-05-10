
#ifndef __RSB_LOG_H__
#define __RSB_LOG_H__

#ifndef _WIN32
  #error This library targets Microsoft Windows only.
#endif

#ifndef _WINDOWS_
  #include <windows.h>
#endif

#include <stdio.h>

#ifndef RSB_LOG_FMT_LENGTH
  #define RSB_LOG_FMT_LENGTH 256
#endif

#ifndef RSB_LOG_STR_LENGTH
  #define RSB_LOG_STR_LENGTH 1024
#endif

#define trace(...) log("TRACE", __VA_ARGS__)
#define debug(...) log("DEBUG", __VA_ARGS__)
#define  info(...) log(" INFO", __VA_ARGS__)
#define  warn(...) log(" WARN", __VA_ARGS__)
#define error(...) log("ERROR", __VA_ARGS__)

static void APIENTRY log(const char* marker, const char* format, ...)
{
    char strfmt[RSB_LOG_FMT_LENGTH];
    sprintf_s(strfmt, "%s %s\n", marker, format);

    va_list args;
    va_start(args, format);
    char strout[RSB_LOG_STR_LENGTH];
    vsnprintf(strout, sizeof(strout), strfmt, args);
    va_end(args);

    OutputDebugStringA(strout);
}
