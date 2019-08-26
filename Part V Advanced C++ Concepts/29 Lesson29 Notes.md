# Lesson 29 - Going Forward

## Writing Great C++ Code
* Give your variables names that make sense (to others as well as to you). It is worth spending a second more to give variables better names.
* Always initialize variables such as int, float, and the like.
* Always initialize pointer values to either NULL or a valid address—for instance, that returned by operator `new`.
* When using arrays, never cross the bounds of the array buffer. This is called a buffer overflow and can be exploited as a security vulnerability.
* Don’t use `char*` string buffers or functions such as `strlen()` and `strcpy()`. `std::string` is safer and provides many useful utility methods including ones that help you find the length, copy, and append.
* Use a static array only when you are certain of the number of elements it will contain. If you are not certain of it, choose a dynamic array such as `std::vector`.
* When declaring and defining functions that take non-POD (plain old data) types as input, consider declaring parameters as reference parameters to avoid the unnecessary copy step when the function is called.
* If your class contains a raw pointer member (or members), give thought to how memory resource ownership needs to be managed in the event of a copy or assign- ment. That is, consider programming copy constructor and copy assignment operator.
* When writing a utility class that manages a dynamic array or the like, remember to program the move constructor and the move assignment operator for better performance.
* Remember to make your code `const`-correct. A `get()` function should ideally not be able to modify the class’s members and hence should be a `const`. Similarly, function parameters should be `const`-references, unless you want to change the values they contain.
* Avoid using raw pointers. Choose the appropriate smart pointers where possible. 
* When programming a utility class, take effort in supporting all those operators that will make consuming and using the class easy.
* Given an option, choose a template version over a macro. Templates are typesafe and generic.
* When programming a class that will be collected in a container, such as a vector or a list, or used as a key element in a map, remember to support `operator<` that will help define the default sort criteria.
* If your lambda function gets too large, you should possibly consider making a function object of it—that is, a class with `operator()` as the functor is reusable and a single point of maintenance.
* Never take the success of operator new for granted. Code that performs resource allocation should always be made exception safe—bracketed within `try` with corresponding `catch()` blocks.
* Never `throw` from the destructor of a class.
