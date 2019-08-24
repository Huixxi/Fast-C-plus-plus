# Lesson 23 - STL Algorithms
To use STL algorithms, the programmer first has to include the header `<algorithm>`.    
STL algorithms can be broadly classified into two types: 
* non-mutating 
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

