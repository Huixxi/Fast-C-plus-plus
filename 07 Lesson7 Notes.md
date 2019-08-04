# Lesson 7 - Organizing Code with Functions
A function is hence a subprogram that optionally takes parameters and returns a value, and it needs to be invoked to perform its task.

## Function Prototype
`ReturnValueType FunctionName(FunctionParameters)`   
For example:  
```c++
double Area(double radius, int height);
```

## Function Definition
```c++
double Area(double radius) {
   return Pi * radius * radius;
}
```
## Function Call and Arguments
```c++
#include <iostream>

using namespace std;

int main(){
  int radius = 3;  // argument.
  cout << Area(radius);  // Area(radius) is a function call.
}
```
> **Note:**  
Parameter `radius` within function `Area()` is a copy of variable `radius` in `main()`.

## Functions with No Parameters or No Return Values Use `void`
```c++
void SayHello() {
  cout << "Hello~";
  return;
}
```

## Recursion — Functions That Invoke Themselves
**Note that a recursive function should have a very clearly defined exit condition where it returns without invoking itself again.**  
> **Stack Overflows**  
In the absence of an exit condition or in the event of a bug in the same, your program execution gets stuck at the recursive function that won’t stop invoking itself, and this eventually stops when the “stack overflows,” causing an application crash.

```c++
int GetFibNumber(int fibIndex) {
  if (fibIndex < 2)
    return fibIndex;  // exit condition
  else // recursion if fibIndex >= 2
    return GetFibNumber(fibIndex - 1) + GetFibNumber(fibIndex - 2);
}
```

## Overloading Functions
Same function name, different parameters.
```c++
// for circle
double Area(double radius) {
  return Pi * radius * radius;
} 
// overloaded for cylinder
double Area(double radius, double height) {
  // reuse the area of circle
  return 2 * Area (radius) + 2 * Pi * radius * height; 
}
```

## Passing an Array of Values to a Function
```c++
void DisplayArray(int numbers[], int length) {
  for (int index = 0; index < length; ++index) {
    cout << numbers[index] << " ";
  }
  cout << endl;
}
```

## Passing Arguments by Reference(!!Important)
In former example:  
```c++
double Area(double radius) {
  return Pi * radius * radius;
}
```
Here, the parameter `radius` contains a value that is copied into it when the function is invoked in `main()`: 
```c++
  // Call function "Area"
  cout << "Area is: " << Area(radius) << endl;
```
This means that the variable `radius` in `main()` is **unaffected** by the function call, as `Area()` works on a copy of the value `radius` contains, held in `radius`.  
But if you pass the reference of the variable:  
```c++
void Area(double radius, double& result) {
  result = Pi * radius * radius; 
}
```
Note the ampersand (`&`) next to the second parameter `result`. This sign indicates to the compiler that the second argument should NOT be copied to the function; instead, it is a reference to the variable being passed.
> **Note:**  
A function can return only one value using the return statement. So, if your function needs to perform operations that affect many values required at the caller, passing arguments by reference is one way to get a function to supply those many modifications back to the calling module.

## How Function Calls Are Handled by the Microprocessor
When the microprocessor encounters `CALL`, it saves the position of the instruction to be executed after the function call on the stack and jumps to the memory location contained in the `CALL` instruction.
> **Understanding the Stack**
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/stack.png)

## Inline Functions
A regular function call is translated into a `CALL` instruction, which results in stack operations and microprocessor execution shift to the function and so on.  
```c++
inline double GetPi() {
  return 3.14159; 
}
```
Classifying functions as inline can also result in a lot of code bloat, especially if the function being inline does a lot of sophisticated processing. Using the `inline` keyword should be kept to a minimum and reserved for only those functions that do very little and need to do it with minimal overhead, as demonstrated earlier.

## Automatic Return Type Deduction
```c++
auto Area(double radius) {
  return Pi * radius * radius;
}
```

## Lambda Functions
Lambda functions were introduced in C++11 and help in the usage of STL algorithms to sort or process data. This is a function that compares two arguments and returns true if one is less than the other, else false, thereby helping in deciding the order of elements in a sort operation.  
`[optional parameters](parameter list){ statements; }`
For example:  
```c++
void DisplayNums(vector<int>& dynArray) {
  for_each (dynArray.begin(), dynArray.end(), [](int Element) {cout << Element << " ";} );
  cout << endl;
}
```
