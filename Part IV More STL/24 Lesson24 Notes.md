# Lesson 24 - Adaptive Containers: Stack and Queue
Such containers that internally use another and present a distinct behavior are called *adaptive containers*.

# Stacks
Stacks are LIFO (last-in-first-out) systems where elements can be inserted or removed at the top of the container.  
To use class `std::stack`, include header: `#include <stack>`
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/stacks.png)

## Instantiating the Stack 
`std::stack` is defined by some implementations of STL as
```c++
template < class elementType, class Container=deque<Type> > 
class stack;
```
So the instantiation of a stack of can be:
```c++
std::stack<int> numsInStack;
// uses a different underlying container
std::stack <double, vector <double>> doublesStackedInVec;
// copy from another stack
std::stack<int> numsInStackCopy(numsInStack);
```

## Member Functions of Stack 
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/mfn_stack.png)


## Queues 
Queues are FIFO (first-in-first-out) systems where elements can be inserted behind the previous one, and the one inserted first gets removed first.
To use class `std::queue`, include header: `#include <queue>`
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/queue.png)

## Instantiating the Queue 
`std::queue` is defined by some implementations of STL as
```c++
template < class elementType, class Container = deque<Type> > 
class queue;
```
So the instantiation of a queue of can be:
```c++
std::queue<int> numsInQ;
// uses a different underlying container
std::queue <double, list<double>> dblsInQInList;
// copy from another queue
std::queue<int> copyQ(numsInQ);
```

## Member Functions of Queue 
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/mfn_Q.png)


# Priority Queue
The `priority_queue` is different from the `queue` in that the element of the highest value (or the value deemed as highest by a binary predicate) is available at the front of the queue and **queue operations are restricted to the front**.

## Instantiating the priority_queue Class 
`std::priority_queue` class is defined as
```c++
template < class elementType, class Container=vector<Type>, class Compare=less<typename Container::value_type> >
class priority_queue
```
So the instantiation of a priority_queue of can be:
```c++
std::priority_queue<int> numsInPrioQ;
// create a priority queue containing elements of type double inside a std::deque:
priority_queue <int, deque<int>, greater<int>> numsInDescendingQ;
// copy from another queue
std::priority_queue<int> copyQ(numsInPrioQ);
```
> Includes standard header `<functional>` to use `std::greater<>`.

## Member Functions of priority_queue
The member functions `front()` and `back()`, available in the `queue`, are not available in the `priority_queue`.
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/mfn_priorQ.png)
