# Lesson 9 - Classes and Objects

## Declaring a Class 
You declare a class using the keyword `class` followed by the name of the class, followed by a statement block `{...}` that encloses a set of *member attributes* and *member functions* within curly braces, and finally terminated by a semicolon ‘`;`’.
```c++
class Human {
  // Member attributes: 
  string name;
  string dateOfBirth; 
  string placeOfBirth; 
  string gender;

  // Member functions:
  void Talk(string textToTalk); 
  void IntroduceSelf(); 
  ...
};
```
Keyword `class`, C++ has provided you with a powerful way to create your own **data type** that allows you to **encapsulate** attributes and functions that work using those. All attributes of a class and all functions declared within it are called **members** of class.

## An Object as an Instance of a Class

