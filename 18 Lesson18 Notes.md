# Lesson 18 - STL `list` and `forward_list`
The main advantage of a linked list is in fast and constant time insertion and removal of elements.
* **`std::list`** - A doubly linked list 
* **`std::forward_list`** - A singly linked list 

# `std::list`
A `linked list` is a collection of nodes in which each node, in addition to containing a value or object of interest, also points to the next node; that is, each node links to the next one and previous one.  
To use class `std::list`, include header: `#include <list>`
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/list.png)

## Instantiating a List
`std::list<dataType> listName;`
```c++
std::list<int> linkInts;

// instantiate a list with 10 integers
std::list<int> listWith10Integers(10);

// instantiate a list with 4 integers, each value 99
std::list<int> listWith4IntegerEach99 (10, 99);

// create an exact copy of an existing list
std::list<int> listCopyAnother(listWith4IntegerEach99);

// a vector with 10 integers, each 2017
std::vector<int> vecIntegers(10, 2017);

// instantiate a list using values from another container
std::list<int> listContainsCopyOfAnother(vecIntegers.cbegin(), vecIntegers.cend());
```

## Inserting Elements at the Front or Back of the List
Similar to a `deque`:  
`linkInts.push_back (-1);`   
`linkInts.push_front (2001);` 
```c++
template <typename T>
void DisplayContents (const T& container) {
  for(auto element = container.cbegin(); element != container.cend(); ++element)
    cout << *element << ' ';
  cout << endl;
}

int main() {
  std::list<int> linkInts{ -101, 42 };
  linkInts.push_front(2011);
  linkInts.push_back(-1);
  DisplayContents(linkInts);
  return 0;
}
```

## Inserting at the Middle of the List
The `list::insert()` member function is available in three forms:
* `iterator insert(iterator pos, const T& x)`  
'This function returns an iterator pointing to the recently inserted element in the list.'
* `void insert(iterator pos, size_type n, const T& x)`  
'Variable `n` is the number of elements.'
* `template <class InputIterator>`  
  `void insert(iterator pos, InputIterator f, InputIterator l)`  
'Two input iterators that mark the bounds of the collection to insert into the list.'

```c++
std::list<int> linkInts1;

// Inserting elements at the beginning...
linkInts1.insert(linkInts1.begin(), 2);
// Inserting an element at the end...
linkInts1.insert(linkInts1.end(), 3);

// Inserting 4 elements of the same value 0... 
linkInts2.insert(linkInts2.begin(), 4, 0);

// Inserting elements from another list at the beginning...
std::list<int> linkInts3;
linkInts3.insert(linkInts3.begin(), linkInts1.begin(), linkInts1.end());
```

## Erasing Elements from the List
The list member function `erase()` comes in two overloaded forms: 
* erases one element given an iterator that points to it 
* accepts a range and therefore erases a range of elements from the list.
```c++
std::list<int> linkInts{ 4, 3, 5, -1, 2017 };
// Store an iterator obtained in using insert()
auto val2 = linkInts.insert(linkInts.begin(), 2);
linkInts.erase(val2);
linkInts.erase(linkInts.begin(), linkInts.end());
```
> The same, if you want to delete all elements of the container, you should use member function `clear()`:  
`linkInts.clear();`

# Reversing and Sorting Elements in a List
`list` has a special property that iterators pointing to the elements in a `list` remain valid in spite of rearrangement of the elements or insertion of new elements and so on.

## Reversing Elements Using `list::reverse()`
`linkInts.reverse(); // reverse order of elements`

## Sorting Elements Using `list::sort()`
`linkInts.sort(); // sort in ascending order`  
Define your own sort priorities via a binary predicate function as a parameter:  
```c++
bool SortPredicate_Descending(const int& lhs, const int& rhs) {
  // define criteria for list::sort: return true for desired order 
  return (lhs > rhs);
}
// Use predicate to sort a list: 
linkInts.sort(SortPredicate_Descending);
```

## Sorting and Removing Elements from a `list` That Contains Instances of a `class`
Most practical applications involving STL containers rarely collect integers; instead, they collect user-defined types such as `classes` or `structs`.
How would you ensure that this list is sorted on name?  
The answer is one of the following: 
* Implement `operator <` within the class type that the list contains.
* Supply a sort binary predicate - a function that takes two values as input and returns a Boolean value indicating whether the first value is smaller than the second.

```c++
struct ContactItem { 
  string name;
  string phone;
  string displayAs;
  ContactItem (const string& conName, const string & conNum) {
    name = conName;
    phone = conNum;
    displayAs = (name + ": " + phone); 
  }

  // used by list::remove() given contact list item 
  bool operator == (const ContactItem& itemToCompare) const {
    return (itemToCompare.name == this->name);
  }

  // used by list::sort() without parameters
  bool operator < (const ContactItem& itemToCompare) const {
    return (this->name < itemToCompare.name); 
  }

  // Used in displayAsContents via cout
  operator const char*() const {
    return displayAs.c_str(); 
  }
};

bool SortOnphoneNumber (const ContactItem& item1, const ContactItem& item2) {
  return (item1.phone < item2.phone);
}
```

## `std::forward_list` Introduced in C++11
To use a `std::forward_list`, you need to include header: `#include<forward_list>`
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/forward_list.png)
You can only use `push_front()` to insert elements now, no `push_back()`. Of course, you can always use `insert()`.
```c++
forward_list<int> flistIntegers{ 3, 4, 2, 2, 0 };
flistIntegers.push_front(1);  // { 1, 3, 4, 2, 2, 0 }
flistIntegers.remove(2);  // { 1, 3, 4, 0 }
flistIntegers.sort();  // { 0, 1, 3, 4 }
```

## Tips
* DO remember to program `operator<` and `operator==` in a class that will be collected in a STL container such as `list` to supply the default sort or remove predicate.
* DON’T use a `list` when you have infrequent insertions or deletions at the ends and no insertions or deletions in the middle; `vector` or `deque` can be significantly faster in these cases.

