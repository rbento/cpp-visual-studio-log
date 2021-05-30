# OutputDebug.h

A convenience C++ drop in header library that enables logging to the Visual Studio Output window

### Usage
---

```
#define _OUTPUT_DEBUG_ENABLED
#include "OutputDebug.h"

int main() 
{ 
    Info("GameObject.Id %d", 42); 
}
```

###### Output Debug is disabled by default

The keys below should be defined before including the `OutputDebug.h`, only once, either at the entry point, precompiled header or in Visual Studio via `Project Properties > C/C++ > Preprocessor > Preprocessor Definitions`


###### Enable Output Debug printing

```
#define _OUTPUT_DEBUG_ENABLED
```

When disabled all functions can be kept in place and are switched to noop

###### Customize the output debug string and format length

```
#define _OUTPUT_DEBUG_FORMAT_LENGTH 384
#define _OUTPUT_DEBUG_STRING_LENGTH 1024
```

### Disable the external Command Prompt Console Window in Visual Studio 
---
 
For a C++ project on Visual Studio, one can avoid launching the separate Command prompt and keeping all log in the Visual Studio Output window by settings the following Project Properties:

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
