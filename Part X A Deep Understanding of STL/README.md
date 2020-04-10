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
```c++
// iterator for List
template <class Item>
struct ListIter {
    Item* ptr;  // Keep a reference to Container.
    
    ListIter(Item* p = 0) : ptr(p) {};
    
    Item& operator*() const {return *ptr};
    Item* operator->() const {return ptr};
    
    // pre-increment operator
    ListIter& operator++() {
        ptr = ptr->next;
        return ptr;
    }
    
    // post-increment operator
    ListIter operator++(int) {
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }
    
    bool operator==(const ListIter& i) const {
        return ptr == i.ptr;
    }
    
    bool operator!=() const {
        return ptr != i.ptr;
    }
}
```
Each STL container has its own iterator.  

**2.3** Iterators' associated types  
Utilize fucntion template's arugment deducation to solve.  

**2.4** Traits  
**template partial specialization**
```c++
template <class I>
struct iterator_traits {
    typedef typename I::intertor_category iterator_category;
    typedef typename I::value_type value_type;
    typedef typename I::difference_type difference_type;
    typedef typename I::pointer pointer;
    typedef typename I::reference reference;
}
```
* `value_type`
* `difference_type`  
Which is used to represent the distance of two iterators, so it can be used to represent a container's largest size, like STL's `count()`.(Also should "partial specialization" for "naive pointers" and "pointer-to-const".)  
> 
```c++
    template <class I, class T>
    typename iterator_traits<I>::difference_type count(I first, I last, const T* value) {
        typename iterator_traits<I>::difference_type n = 0;
        for(; first != last; ++first) 
            if(*first == value)
                ++n;
        return n;
    }
```

* `reference_type`  
There are two kinds of iterators: constant iterators, e.g. `const int* pic` & mutable iterators, e.g. `int* pi`.   
> 
```c++
    int* pi = new int(5);
    const int* pic = new int(9);
    *pi = 7;  // *pi is a lvalue, allowed assignment.
    *pic = 1;  // *pic is a rvalue, don't allow assignment.
```

* `pointer_type`
```c++
    Item& operator*() const {return *ptr};  // Item& is ListIter's reference type
    Item* operator->() const {return ptr};  // Item* is ListIter's pointer type
```

* `iterator_category`
  * Input Iterator (read only)
  * Output Iterator (write only)
  * Forward Iterator (allow operations like `replace()`
  * Bidirectional Iterator (can bidirectionally move)
  * Random Access Iterator (covers pointer's all arithmetic abilities, like `p+n, p-n, p[n], p1-p2, p1<p2`

