# Lesson 20 - STL Map Classes
Unlike in a vector where elements at a position can be replaced by another, elements in a map at a given position cannot be replaced by a new element of a different value. This is because the map would ideally like to have it placed in a possible different location in accordance with its value relative to those in the internal tree.

# An Introduction to STL Map Classes 
The `map` and `multimap` are key-value pair containers that allow for a lookup on the basis of a key.
To use class `std::map` or `std::multimap`, include header: `#include<map>`.  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/map.png)
The difference between the `map` and the `multimap` is that only the latter allows for duplicates, whereas the former can store only unique keys.

## Instantiating a Map
`map <keyType, valueType, Predicate=std::less <keyType>> mapObj;`  
`multimap <keyType, valueType, Predicate=std::less <keyType>> mmapObj;`  
```c++
std::map<int, string> mapIntToStr; 
std::multimap<int, string> mmapIntToStr;
```
If you want to change this behavior, you supply a predicate that is a `class` or a `struct` that implements `operator()`.
```c++
template<typename keyType>
struct ReverseSort {
  bool operator() (const keyType& key1, const keyType& key2) {
    return (key1 > key2);
  }
};

int main() {
  // map and multimap with a predicate that inverses sort order 
  map<int, string, ReverseSort<int>> mapIntToStr; 
}
```

## Inserting Elements in an STL `map` or `multimap` Using `insert()`
```c++
template <typename T>
void DisplayContents(const T& cont) {
  for (auto element = cont.cbegin(); element != cont.cend(); ++element) {
    // ->first to get key, ->second to get value.
    cout << element->first << " -> " << element->second << endl;
  }
}

// Insert key-value pairs into the map using value_type 
mapIntToStr.insert (map<int, string>::value_type(3, "Three"));

// insert pair of key and value using make_pair function 
mapIntToStr.insert (make_pair(-1, "Minus One"));

// directly supply a std::pair initialized to the key and value to be inserted
mapIntToStr.insert (pair<int, string>(1000, "One Thousand"));

// via subscript operator[]
mapIntToStr[1000000] = "One Million";

// instantiate a multimap as a copy of a map
std::multimap<int, std::string> mmapIntToStr(mapIntToStr.cbegin(), mapIntToStr.cend());
```
Using `typedef` for easy readability:  
```c++
typedef map <int, string> MAP_INT_STRING; 
typedef multimap <int, string> MMAP_INT_STRING;
```

## Finding Elements in an STL `map` Using `find()`
```c++
// multimap <int, string>::const_iterator pairFound = mapIntToStr.find(key);
auto pairFound = mapIntToStr.find(key);

// remember to check the iterator returned for success.
if (pairFound != mapIntToStr.end()) {
  // ...
}
```

