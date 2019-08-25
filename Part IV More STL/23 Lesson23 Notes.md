# Lesson 23 - STL Algorithms
To use STL algorithms, the programmer first has to include the header `<algorithm>`.    
STL algorithms can be broadly classified into two types: 
* non-mutating algorithms.
* mutating algorithms.

## Non-Mutating Algorithms
*Non-mutating algorithms* are those that change neither the order nor the contents of a container are called.  
* *Counting Algorithms*:   
`count()`, `count_if()`
* *Search Algorithms*:   
`search()`, `search_n()`, `find()`, `find_if()`, `find_end()`, `find_first_of()`, `adjacent_find()`
* *Comparison Algorithms*:  
`equal()`, `mismatch()`, `lexicographical_compare()`

## Mutating Algorithms
*Mutating algorithms* are those that change the contents or the order of the sequence they are operating on.
* *Initialization Algorithms*:  
`fill()`, `fill_n()`, `generate()`, `generate_n()`
* *Modifying Algorithms*:  
`for_each()`, `transform()`
* *Copy Algorithms*:  
`copy()`, `copy_backward()`
* *Removal Algorithms*:  
`remove()`, `remove_if()`, `remove_copy()`, `remove_copy_if()`, `unique()`, `unique_copy()`
* *Replacement Algorithms*:   
`replace()`, `replace_if()`
* *Sort Algorithms*:  
`sort()`, `stable_sort()`, `partial_sort()`, `partial_sort_copy()`
* *Partitioning Algorithms*:  
`partition()`, `stable_partition()`  
* *Algorithms That Work on Sorted Containers*:  
`binary_search()`, `lower_bound()`, `upper_bound()`

# Usage of STL Algorithms
## Finding Elements Given a Value or a Condition
```c++
auto element = find(numsInVec.cbegin(), numsInVec.cend(), 
                    numToFind  // Element to find);

// Check if find() succeeded 
if (element != numsInVec.cend ()) 
  cout << "Result: Value found!" << endl;
```
```c++
auto element = find(numsInVec.cbegin(), numsInVec.cend(), 
                    [](int element) { return (element % 2) == 0; });

// Check if find() succeeded 
if (element != numsInVec.cend ()) 
  cout << "Result: Value found!" << endl;
```

## Counting Elements Given a Value or a Condition
`size_t numZeroes = count (numsInVec.cbegin (), numsInVec.cend (), 0);`  
`size_t numEvenNums = count_if (numsInVec.cbegin (), numsInVec.cend (), IsEven <int> );`  

## Searching for an Element or a Range in a Collection Listing
`search()` can be used to check if one range is contained in another:
```c++
auto range = search(numsInVec.cbegin(), // Start range to search in 
                    numsInVec.cend(), // End range to search in 
                    numsInList.cbegin(), // start range to search 
                    numsInList.cend() ); // End range to search for
```
`search_n()` can be used to check if `n` instances of a value placed consequently are to be found in a container:
```c++
// find the first occurrence of series {9, 9, 9} in the vector.
auto partialRange = search_n(numsInVec.cbegin(), // Start range 
                             numsInVec.cend(), // End range 
                             3, // num items to be searched for 
                             9); // value to search for
```

## Initializing Elements in a Container to a Specific Value
`fill()` is used to overwrite the elements in a range given the bounds of the range and the value to be inserted:
```c++
vector <int> numsInVec (3);  // {0, 0, 0}
// fill all elements in the container with value 9 
fill(numsInVec.begin (), numsInVec.end (), 9);  // now {9, 9, 9}
```
`fill_n()` resets a specified n number of values:
```c++
numsInVec.resize(6);
fill_n(numsInVec.begin() + 3, /*count*/ 3, /*fill value*/ -9);
```

## Using `std::generate()` to Initialize Elements to a Value Generated at Runtime
`generate()` is used to fill a range using the return value of a generator function:
```c++
generate(numsInVec.begin(), numsInVec.end(),  // range 
         rand);  // generator function
         
generate_n (numsInList.begin (), 5, rand);
```

## Processing Elements in a Range Using `for_each()`
The `for_each()` algorithm applies a specified unary function object to every element in the supplied range. 
```
fnObjType retValue = for_each(start_of_range, 
                              end_of_range,
                              unaryFunctionObject); 
```

