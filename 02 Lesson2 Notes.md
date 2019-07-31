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

## The Body of Your Program `main()` Following
The execution of a C++ program always starts here. It is a standardized convention that function `main()` is declared with an `int` preceding it. `int` is the return value type of the function `main()` and stands for integer. Conventionally programmers return 0 in the event of success or –1 in the event of error.

## The Concept of Namespaces 




## CAUTION
C++ is case-sensitive. So, expect compilation to fail if you write `Int` instead of `int` and `Std::Cout` instead of `std::cout`.
