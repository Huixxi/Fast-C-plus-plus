# Lesson 25 - Working with Bit Flags Using STL  
Bits can be an efficient way of storing settings and flags.
* The `bitset` class
* The `vector<bool>`

# The bitset Class
`std::bitset` is the STL class designed for handling information in bits and bit flags. `std::bitset` is not an STL container class because it cannot resize itself.  
To use class `std::bitset`, include header: `#include <bitset>`

## Instantiating the `std::bitset`
```c++
std::bitset<4> fourBits;  // 4 bits initialized to 0000
std::bitset<5> fiveBits("10101");  // 5 bits 10101
std::bitset<6> sixBits(0b100001);  // C++14 binary literal
std::bitset<8> eightBits (255);  // 8 bits initialized to long int 255
std::bitset<8> eightBitsCopy(eightBits);
```
This number is fixed at compile time; it isn’t dynamic. You can’t insert more bits into a `bitset` like you did to a `vector`.
> The prefix `0b` or `0B` tells the compiler that the following digits are a binary representation of an integer. This literal is new to C++ and introduced in C++14.

## Useful Operators Featured in `std::bitset`
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/op_bitset.png)

## Member Functions of std::bitset
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/mfn_bitset.png)

# The `vector<bool>`
Just a `vector` of `boolean` type elements, besides the `vector<bool>` features the function `flip()` similar to the function of `bitset<>::flip()`.  
To use class `std::vector<bool>`, include header: `#include <vector>`.

## Instantiating the `vector<bool>`
```c++
vector<bool> boolFlags1;
vector<bool> boolFlags{ true, true, false };
vector<bool> boolFlags2 (10, true);
vector<bool> boolFlags2Copy (boolFlags2);
```
