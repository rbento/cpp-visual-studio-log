/* MIT License
 *
 * Copyright(c) 2021 Rodrigo Bento
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this softwareand associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :
 *
 * The above copyright noticeand this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Home: https://github.com/rbento/rsb
 * 
 * About:
 * 
 *     rsb/log.h, v1.0
 * 
 *     Allows simple printf like logging on the Visual Studio Output window.
 *
 * Setup:
 * 
 * Disabling the external Command Prompt Console Window in Visual Studio while keeping the C main function:
 * 
 *  For a C/C++ project on Visual Studio, set the following Project Properties:
 *
 *    Linker > System > SubSystem:
 * 
 *        /SUBSYSTEM:WINDOWS
 *
 *    Linker > Command Line > Additional Options:
 * 
 *        /ENTRY:mainCRTStartup
 *
 *    Or alternatively add the preprocessor comment:
 * 
 *        #pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
 * 
 *  See: https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol
 * 
 * Usage:
 *
 *    Default approach:
 *     
 *        #include <rsb/log.h>  
 *        void main() { log("The best number is %d", 42); }
 * 
 *    Setting the output string length:
 *    
 *        #define RSB_LOG_STR_LENGTH 80
 *        #include <rsb/log.h>
 *
 *        void main() { log("The best number is %d", 42); }
 * 
 *    Replacing printf:
 *      
 *        #define RSB_LOG_AS_PRINTF
 *        #include <rsb/log.h>
 *
 *        void main() { printf("The best number is %d", 42); }
 *
 *        // printf now outputs to the Visual Studio Output window
 */

#ifndef __RSB_LOG_H__
#define __RSB_LOG_H__

#include <stdio.h>
#include <windows.h>

#ifdef RSB_LOG_AS_PRINTF
    #define printf log
#endif

#ifndef RSB_LOG_STR_LENGTH
    #define RSB_LOG_STR_LENGTH 1024
#endif

static int __cdecl log(const char* format, ...)
{
    char strout[RSB_LOG_STR_LENGTH];
    va_list args;
    va_start(args, format);
    int done = vsnprintf(strout, sizeof(strout), format, args);
    va_end(args);
    OutputDebugStringA(strout);
    return done;
}

#endif
