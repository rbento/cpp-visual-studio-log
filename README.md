# rsb/log.h

A header library that allows simple printf like logging to the Visual Studio Output window

#### Usage

##### Default approach

```     
#include <rsb/log.h>  

int main() 
{ 
    info("The best number is %d", 42); 
}
```

##### Setting the output string length

```    
#define RSB_LOG_STR_LENGTH 80

#include <rsb/log.h>

int main() 
{ 
    info("The best number is %d", 42); 
}
```

#### Disabling the external Command Prompt Console Window in Visual Studio while keeping the C main function
 
For a C/C++ project on Visual Studio, set the following Project Properties:

##### Linker > System > SubSystem
 
```/SUBSYSTEM:WINDOWS```
  
##### Linker > Command Line > Additional Options
 
```/ENTRY:mainCRTStartup```

##### Or alternatively add the preprocessor comment
 
```#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")```
 
See: [https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol][1]

#### Note

- If using with `glew.h` or `glfw3.h`, include `<rsb/log.h>` first to avoid APIENTRY macro redefinition.
 
 [1]: https://docs.microsoft.com/en-us/cpp/build/reference/entry-entry-point-symbol