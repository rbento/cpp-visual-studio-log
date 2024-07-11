# OutputDebug.h

Convenience debug logging macros for C++ projects.

Based on the [OutputDebugStringA](https://learn.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-outputdebugstringa) that sends a string to the debugger for display, which then shows up in the Visual Studio Output window.

### Usage
---

```
#include "OutputDebug.h"

int main() 
{ 
    Info("GameObject.Id %d", 42); 
}
```

###### The Visual Studio flag `_DEBUG` controls whether OutputDebug is enabled

This flag is present by default in Visual Studio C/C++ projects in Debug configuration and not present in Release, so nothing has to be configured.

Just in case, it is set at `Project Properties` > `Configuration Properties` > `C/C++` > `Preprocessor` > `Preprocessor Definitions`.

When disabled, calls are replaced with a noop version of the logging function.

###### Customize the output debug string and format length

```
#define _OUTPUT_DEBUG_FORMAT_LENGTH 384
#define _OUTPUT_DEBUG_STRING_LENGTH 1024
```

### Disable the external Command Prompt Console Window in Visual Studio 
---
 
For a C++ project on Visual Studio, one can avoid launching the separate Command prompt and keeping all log in the Visual Studio Output window with the following Project Properties:

##### Linker > System > SubSystem
 
```
/SUBSYSTEM:WINDOWS
```
  
##### Linker > Command Line > Additional Options
 
```
/ENTRY:mainCRTStartup
```

##### Or alternatively add the preprocessor comment
 
```
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
```
 
See: [https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol][1]

 [1]: https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol
