// alloc is SGI STL's allocator
template&lt;class T, class Alloc = alloc&gt;
class vector {
public:
    // vector's nested types
    typedef T           value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef value_type&amp; reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

protected:
    // simple_alloc is SGI STL's allocator
    typedef simple_alloc&lt;value_type, Alloc&gt; data_allocator; 
    iterator start;           // the head of the currently used memory space.
    iterator finish;          // the tail of the currently used memory space.
    iterator end_of_storage;  // the tail of the currently available memory space.
    
    void insert_aux(iterator position, const T&amp; x);
    void deallocate() {
        if(start)
            data_allocator::deallocate(start, end_of_storage - start);
    }
    
    void fill_initialize(size_type n, const T&amp; value) {
        start = allocate_and_fill(n, value);
        finish = start + n;
        end_of_storage = finish;
    }
    
public:
    iterator begin() {return start;}
    iterator end() {return finish;}
    size_type size() const {return size_type(end() - begin());}
    size_type capacity() const {return size_tyoe(end_of_storage - begin());}
    bool empty() const {return begin() == end();}
    reference operator[] (size_type n) {return *(begin() + n);}
    
    
}
