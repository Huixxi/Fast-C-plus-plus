# Lesson 19 - STL Set Classes
The `std::set` and `std::multiset` are used to contain a sorted set of elements and offer you the ability to find elements given a ***logarithmic complexity***. Their unordered counterparts offer ***constant-time*** insertion and search capabilities.

# An Introduction to STL Set Classes 
To use class `std::set` or `std::multiset`, include header: `#include <set>`
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/set.png)
The difference between the `set` and the `multiset` is that the latter allows for duplicates whereas the former can store only unique values.   
To facilitate quick searching, STL implementations of the `set` and `multiset` internally look like a ***binary tree***.

## Instantiating a Set
`std::set<dataType> setName;`  
`std::multiset<dataType> multisetName;` 
```c++
std::multiset<int> msetInts{ 43, 78, -1, 124, -1 };
msetInts.insert(-1);
cout << msetInts.count(-1);  // 3
```
Given that both `set` and `multiset` are containers that sort elements on insertion, they use a default predicate `std::less` when you don’t supply a sort criteria.  
You create a binary sort predicate by defining a class with `operator()` that takes two values of the type contained in the set as input and returns `true` depending on your criteria. One such sort predicate that sorts in descending order is the following:
```c++
// used as a template parameter in set / multiset instantiation 
template <typename T> 
struct SortDescending {
  bool operator()(const T& lhs, const T& rhs) const {
    return (lhs > rhs); 
  }
};

// a set and multiset of integers (using sort predicate) 
set <int, SortDescending<int>> setInts; 
multiset <int, SortDescending<int>> msetInts;
```

## Inserting Elements in a `set` or `multiset` Using `insert()`
`setInts.insert (-1);`  
`msetInts.insert (setInts.begin (), setInts.end ());`

## Finding Elements in an STL `set` or `multiset` Using `find()`
```c++
auto elementFound = setInts.find (-1);
// Check if found... 
if(elementFound != setInts.end ()) 
  cout << "Element " << *elementFound << " found!" << endl; 
else 
  cout << "Element not found in set!" << endl;
```

## Erasing Elements in an STL `set` or `multiset` Using `erase()`
`setObject.erase (element);`    
`setObject.erase (iLowerBound, iUpperBound);  // using iterators` 

## Pros and Cons of Using STL `set` and `multiset`
Quicker to locate element. But the container needs to sort elements at insertion time.   
`find()` makes use of the internal binary tree structure. overwriting an element using an iterator should never be done.

## STL Hash Set Implementation `std::unordered_set` and `std::unordered_multiset`
Elements inserted into a hash set are first evaluated by a hash function that generates a unique index, which is the index of the *bucket* they’re placed in.  
To use STL containers `std::unordered_set` or `std::unordered_ multiset`, include `#include<unordered_set>`  
The usage of this class doesn’t change too much in comparison to a `std::set`:   
```c++
// instantiation:
unordered_set<int> usetInt;

// insertion of an element 
usetInt.insert(1000); 

// find():
auto elementFound = usetInt.find(1000);
if (elementFound != usetInt.end()) 
  cout << *elementFound << endl;
```
Yet, one very important feature of an unordered_set is the availability of a hash func- tion that is responsible for deciding the sorting order:  
`unordered_set<int>::hasher HFn = usetInt.hash_function();`

