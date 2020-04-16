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

___

## vector
**vector's source code: [stl_vector.h](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/Part%20X%20A%20Deep%20Understanding%20of%20STL/3.%20Sequence%20Containers/stl_vector.h)**  

**vector's iterator**  
`random_access_iteartor`

**vector's data structure**  
When adding a new element `s`, if exceed the current capacity, the capacity will be enlarged to its twice, if still not enough, then enlarge to enough capacity.(reallocate, element move, release original space, ...)  

**vector's construct and memory management: constructor, push_back**  

**vector's element operator: pop_back, erase, clear, insert**  


## list
**list's iterator**  
STL list is a double linked-list, so list's iterator is `bidirectional_iterator`.   

**list's data structure**   

**list's construct and memory management: constructor, push_back, insert**  

**list's element operator:push_front, push_back, erase, pop_front, pop_back, clear, remove, unique, splice, merge, reverse, sort**


## deque
deque can do `insert` and `remove` in O(1), and don't have `capacity` like vector, so don't have `reserve`.   

**deque's iterator**   
deque's iterator is much much complex than vector.  

**deque's central controller**  
deque is composed with several pieces of continuous spaces. It has a so called ***map***, which is a small piece of continuous space, each ***node*** in it is a pointer, that point to another larger piece of continuous space, called ***buffer***. So actually, the `value_type` of ***map*** is `T**`.  
```c++
template <class T, class Alloc = alloc, size_t BufSiz = 0>
class deque {
public:
    typedef T value_type;
    typedef value_type* pointer;
    ...
protected:
    typedef pointer* map_pointer;
    
protected:
    map_pointer map;
    size_type map_size;
    ...
}
```

## stack
stack don't have a iterator, it's a FILO container adapter, that you can only fetch the element from top, which means traverse is not allowed.  
```c++
template <class T, class Sequence = deque<T>> 

```

## queue
queue don't have a iterator, it's a FIFO container adapter.
```c++
template <class T, class Sequence = deque<T>> 

```

## heap(implicit representation)
heap don't have a iterator. It acts as `priority_queue`'s assistant. **binary max heap** is suit for `priority_queue`'s underlying mechanisms. **binary search tree** can also be its underlyint mechanisms but it's too complex to be implemented and **binary search tree** requires its input should has enough randomness. The complexity is better between `queue` and `binary search tree`.    

**binary heap** is a kind of **complete binary tree**. The way that use **array** to represent a **complete binary tree** is called **implicit representation**, but heap requires dynamic changing size, so vector is a better choice.   


**heap algorithm**  
* `push_heap` 
* `pop_heap`: put the largest element to its vector's tail.
* `sort_heap`: looping `pop_heap`.
* `make_heap`: turn a sequence data to a valid heap.


## priority_queue
```c++
template <class T, class Sequence = vector<T>, class Compare = less<typename Sequence::value_type>> 

```


## slist(single list)
slist's iterator is a `forward_iterator`






