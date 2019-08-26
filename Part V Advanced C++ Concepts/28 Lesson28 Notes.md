# Lesson 28 - Exception Handling

## Implementing Exception Safety via `try` and `catch`
```c++
void SomeFunc() {
  try {
    int* numPtr = new int; 
    *numPtr = 999; 
    delete numPtr;
  }
  catch(...) // ... catches all exceptions {
    cout << "Exception in SomeFunc(), quitting" << endl; 
  }
}
```

## Catching Exception of a Type
```c++
#include<exception> // include this to catch exception bad_alloc

// ...
void SomeFunc() {
  try {
    int* numPtr = new int; 
    *numPtr = 999; 
    delete numPtr;
  }
  
  catch(std::bad_alloc& exp) {
    cout << "Exception encountered: " << exp.what() << endl;
  }
  
  catch(...) // ... catches all exceptions {
    cout << "Exception in SomeFunc(), quitting" << endl; 
  }
}
```

## Throwing Exception of a Type Using `throw`
```c++
double Divide(double dividend, double divisor) {
  if(divisor == 0)
    throw "Dividing by 0 is a crime";
  return (dividend / divisor);
}

// ...
try {
  cout << "Result is: " << Divide(dividend, divisor);
}
// catch an exception thrown in a called function Divide()
catch(const char* exp) {  // note the type char*
  cout << "Exception: " << exp << endl;
}
```

## How Exception Handling Works
Page 676

## Class `std::exception`
`std::exception` is the base class for the following important exceptions:
* `bad_alloc` - Thrown when a request for memory using `new` fails 
* `bad_cast` - Thrown by `dynamic_cast` when you try to cast a wrong type (a type that has no inheritance relation)
* `ios_base::failure` - Thrown by the functions and methods in the `iostream` library

Class `std::exception` that is the base class supports a very useful and important virtual method `what()` that gives a more descriptive reason on the nature of the problem causing the exception. You can create one `catch(const exception&)` that can catch all exceptions that have `std::exception` as base: 
```c++
void SomeFunc() {
  try {
    // code made exception safe 
  }
  catch(const std::exception& exp) {  // catch bad_alloc, bad_cast, etc 
    cout << "Exception encountered: " << exp.what() << endl; 
  }
}
```

## Your Custom Exception Class Derived from `std::exception`
```c++
class CustomException: public std::exception {
  string reason;
public:
  // constructor, needs reason
  CustomException(const char* why):reason(why) {} 
  // redefining virtual function what() to return 'reason'
  virtual const char* what() const throw() { 
    return reason.c_str();
  }
}; 

double Divide(double dividend, double divisor) {
  if(divisor == 0)
    throw CustomException("CustomException: Dividing by 0 is a crime");
  return (dividend / divisor);
}

int main() {
  // ... 
  try {
    cout << "Result is: " << Divide(dividend, divisor);
  }
  catch(exception& exp) {  // catch CustomException, bad_alloc, etc
    cout << exp.what() << endl;
  }
}
```
> `virtual const char* what() const throw()`    
It ends with `throw()`, which means that this function itself is not expected to throw an exception - a very important and relevant restriction on a class that is used as an exception object.



