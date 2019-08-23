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

## Inserting Elements at the End Using `push_back()`
```c++
vector <int> integers;
integers.push_back (50);
```

## Inserting Elements at a Given Position Using `insert()`
```c++
// insert an element at the beginning 
integers.insert (integers.begin (), 25);

// Insert 2 elements of value 45 at the end 
integers.insert (integers.end (), 2, 45);

vector<int> another (2, 30);
// Insert two elements from another container in position [1]
integers.insert (integers.begin () + 1, another.begin (), another.end ());
```
> **Note:**  
`push_back()` should be your preferred way of adding elements to a vector. `vector::insert()` makes the vector class shift all subsequent elements backward, and the cost of this shift operation can be significant in terms of the copy constructor or copy assign- ment operator invoked. If your container needs to have very frequent insertions in the middle, you should ideally choose the `std::list`, linked list.

## Accessing Elements in a Vector Using Array Semantics
Elements in a vector can be accessed using the following methods:   
* using array semantics using the subscript operator (`[]`)
* using the member function `at()`
* using iterators
```c++
std::vector<int> tenElements(10);
tenElements[3] = 2011; // set 4th element
```
> **Note:**  
You should also not cross the bounds of the container. A safer alternative is to use the `at()` member function:  
`// gets element at position 2`    
`cout << integers.at (2);`  
`at()` performs a runtime check against the `size()` of the container and throws an exception if you cross the boundaries.

## Accessing Elements in a Vector Using Pointer Semantics(Iterators)
```c++
auto element = integers.cbegin();  // a const_iterator, different from .begin() which is just a iterator
// vector<int>::const_iterator element = integers.cbegin ();

while(element != integers.end()) {
  size_t index = distance (integers.cbegin (), element);
  cout << *element << endl;
  ++element;
} 
```
> **Understand `const_iterator`**  
In the above example, `element` is a `const_iterator`, you can see that, `++element;` is allowed, but if you try `++(*element)`, it will cause an error, which means it's not allowed to change the value that `element` points to.

## Removing Elements from a Vector Using `pop_back()`
```c++
// Erase one element at the end
integers.pop_back();
```

## Understanding the Concepts of Size and Capacity
`cout << "Size: " << integers.size ();`  
`cout << "Capacity: " << integers.capacity () << endl;`  
A `vector` can cause some amount of performance problems when it needs to frequently reallocate the memory of the internal dynamic array. To a great extent, this problem can be addressed by using the member function `reserve(number)` which increases the amount of memory allocated for the vector’s internal array so as to accommodate the number of elements without needing to reallocate. In `vector`, there is a *preemptive increase* mechanism.

# The STL `deque` Class deque
`deque` (pronunciation rhymes with *deck*) is an STL dynamic array class which also allows insertion and removal of elements at the front and back of the array.  
To use a `std::deque`, include header `<deque>`: `#include<deque>`  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/deque.png)
```c++
deque<int> intDeque;
// Insert integers at the top of the array
intDeque.push_back(2);
intDeque.pop_back();
intDeque.push_front(2);
intDeque.pop_front();
```
