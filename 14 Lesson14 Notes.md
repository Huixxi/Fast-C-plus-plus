# Lesson 14 - An Introduction to Macros and Templates

## The Preprocessor and the Compiler
The preprocessor is what runs before the compiler starts. Preprocessor directives are characterized by the fact that they all start with a `#` sign, like `#include`, `#define`.

## Using Macro `#define` to Define Constants
`#define identifier value`  
For example:  
```c++
#define PI 3.1416  // note, no ;
```
Additionally, you don’t have much control on the macro defined constant `PI`: was it a `double` or a `float`? Neither. `PI` to the preprocessor was just a text substitution element “3.1416”. It never was a defined data type.  
Constants are better defined using the const keyword with data types instead.
```c++
const double PI = 3.1416; 
```

## Using Macros for Protection against Multiple Inclusion
C++ programmers typically **declare** their classes and functions in `.H` files called header files. The respective functions are **defined** in `.CPP` files that include the header files using the `#include<header>` preprocessor directive.    
For the preprocessor, two header files that include each other is a problem of recursive nature. Use `#ifndef` and `#endif` to avoid this.  
`header1.h` that includes `<header2.h>`  
```c++
#ifndef HEADER1_H  //multiple inclusion guard:
#define HEADER1_H  // preprocessor will read this and following lines once 
#include <header2.h>
class Class1 {
  // class members, just declare.
}; 
#endif  // end of header1.h
```
`header2.h` that includes `<header1.h>`  
```c++
#ifndef HEADER2_H  //multiple inclusion guard 
#define HEADER2_H
#include <header1.h>
class Class2 {
  // class members 
}; 
#endif // end of header2.h
```

## Using `#define` to Write Macro Functions
`#define SQUARE(x) ((x) * (x))`    
**Why All the Parentheses?**   
Why `#define AREA_CIRCLE(r) (PI*(r)*(r))` not `#define AREA_CIRCLE(r) (PI*r*r)`?  
The reason lies in the way the macro is evaluated—as a **text substitution** mechanism supported by the preprocessor.  
The difference will be showed in the following case:  
If you: `AREA_CIRCLE(4+6)`, the first defination is `(PI*(4+6)*(4+6))`, but the second defination is `(PI*4+6*4+6) = (PI*4+24+6)`, which is incorrect.

## Using Macro `assert` to Validate Expressions
To use assert you `include <assert.h>`  
`assert (expression that evaluates to true or false);`  

## Advantages and Disadvantages of Using Macro Functions Macros
* These macro functions get expanded inline before compilation and hence the performance of a simple macro is superior to that of an ordinary function call doing the same task. 
* Macros do not support any form of type safety.

# An Introduction to Templates

## Template Declaration Syntax Using Keyword `template`
In my opinion, it's just a typename placeholder that when you use the function or class, you should first pass in its real dataType(like `int`, `double`, `string`) to replace the defined `objType`.
```
template <parameter list>
template function(or class) declaration.
```
```
// A template function
template <typename T1, typename T2 = T1>
bool TemplateFunction(const T1& param1, const T2& param2);  // function declaration

// A template class
template <typename T1, typename T2 = T1>
class MyTemplate {
private:
  T1 member1; T2 member2;
public:
  T1 GetObj1() {return member1; }  // ... other members
};
```
When you use the template function:  
```
int num1, num2
TemplateFunction<int>(num1, num2);
// note the <int>, it effectively defines the template parameter objType as int but not necessary when it comes to template function, it is necessary to template class.
```

## Template Classes
```c++
template <typename T> 
class HoldVarTypeT {
private: 
  T value; 
public:
  void SetValue (const T& newValue) { value = newValue; } 
  T& GetValue() {return value;}
};
```
The type of the variable `value` is `T`, and that is assigned at the time the template is used, that is, *instantiated*.
```c++
HoldVarTypeT <int> holdInt; // template instantiation for int (you can change int to other datatype)
holdInt.SetValue(5);
cout << "The value stored is: " << holdInt.GetValue() << endl;
```

## Declaring Templates with Multiple Parameters
```c++
template <typename T1, typename T2> 
class HoldsPair {
private:
  T1 value1; 
  T2 value2;
public:
  // ..
};

// Then
// A template instantiation that pairs an int with a double 
HoldsPair <int, double> pairIntDouble (6, 1.99);
```

## Declaring Templates with Default Parameters
```c++
template <typename T1=int, typename T2=int> 
class HoldsPair {
  // ... method declarations
};

// Then
// Pair an int with an int (default type) 
HoldsPair <> pairInts (6, 500);
```

## Template Instantiation and Specialization
```c++
template<> class HoldsPair<int, int> {
  // implementation code here
};
```

## Template Classes and `static` Members
**Static member instantiation syntax:**  
`template<typename T> int TestStatic<T>::staticVal;`

## Variable Templates, Also Called Variadic Templates
```c++
template <typename T1, typename T2, typename T3> 
void Sum(T1& result, T2 num1, T3 num2) {
  result = num1 + num2; 
  return;
}
``` 
> **ellipsis mark ...**  
Ellipses in C++ used with templates tell the compiler that the template class or function may accept an arbitrary number of template arguments of any type.  
`template <typename Res, typename First, typename... Rest>`    
`void Sum(Res& result, First val1, Rest... valN) {}`   
**sizeof...()**  
`int arrNums[sizeof...(Rest)];`  
It returns the number of template arguments sent to a variadic template.

The support of *variable templates* has also ushered in standard support for *tuples`*.
```c++
#include <tuple>

tuple<int, char, string> tup1(make_tuple(101, 's', "Hello Tuple!"));
```

## Using `static_assert` to Perform Compile-Time Checks
`static_assert(expression being validated, "Error message when check fails");`  
For example:  
`static_assert(sizeof(T) != sizeof(int), "No int please!");`

## Using Templates in Practical C++ Programming
An important and powerful application of templates is in the Standard Template Library (STL).
* DO use templates for the implementation of generic concepts.
* DON’T forget to use the principles of `const` correctness when program- ming template functions and classes.







