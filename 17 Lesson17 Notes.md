# Lesson 17 - STL Dynamic Array Classes

# `std::vector`
To use class `std::vector`, include header: `#include <vector>`.  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/vector.png)

## Instantiating a Vector
`std::vector<dataType> vectorName;`  
```c++
std::vector<int> integers;

// std::vector<int> initVector = { 202, 2017, -1 };
std::vector<int> initVector{ 202, 2017, -1 };  // list initialization

// Instantiate a vector with 10 default elements 0 (it can still grow)
std::vector<int> tenElements (10);

// Instantiate a vector with 10 elements, each initialized to 90
std::vector<int> tenElemInit (10, 90);

// Initialize vector to the contents of another
std::vector<int> copyVector (tenElemInit);

// Vector initialized to 5 elements from another using iterators
std::vector<int> partialCopy (tenElements.cbegin(), tenElements.cbegin() + 5);
```

