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
Namespaces are names given to parts of code that help in reducing the potential for a **naming conflict**. By invoking `std::cout`, you are telling the compiler to use that one unique `cout` that is available in the `std` namespace.   
i.e. maybe there is another namespace called `stdddd`, and there is also a `cout` function in it, so that when you just use `cout`, the compiler will be confused that which `cout` you used either `std::cout` or `stdddd::cout`. Then if you tell the compiler that I will `using namespace std`, the compiler will know that the `cout` is `std::cout`.



## CAUTION
C++ is case-sensitive. So, expect compilation to fail if you write `Int` instead of `int` and `Std::Cout` instead of `std::cout`.
