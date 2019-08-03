# Lesson 4 - Managing Arrays and Strings
## Declaring and Initializing Static Arrays
`ElementType ArrayName [constant_number of elements] = {optional initial values};`  

**Examples:**  
```c++ 
int myNumbers [5] = {34, 56, -21, 5002, 365};

int myNumbers [5] = {}; // initializes all integers to 0

int myNumbers [5] = {34, 56};  // initialize first two elements to 34 and 56 and the rest to 0

const int ARRAY_LENGTH = 5;
int myNumbers [ARRAY_LENGTH] = {34, 56, -21, 5002, 365};

int myNumbers [] = {2016, 2052, -525}; // array of 3 elements
```
**Do** always initialize arrays, or else they will contain junk values.

## How Data Is Stored in an Array
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/array.png)
In general, the amount of memory reserved by the compiler for an array in bytes is:  
`Bytes consumed by an array = sizeof(element-type) * Number of Elements`

## Accessing and Modifying Data Stored in an Array
```c++
int myNumbers [5] = {34, 56, -21, 5002, 365};
// Accessing
cout << myNumbers[0];  // index start from 0 to N-1
// Modifying
myNumbers [3] = 2016;
```
**Fence-Post Error:**  
It’s named after the fact that the number of posts needed to build a fence is always one more than the number of sections in the fence. You must make sure that the index is not beyond the length of array minus 1.

## Multidimensional Arrays
```c++
int solarPanels [2][3] = {{0, 1, 2}, {3, 4, 5}};
cout << solarPanels[0][2];  // row 1, column 3 --> 2
```

## Dynamic Arrays - `std::vector`
```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> dynArray (3);  // dynamic array of int
  
  dynArray[0] = 365;
  dynArray[1] = -421;
  dynArray[2] = 789;
  // ...
}
```

## C-style Character Strings
```c++
std::cout << "Hello World"; 

char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
std::cout << sayHello << std::endl;
```
C-style strings are a special case of character arrays in that the last character always precedes the null-terminator `'\0'`. 
`'\0'` is called the string-terminating character.   
If you inserted `'\0'` anywhere in the middle of the array, it would not change the size of the array; it would only mean that string-processing using the array as input would stop at that point.   

## C++ Strings: Using `std::string`
```c++
#include <iostream> 
#include <string> 

using namespace std;

int main(){
  string greetString ("Hello std::string!");  // Initialization
  cout << greetString << endl;
  cout << greetString.length() << endl;
  \\ ...
}
```



