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



