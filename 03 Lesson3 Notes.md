## Lesson 3 - Using Variables, Declaring Constants
**Variables** are tools that help the programmer temporarily store data for a finite amount of time. **Constants** are tools that help the programmer define artifacts that are not allowed to change or make changes.  

## Memory and Addressing in Brief 
All computers, smart phones, and other programmable devices contain a microprocessor and a certain amount of memory for temporary storage called **Random Access Memory (RAM)**. 
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/what_is_ram.png)
The RAM itself can be considered to be a storage area akin to a row of lockers in the dorms, each locker having a number—that is, an **address**.
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/ram_address.png)

## Declaring Variables to Access and Use Memory
**Defining a variable:**  
* `VariableType VariableName;`   
or:  
* `VariableType VariableName = InitialValue;`

(It is always good to give the variable an `InitialValue`, rather than leave it with an unknown value of that memory location which can be bad for the program.)  
The `VariableType` attribute tells the compiler ***the nature of data the variable can store***, and the compiler ***reserves the necessary space for it***. The `VariableName` chosen by the programmer is ***a friendly replacement for the address*** in the memory where the variable’s value is stored, **i.e.** a readable name not a confusing address number, the compiler will do the job of mapping the vairable name to a associated memory location.

## Declaring and Initializing Multiple Variables of a Type
```c++
int firstNumber = 0, secondNumber = 0, multiplicationResult = 0;
```

## Warm Reminder: the Scope of a Variable and Global Variables
(**Note:** Indiscriminate use of global variables is considered poor pro- gramming practice.)
```c++
#include <iostream>
using namespace std;
// a global integer 
int globalNumber = 0; 

int main(){
  cout << globalNumber << endl;
  // ...
}
```

## Naming Conventions
!! When working in a team, it is a good idea to align on the convention to be used before starting a new project.
* ***Pascal casing:*** Every word in the function name starts with a capital letter, like `MultiplyNumbers()`.
* ***Camel casing:*** The first word in the variable name starts with a lowercase letter, like `firstNumber`.
* ***Hungarian notation:*** Wherein a variable name is prefixed with characters that explain the type of the variable, like `iFirstNumber`, where the prefix `i` stands for `integer`.

## Common Compiler-Supported C++ Variable Types
![From: Book C++ in One Hour a Day, Sams Teach Yourself(8th Edition)](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/variable_types.png)
* Sign Bit: 0: Indicates positive integer; 1: Indicates negative integer.
* You would use an **unsigned variable type** when you expect only positive values.

## Avoid Narrowing Conversion Errors by Using *List Initialization*
To use this feature, insert initialization values/variables within braces `{...}`.   
The list initialization syntax is as follows: 
```c++
int largeNum = 5000000;
short anotherNum{ largeNum }; // error! Amend types 
int anotherNum{ largeNum }; // OK!
float someFloat{ largeNum }; // error! An int may be narrowed 
float someFloat{ 5000000 }; // OK! 5000000 can be accomodated
```

## Automatic Type Inference Using `auto`
Compilers supporting C++11 and beyond give you the option of not having to explicitly specify the variable type when using the keyword `auto`.   
```c++
auto coinFlippedHeads = true;
```

 ## Using `typedef` to Substitute a Variable’s Type
 ```c++
 typedef unsigned int STRICTLY_POSITIVE_INTEGER;
 STRICTLY_POSITIVE_INTEGER numEggsInBasket = 4532;
 ```
 
## What Is a Constant?
Constants are like variables in C++ except that these cannot be changed. Similar to variables, constants also occupy space in the memory and have a name to identify the address where the space is reserved. However, the content of this space cannot be over- written. Constants in C++ can be:  
* Declaring Variables as Constants Using `const`  
```c++
const type-name constant-name = value;
```
* Constant Expressions Using `constexpr`
```c++
constexpr double GetPi() {return 22.0 / 7;}
```
One constexpr can use another:   
```c++
constexpr double TwicePi() {return 2 * GetPi();}
```
* Enumerations
There are situations where a particular variable should be allowed to accept only a certain set of values.  
```c++
enum RainbowColors {
  Violet = 0, // start from 0, you can change it to other number. 
  Indigo, 
  Blue, 
  Green, 
  Yellow, 
  Orange, 
  Red
};

RainbowColors MyFavoriteColor = Blue; // Initial value
```
The compiler converts the enumerator such as `Violet` and so on into `integers`.
* Defining Constants Using `#define` (But you should never use it)
`#define pi 3.14286`
