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
You can initialize it directly with:  
```c++
mapIntToStr = {{1, "String1"}, {2, "String2"}, {3, "String3"}}
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

## Finding Elements in an STL `multimap`
In the case of a `multiset` you would use `multiset::count()` to find the number of values corresponding to a key and increment the iterator to access those consequently placed values.
```c++
auto pairFound = mmapIntToStr.find(key);
// Check if find() succeeded 
if(pairFound != mmapIntToStr.end()) {
  // Find the number of pairs that have the same supplied key 
  size_t numPairsInMap = mmapIntToStr.count(key);
  for(size_t counter = 0; counter < numPairsInMap; ++counter) {
    cout << "Key: " << pairFound->first;  // key 
    cout << ", Value [" << counter << "] = "; 
    cout << pairFound->second << endl;  // value 
    ++pairFound;   
  } 
} 
else 
  cout << "Element not found in the multimap";
```

## Erasing Elements from an STL `map` or `multimap`
```c++
multimap<int, string> mmapIntToStr;
mmapIntToStr.insert(make_pair(1000, "Thousand"));
mmapIntToStr.insert(make_pair(45, "Forty Five"));
mmapIntToStr.insert(make_pair(-1, "Minus One"));
mmapIntToStr.insert(make_pair(1000, "Thousand"));

// Erasing an element with key as -1 from the multimap
auto numPairsErased = mmapIntToStr.erase(-1);

// Erase an element given an iterator from the multimap
auto pair = mmapIntToStr.find(45);
if(pair != mmapIntToStr.end()) {
  mmapIntToStr.erase(pair);
}
// Erase a range from the multimap...
mmapIntToStr.erase(mmapIntToStr.lower_bound(1000), mmapIntToStr.upper_bound(1000));
```

## Supplying a Custom Sort Predicate
To supply a different sort criterion than what the key-type supports, you would typically program a binary predicate in the form of a `class` or a `struct` using `operator()`:
```c++
template<typename keyType> 
struct Predicate {
  bool operator()(const keyType& key1, const keyType& key2) {
    // your sort priority logic here 
  }
};
```

# STL’s Hash Table-Based Key-Value Container
The Hash Table is one such container that promises constant-time insertions and near-constant–time searches (in most cases), given a key.  
To use class `std::unordered_map`, include header: `#include<unordered_map>`  

## How Hash Tables Work
A hash table can be viewed as a collection of key-value pairs, where given a key, the table can find a value. A hash table stores key-value pairs in **buckets**, each bucket having an index that defines its relative position in the table.  
`Index = HashFunction(key, TableSize);`  
When performing a `find()` given a key, `HashFunction()` is used once again to determine the position of the element and the table returns the value at the position.

## Using `unordered_map` and `unordered_multimap`
Not too different from `std::map` and `std::multimap`, respectively. *Instantiation*, *insertion*, and *find* follow similar patterns. Yet, one important feature of an `unordered_map` is the availability of a hash function that is responsible for deciding the sorting order:  
`unordered_map<int, string>::hasher hFn = umapIntToStr.hash_function();`  
You can view the priority assigned to a key by invoking the hash function for a key:   
`size_t hashingVal = hFn(1000);  // 1000 is a key`  
As an unordered_map stores key-value pairs in buckets, it does an automatic **load balancing** when the number of elements in the map reach or tend to reach the number of buckets in the same:  
```
cout << "Load factor: " << umapIntToStr.load_factor() << endl; 
cout << "Max load factor = " << umapIntToStr.max_load_factor() << endl; 
cout << "Max bucket count = " << umapIntToStr.max_bucket_count() << endl;
```
> `load_factor()` is an indicator of the extent to which buckets in the `unordered_map` have been filled. When `load_factor()` exceeds `max_load_factor()` due to an insertion, the map reorganizes itself to increase the number of available buckets and rebuilds the hash table.

## Tips
* DO use an `unordered_map` or `unordered_multimap` when constant-time insertions and searches are absolutely essential (typically when the number of elements is very high).



