# Lesson 5 - Working with Expressions, Statements, and Operators

## Statements
All statements in C++ end with a semicolon (;). For examples:  
```c++
cout << "Hello World" << endl;
cout << "Hello \ 
         World" << endl; // split to two lines is OK
```

## Operators
**The Assignment Operator (`=`)**   
```c++
int daysInYear = 365;
```
The assignment operator replaces the value contained by the operand to the left (unimaginatively called **l-value**) by that on the right (called **r-value**).
> **Understanding L-values and R-values**  
**L-values often refer to locations in memory**. A variable such as `daysInYear` from the preceding example is actually a handle to a memory location and is an **l-value**. **R-values**, on the other hand, can be the very content of a memory location(with no memory address). So, all l-values can be r-values, but not all r-values can be l-values, like `365 = daysInYear` is not allowed.

**Operators to Add (`+`), Subtract (`-`), Multiply (`*`), Divide (`/`), and Modulo Divide (`%`)**  

**Operators to Increment (`++`) and Decrement (`--`)**
```c++
int num1 = 101;
int num2 = num1++;  // Postfix increment operator: assign num1(101) to num2 first, then num1 += 1, now num1 is 102.
int num2 = ++num1;  // Prefix increment operator: num1 += 1 first, now num1 is 103, then assign num1(103) to num2.
int num2 = num1--;  // Postfix decrement operator: assign num1(103) to num2 first, then num1 -= 1, now num1 is 102.
int num2 = --num1;  // Prefix decrement operator: num1 -= 1 first, now num1 is 101, then assign num1(101) to num2.
```
> **To Postfix or to Prefix?**  
When no assignment, the two statements are the same:  
`startValue++; // Is the same as ...`  
`++startValue;`  
And **`++startValue` is preferred over `startValue++`**, because with the postfix operators(`startValue++;`), the compiler needs to store the initial value temporarily in the event of it needing to be assigned.  

**Equality Operators (`==`) and (`!=`)**

**Logical Operators NOT (`!`), AND (`&&`), and OR (`||`)**

**Bitwise NOT (`~`), AND (`&`), OR (`|`), and XOR (`^`) Operators**

**Bitwise Right Shift (`>>`) and Left Shift (`<<`) Operators**
Effectively doubling and quadru- pling the number.  
```c++
#include <iostream>

using namespace std;

int main(){
  int inputNum = 16;
  int halfNum = inputNum >> 1;
  int quarterNum = inputNum >> 2;

  int doubleNum = inputNum << 1; 
  int quadrupleNum = inputNum << 2;
  
  cout << "Quarter: " << quarterNum << endl;
  cout << "Half: " << halfNum << endl; cout << "Double: " << doubleNum << endl;
  cout << "Quadruple: " << quadrupleNum << endl;
  return 0;
}

// Output
// Quarter: 4 
// Half: 8 
// Double: 32 
// Quadruple: 64
```

**Compound Assignment Operators**  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/compound_oper.png)

**Using Operator `sizeof` to Determine the Memory Occupied by a Variable**  
`sizeof (variable);`   
or:  
`sizeof (type);`
