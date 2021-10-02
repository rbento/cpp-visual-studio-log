# OutputDebug.h

A convenience C++ drop in header library that enables logging to the Visual Studio Output window

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

When disabled all functions can be kept in place and are switched to noop.

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
