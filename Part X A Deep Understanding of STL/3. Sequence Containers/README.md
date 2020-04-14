## Sequence Containers
Any particular "Data Structures" is designed to implement a particular algorithm.   
Those "Data Sturctures" can be classified into: **sequence** and **associatice**.  
___

**Sequence Containers**  
* array (build-in)
* vector
  * heap (contains a vector)(in algorithm form)
    * priority_queue (contains a heap)
* list
* slist (non-std)
* deque 
  * stack (contains a deque)(adapter)
  * queue (contains a deque)(adapter)

**Associatice Containers**  
* RB-tree (non-public)
  * set (contains an RB-tree)
  * map (contains an RB-tree)
  * multiset (contains an RB-tree)
  * multimap (contains an RB-tree)
* hashtable (non-std)
  * hash_set (contains a hashtable)(non-std)
  * hash_map (contains a hashtable)(non-std)
  * hash_multiset (contains a hashtable)(non-std)
  * hash_multimap (contains a hashtable)(non-std)

___

### vector
**vector's source code: [stl_vector.h](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/Part%20X%20A%20Deep%20Understanding%20of%20STL/3.%20Sequence%20Containers/stl_vector.h)**  

**vector's data structure**  
When adding a new element `s`, if exceed the current capacity, the capacity will be enlarged to its twice, if still not enough, then enlarge to enough capacity.(reallocate, element move, release original space, ...)  

**vector's construct and memory management: constructor, push_back**  

**vector's element operator: pop_back, erase, clear, insert**  


### list

