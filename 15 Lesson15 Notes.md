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
* 


