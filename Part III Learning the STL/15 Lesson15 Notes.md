# Lesson 15 - An Introduction to the Standard Template Library
The standard template library (STL) is a set of template classes and functions that supply the programmer with 
* Containers for storing information 
* Iterators for accessing the information stored 
* Algorithms for manipulating the content of the containers

# STL Containers
* Sequential containers
* Associative containers

## Sequential Containers
Sequential containers are those that store data in a sequential fashion, such as arrays and lists.   
Fast insertion time, but slow in find operations. 
* **`std::vector`** - Operates like a dynamic array and grows(add and remove) at the end.
* **`std::deque`** - Similar to `std::vector` except it allows grows(add and remove) at both sides.
* **`std::list`** - Operates like a doubly linked list.
* **`std::forward_list`** - Similar to a `std::list` except it allows you to iterate only in one direction.

## Associative Containers
Associative containers are those that store data in a sorted fashion — akin to a dictionary.  
Slow insertion time, but much fast in find operations.  
* **`std::set`** - Stores unique values sorted on insertion in a container.(O(log n))
* **`std::unordered_set`** - Stores unique values sorted on insertion in a container.(near O(1))
* **`std::map`** - Stores key-value pairs sorted by their unique keys in a container.(O(log n))
* **`std::unordered_map`** - Stores key-value pairs sorted by their unique keys in a container.(near O(1))
* **`std::multiset`** - Akin to a `set`, supports the ability to store multiple items having the same value; that is, the value doesn’t need to be unique.
* **`std::unordered_multiset`** - Akin to a `unordered_set`.
* **`std::multimap`** - Akin to a `map`. Additionally, supports the ability to store key-value pairs where keys don’t need to be unique.
* **`std::unordered_multimap`** - Akin to a unordered_map. Additionally,

## Container Adapters
*Container adapters* are variants of sequential and associative containers that have limited functionality and are intended to fulfill a particular purpose. 
* **`std::stack`** - Stores elements in a LIFO (last-in-first-out) fashion, allowing elements to be inserted (pushed) and removed (popped) at the top.
* **`std::queue`** - Stores elements in FIFO (first-in-first-out) fashion, allowing the first element to be removed in the order they’re inserted.
* **`std::priority_queue`** - Stores elements in a sorted order, such that the one whose value is evaluated to be the highest is always first in the queue.

# STL Iterators
The simplest example of an iterator is a pointer. Iterators in STL are template classes that in some ways are a generalization of pointers.
* **Input iterator** - One that can be dereferenced to reference an object. Read access only.
* **Output iterator** - One that allows the programmer to write to the collection. Write access only.
Further refined:  
* **Forward iterator** - A refinement of the input and output iterators allowing both input and output. Typically find use in a singly linked list.
* **Bidirectional iterator** - A refinement of the forward iterator that allow move backward. Typically find use in a doubly linked list.
* **Random access iterators** - A refinement over the concept of bidirectional iterators that allow addition and subtraction. Typically find use in an array.

# STL Algorithms
Finding, sorting, reversing, and the like are standard programming requirements that should not require the programmer to reinvent implementation to support.  
* **`std::find`**
* **`std::find_if`**
* **`std::reverse`**
* **`std::remove_if`**
* **`std::transform`**

# The Interaction between Containers and Algorithms Using Iterators
```c++
#include <vector>
#include <algorithm>

int main() {
  vector <int> intArray;
  
  intArray.push_back (50);
  intArray.push_back (100);
  intArray.push_back (2991);
  
  // Walk the vector and read values using an iterator
  vector<int>::interator arrIterator = intArray.begin();
  
  while(arrIterator != intArray.end()) {
    cout << *arrIterator << endl;
    ++arrIterator;
  }
  
  // Find an element (say 2991) using the 'find' algorithm
  vector <int>::iterator elFound = find (intArray.begin(), intArray.end(), 2991);
  // Check if value was found
  if (elFound != intArray.end ()) {
    // Determine position of element using std::distance
    int elPos = distance (intArray.begin (), elFound);
    cout << "Value "<< *elFound;
    cout << " found in the vector at position: " << elPos << endl;
  }
  return 0;
}
```
* function `begin()` points to the first element.
* function `end()` points to the end of the container after the last element.
* The result of the `find` operation is an iterator as well.

## Using Keyword `auto` to Let Compiler Define Type
Change:  
`vector <int>::iterator arrIterator = intArray.begin();`
To:  
`auto arrIterator = intArray.begin (); // compiler detects type`

## Choosing the Right Container
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/stl_container.png)

## STL String Classes
* **`std::string`** - A `char`-based specialization of `std::basic_string` used for the manipulation of simple character strings.
* **`std::wstring`** - A `wchar_t`-based specialization of `std::basic_string`...

