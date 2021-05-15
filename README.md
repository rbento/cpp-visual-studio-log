# Log.h

A convenience C/C++ drop in header library that enables logging to the Visual Studio Output window

Meant for small projects only

### Usage

```     
// Alternatively adjust the output and format string length 

#define LOG_OUTPUT_FORMAT_LENGTH 512
#define LOG_OUTPUT_STRING_LENGTH 1024

#include "Log.h"

int main() 
{ 
    Info("GameObject.Id %d", 42); 
}
```

### Disable the external Command Prompt Console Window in Visual Studio 
 
For a C/C++ project on Visual Studio, set the following Project Properties:

##### Linker > System > SubSystem
 
```/SUBSYSTEM:WINDOWS```
  
##### Linker > Command Line > Additional Options
 
```/ENTRY:mainCRTStartup```

##### Or alternatively add the preprocessor comment
 
```#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")```
 
See: [https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol][1]

### Note

- If using with `glew.h` or `glfw3.h`, include `Log.h` first to avoid APIENTRY macro redefinition.
 
 [1]: https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol
