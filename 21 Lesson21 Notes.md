# Lesson 21 - Understanding Function Objects

## The Concept of Function Objects and Predicates
On a conceptual level, function objects are objects that work as functions.   
On an implementation level, however, function objects are objects of a class that implement `operator()`.
* **Unary function** - A function called with one argument; for example, `f(x)`. When a unary function returns a `bool`, it is called a *predicate*.
* **Binary function** - A function called with two arguments; for example, `f(x, y)`. A binary function that returns a `bool` is called a *binary predicate*.

Function objects that return a `boolean` type are naturally suited for use in algorithms that help in **decision making**.  
A function object that combines two function objects is called an *adaptive function object*.

## Unary Functions
```c++
// A unary function
template <typename elementType>
void FuncDisplayElement(const elementType& element) {
  cout << element << ' '; 
};
```
The same function can also have another representation in which the implementation of the function is actually contained by the `operator()` of a `class` or a `struct`:   
```c++
// Struct that can behave as a unary function 
template <typename elementType> 
struct DisplayElement {
  void operator () (const elementType& element) const {
    cout << element << ' '; 
  }
};
```
Used with the STL algorithm `for_each()`: 
```c++
std::list<char> charsInList{ 'a', 'z', 'k', 'd' };
for_each(charsInList.begin(),
         charsInList.end(),
         FuncDisplayElement<char>);
// Or
for_each(charsInList.begin(),
         charsInList.end(),
         DisplayElement<char>());
```
The real advantage of using a function object implemented in a `struct` becomes apparent when you are able to use the object of the `struct` to store information.
```c++
template <typename elementType> 
struct DisplayElementKeepCount {
  int count;
  DisplayElementKeepCount() : count(0) {}   // constructor
  void operator () (const elementType& element) {
    ++count; 
    cout << element << ' '; 
  }
};

int main() {
  // ...
  result = for_each(charsInList.begin(),
                    charsInList.end(),
                    DisplayElementKeepCount<char>());
  cout << result.count << endl;
}
```

## Unary Predicate 
A unary function that returns a `bool` is a `predicate`. Such functions help make decisions for STL algorithms.
```c++
// A structure as a unary predicate
template <typename numberType> 
struct IsMultiple {
  numberType Divisor;
  IsMultiple(const numberType& divisor) : Divisor(divisor) {}   // constructor
  
  bool operator () (const numberType& element) const {
    // Check if the divisor is a multiple of the divisor
    return ((element % Divisor) == 0);
  }
};

int main() {
  vector<int> numsInVec{ 25, 26, 27, 28, 29, 30, 31 };
  int divisor = 2;
  // Find the first element that is a multiple of divisor
  auto element = find_if(numsInVec.begin(), 
                         numsInVec.end(), 
                         IsMultiple<int>(divisor));
  // always remember to verify that an element was found
  if (element != numsInVec.end()) {
    cout << *element << endl;
  }
}
```

## Binary Functions
```c++
template <typename elementType> 
class Multiply {
public:
  elementType operator () (const elementType& elem1, const elementType& elem2) { 
    return (elem1 * elem2); 
  }
};

int main() {
  std::vector <int> multiplicands{ 0, 1, 2, 3, 4 };
  std::vector <int> multipliers{ 100, 101, 102, 103, 104 };
  // A third container that holds the result of multiplication
  std::vector <int> vecResult;
  // Make space for the result of the multiplication
  vecResult.resize (multipliers.size());
  transform (multiplicands.begin (),  // range of multiplicands
             multiplicands.end (),  // end of range
             multipliers.begin (),  // multiplier values
             vecResult.begin (),  // holds result
             Multiply<int>() );  // multiplies, The return value of the operator() is held in vecResult.
}
```

## Binary Predicate
A function that accepts two arguments and returns a `bool` is a binary predicate.
```c++
class CompareStringNoCase {
public:
  bool operator () (const string& str1, const string& str2) const {
    string str1LowerCase;
    // Assign space 
    str1LowerCase.resize(str1.size()); 
    // Convert every character to the lower case
    transform(str1.begin(), str1.end(), str1LowerCase.begin(), ::tolower);
    string str2LowerCase; 
    str2LowerCase.resize (str2.size());
    transform(str2.begin(), str2.end(), str2LowerCase.begin(), ::tolower);
  }
  return (str1LowerCase < str2LowerCase);
}

int main() {
  // ...
  vector<string> names{ "jim", "Jack", "Sam", "Anna" };
  sort(names.begin(), names.end(), CompareStringNoCase());
}
```




