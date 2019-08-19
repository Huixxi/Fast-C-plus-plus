# Lesson 12 - Operator Types and Operator Overloading
The operator-based mechanism facilitates consumption by supplying ease of use and intuitiveness.  
`Date holiday (12, 25, 2016);`  
Assuming that you want to add a day and get the instance to contain the next day:
* Option 1 (using the increment operator):  
`++ holiday;` 
* Option 2 (using a member function `Increment()`):  
`holiday.Increment(); // Dec 26, 2016`

# Unary Operators
Operators that function on a single operand are called *unary operators*.  
**A unary operator that is implemented in the global namespace or as a static member function of a class:**  
```
returnType operator operatorType (parameterType) {
  // ... implementation
}
```
**A unary operator that is a (non-static) member of a class has a similar structure but is lacking in parameters, because the single parameter that it works upon is the instance of the class itself (`*this`):**  
```
returnType operator operatorType () {
  // ... implementation
}
```
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/unary_operator.png)

## Programming a Unary Increment/Decrement Operator
```c++
class Data {
private:
  // ...
public:
  Data& operator ++ () { // prefix increment
    ++day;
    return *this;
  }
  
  Data& operator -- () { // prefix decrement
    --day;
    return *this;
  }
  
  Data operator ++ () { // postfix increment 
    Data copy();
    ++day;
    return copy; // copy of instance before increment returned
  }
  
  Data operator -- () { // postfix decrement 
    Data copy();
    --day;
    return copy; // copy of instance before decrement returned
  }
  
  // ...
};
```

## Programming Conversion Operators
If you want to `cout` an intance of a class just like `cout` a `string`, we need to define your own conversion operator.  
**Syntax**  
`/*explicit*/ operator conversion-type-id () {}`
**Getting cout to work with an instance of type by adding an operator that returns a `const char*` version::**  
```c++
#include <sstream> // new include for ostringstream

class Data {
private:
  // ...
  string dateInString;
public:
  // ...
  operator const char* () {
    ostringstream formattedDate; // assists string construction 
    formattedDate << month << " / " << day << " / " << year;
    dateInString = formattedDate.str();
    return dateInString.c_str();
  }
};
```
Note that such assignments cause implicit conversions. Using `explicit` would force the programmer to assert his intention to convert using a cast:  
```c++
explicit operator const char*() {
  // conversion code here 
}

string strHoliday(static_cast<const char*>(Holiday));
```
**Read More: https://en.cppreference.com/w/cpp/language/cast_operator**







