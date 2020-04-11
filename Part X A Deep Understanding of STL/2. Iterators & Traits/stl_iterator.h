// 5 iterator types
struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : bidirectional_iterator_tag { };

// stl::iterator class
template <class Category, 
          class T, 
          class Distance = ptrdiff_t, 
          class Pointer = T*, 
          class Reference = T&>
struct iterator {
    typedef Category iterator_category; 
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer; 
    typedef Reference reference;
};

// traits
template <class I>
struct iterator_traits {
    typedef typename I::intertor_category iterator_category;
    typedef typename I::value_type        value_type;
    typedef typename I::difference_type   difference_type;
    typedef typename I::pointer           pointer;
    typedef typename I::reference         reference;
};

// traits for "navie pointer"
template <class T>
struct iterator_traits<T*> {
    typedef random_access_iterator_tag    iterator_category;
    typedef T                             value_type;
    typedef ptrdiff_t                     difference_type;
    typedef T*                            pointer;
    typedef T&                            reference;
};

// traits for "pointer-to"
template <class T>
struct iterator_traits<const T*> {
    typedef random_access_iterator_tag    iterator_category;
    typedef T                             value_type;
    typedef ptrdiff_t                     difference_type;
    typedef const T*                      pointer;
    typedef const T&                      reference;
};

// judge iterator's category
template<class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&) {
    typedef typename iterator_traits<Iterator>::intertor_category category;
    return category();
}

// judge iterator's distance type
template<class Iterator>
inline typename iterator_traits<Iterator>::difference_type*
distance_type(const Iterator&) {
    return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
}

// judge iterator's value type
template<class Iterator>
inline typename iterator_traits<Iterator>::value_type*
value_type(const Iterator&) {
    return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
}

// distance()
template <class InputIterator>
inline iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, input_iterator_tag) {
    iterator_traits<InputIterator>::difference_type n = 0;
    while(first != last) {
        ++first;
        ++n;
    }
    return n;
}

template <class RandomAccessIterator>
inline iterator_traits<RandomAccessIterator>::difference_type
__distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag) {
    return first - last;
}

template <class InputIterator>
inline iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last) {
    typedef typename iterator_traits<InputIterator>::intertor_category category;
    return __distance(first, last, category());
}

// advance()
template <class InputIterator, class Distance>
inline void __advance(InputIterator& i, Distance n, input_iterator_tag) {
    while(n--) 
        ++i;
}

template <class BidirectionalIterator, class Distance>
inline void __advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag) {
    if(n >= 0)
        while(n--) ++i;
    else
        while(n++) --i;
}

template <class RandomAccessIterator, class Distance>
inline void __advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag) {
    i += n;
}

template <class InputIterator, class Distance>
inline void advance(InputIterator& i, Distance n) {
    __advance(i, n, iterator_traits<InputIterator>::intertor_category());
}


