# Lesson 2 - The Anatomy of a C++ Program
``` c++
// Preprocessor directive that includes header iostream 
#include <iostream> 
// Start of your program: function block main()
int main(){
  /* Write to the screen */
  std::cout << "Hello World" << std::endl;

  // Return a value to the OS 
  return 0;
}
```
## Preprocessor Directive `#include`
Preprocessor directives are commands to the preprocessor and always start with a pound sign `#`.
* `#include <filename>` `<>` brackets are typically used when including standard headers.
* `#include "...relative path to FileB\FileB"` we use quotes `" "` when including our self-programmed headers.
