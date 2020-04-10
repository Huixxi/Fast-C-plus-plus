## STL Source Code Dissect

### 1. Allocator

### 2. Iterators & Traits
**2.1** STL separate **containers** and **algorithms**, and implements with **class templates** and **functions templates**.  
```c++
// find() fucntion in <algorithm>
template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& value) {
    while(first != last && *fisrt != value) 
        ++first;
    return first;
}
```

**2.2** Iterator is a **smart pointer**
The most important thing for **Iterators** is **overloading** the `operator*` and `operator->`
