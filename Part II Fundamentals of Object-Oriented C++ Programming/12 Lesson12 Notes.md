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

# Programming Dereference Operator (`*`) and Member Selection Operator (`->`)
*Smart pointers* are utility classes that wrap regular pointers and simplify memory management by resolving ownership and copy issues using operators.
```c++
#include <memory> // new include to use unique_ptr
// ...
int main() {
  unique_ptr<int> smartIntPtr(new int);
  *smartIntPtr = 42;
  // Use smart pointer type like an int*
  cout << "Integer value is: " << *smartIntPtr << endl;
  
  unique_ptr<Date> smartHoliday (new Date(12, 25, 2016));
  // use smartHoliday just as you would a Date*
  smartHoliday->DisplayDate();
  
  return 0;
}
```

# Binary Operators
Operators that function on two operands are called *binary operators*.
**A binary operator that is implemented in the global namespace or as a static member function of a class:**    
`return_type operator_type (parameter1, parameter2);`  
**A binary operator that is a (non-static) member of a class:**  
`return_type operator_type (parameter);`  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/binary_operator.png)

## Programming Binary Addition (`a+b`) and Subtraction (`a-b`) Operators
```c++
class Data {
private:
  // ...
public:
  Data operator + (int daysToAdd) { // binary addition 
    Data newDate (month, day + daysToAdd, year);
    return newDate; 
  }
  
  Data operator - (int daysToSub) { // binary subtraction 
    return Date(month, day - daysToSub, year);
  }
  
  // ...
};
```

## Implementing Addition Assignment (`+=`) and Subtraction Assignment (`-=`) Operators
```c++
class Data {
private:
  // ...
public:
  void operator += (int daysToAdd) { // addition assignment
    day += daysToAdd;
  }
  
  void operator -= (int daysToSub) { // subtraction assignment 
    day -= daysToSub;
  }
  
  // ...
};
```

## Overloading Equality (`==`) and Inequality (`!=`) Operators
**Syntax**  
```
bool operator operatorType (const ClassType& compareTo) {
  // comparison code here, return true if equal else false 
}
```

```c++
class Data {
private:
  // ...
public:
  bool operator == (const Date& compareTo) {
    return day == compareTo.day;
  }
  
  bool operator != (const Date& compareTo) {
    return !(tihs->operator==(compareTo));
  }
  
  // ...
};
```

## Overloading `<`, `>`, `<=`, and `>=` Operators
```c++
class Data {
private:
  // ...
public:
  bool operator < (const Date& compareTo) {
    return day <   compareTo.day;
  }
  
  // ...
};
```

## Overloading Copy Assignment Operator (`=`)
`anotherHoliday = holiday; // uses copy assignment operator`  
This assignment invokes the default copy assignment operator that the compiler has built in to your class when you have not supplied one.
```
ClassType& operator = (const ClassType& copySource) {
  if(this != &copySource) { // protection against copy into self
    // copy assignment operator implementation 
  } 
  return *this; 
}
```
> To create a class that cannot be copied, declare the copy constructor and copy assignment operator as `private`.


## Subscript Operator (`[]`)
The operator that allow array-style [] access to a class is called *subscript operator*.  
`/*const*/ return_type& operator [] (subscript_type& subscript) /*const*/ {}`
By using `const` you are protecting internal member `MyString::buffer` from direct modifications from the outside via `operator []`.  
`char& operator [] (int index) const; // used only for accessing char at index`

## Function Operator `()`
The operator () that make objects behave like a function is called a *function operator*.  
```c++
class Data {
private:
  // ...
public:
  void operator () (string input) const {
    cout << input << endl;
  }
  
  // ...
};

int main() {
  Display displayFuncObj;
  displayFuncObj ("Display this string! ");
  return 0;
}
```

# Move Constructor and Move Assignment Operator for High Performance Programming
The move constructor and the move assignment operators ensure temporary values (rvalues that don’t exist beyond the statement) are not wastefully copied.  
## Declaring a Move Constructor and Move Assignment Operator
```
class Sample {
private: 
  Type* ptrResource; 

public:
  Sample(Sample&& moveSource) { // Move constructor, note && 
    ptrResource = moveSource.ptrResource; // take ownership, start move 
    moveSource.ptrResource = NULL;
  }
  Sample& operator = (Sample&& moveSource) { //move assignment operator, note && 
    if(this != &moveSource) {
      delete [] ptrResource; // free own resource 
      ptrResource = moveSource.ptrResource; // take ownership, start move 
      moveSource.ptrResource = NULL; // free move source of ownership
    }
  } 
  Sample(); // default constructor
  Sample(const Sample& copySource); // copy constructor 
  Sample& operator = (const Sample& copySource); // copy assignment
};
```
In your implementation of these two, you ensure that instead of copying, you are simply moving the resource from the source to the destination.  
Use this feature to optimize the functioning of classes that point to dynamically allocated resources that would otherwise be deep copied even in scenarios where they’re only required temporarily.

## User Defined Literals
```
ReturnType operator "" YourLiteral(ValueType value) {
  // conversion code here 
}
```