## Performing Transformations on a Range Using `std::transform()`
The first version accepts a unary function and is popularly used to convert a string to upper- or lowercase using functions `toupper()` or `tolower()`: 
```c++
string str ("THIS is a TEst string!"); 
transform(str.cbegin(),  // start source range 
          str.cend(),  // end source range
          strLowerCaseCopy.begin(),  // start destination range 
          ::tolower);  // unary function
```
The second version accepts a binary function allowing `transform()` to process a pair of elements taken from two different ranges:
```c++
// sum elements from two vectors and store result in a deque 
transform(numsInVec1.cbegin(),  // start of source range 1 
          numsInVec1.cend(),  // end of source range 1
          numsInVec2.cbegin(),  // start of source range 2 
          sumInDeque.begin(),  // store result in a deque 
          plus<int>());  // binary function plus
```

## Copy and Remove Operations
`copy()` can assign the contents of a source range into a destination range in the forward direction:
```c++
auto lastElement = copy(numsInList.cbegin(),  // start source range
                        numsInList.cend(),  // end source range
                        numsInVec.begin());  // start dest range
```
`copy_if()` can copies an element when a unary predicate supplied by you returns `true`: 
```c++
// copy odd numbers from list into vector 
copy_if(numsInList.cbegin(), numsInList.cend(), 
        lastElement, // copy position in dest range 
        [](int element){ return ((element % 2) == 1);});
```
`copy_backward()` assigns the contents to the destination range in the backward direction:
```c++
copy_backward(numsInList.cbegin(), 
              numsInList.cend(), 
              numsInVec.end());
```
`remove()` deletes elements in a container that matches a specified value:
```c++
// Remove all instances of '0', 
resize vector using erase() 
auto newEnd = remove(numsInVec.begin (), numsInVec.end (), 0); 
numsInVec.erase (newEnd, numsInVec.end());
```
`remove_if()` uses a unary predicate and removes from the container those elements for which the predicate evaluates to `true`:
```c++
// Remove all odd numbers from the vector using remove_if 
newEnd = remove_if(numsInVec.begin(), numsInVec.end(), 
                   [](int num) {return ((num % 2) == 1);} );  //predicate
numsInVec.erase (newEnd, numsInVec.end());  // resizing
```
> `remove()` and `remove_if()` return an iterator that points to the new end of the container.

## Replacing Values and Replacing Element Given a Condition
`replace()` replaces elements based on the return value of the comparison `operator (==)`: 
```c++
// "Using 'std::replace' to replace value 5 by 8" 
replace(numsInVec.begin(), numsInVec.end(), 5, 8);
```
`replace_if()` expects a user-specified unary predicate that returns true for every value that needs to be replaced:
```c++
// "Using 'std::replace_if' to replace even values by -1" 
replace_if(numsInVec.begin(), numsInVec.end(), 
           [](int element) { return ((element % 2) == 0); }, -1);
```

## Sorting and Searching in a Sorted Collection and Erasing Duplicates Sorting
`sort(numsInVec.begin(), numsInVec.end());  // ascending order`    
`sort(numsInVec.begin(), numsInVec.end(), [](int lhs, int rhs) { return (lhs > rhs); });  // descending order`   
To remove adjacently placed repeating values, use algorithm `unique()`:  
```c++
auto newEnd = unique(numsInVec.begin(), numsInVec.end()); 
numsInVec.erase(newEnd, numsInVec.end());  // to resize
```
To search fast, STL provides you with `binary_search()` that is effective only on a sorted container:  
```c++
bool elementFound = binary_search(numsInVec.begin(), numsInVec.end(), 2011); 
if(elementFound)
  cout << "Element found in the vector!" << endl;
```
> `stable_sort()` ensures that the relative order of the sorted elements is maintained. Maintaining relative order comes at the cost of performance.

## Partitioning a Range `std::partition()`
`std::partition()` helps partition an input range into two sections: one that satisfies a unary predicate and another that doesn’t:
```c++
vector<int> numsInVec{ 2017, 0, -1, 42, 10101, 25 };
partition(numsInVec.begin(), numsInVec.end(), IsEven);  // now { 42 0 /*two parts*/ -1 2017 10101 25 }
```
> `stable_partition()` is slower than `partition()`

## Inserting Elements in a Sorted Collection
`lower_bound()` and `upper_bound()` return iterators pointing to the minimal and the maximal positions in a sorted range where an element can be inserted without breaking the order of the sort.
```c++
auto minInsertPos = lower_bound (names.begin(), names.end(), "Brad Pitt");
// alternatively:
auto maxInsertPos = upper_bound (names.begin(), names.end(), "Brad Pitt");
```

