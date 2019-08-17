# Lesson 11 - Polymorphism

## Polymorphic Behavior Implemented Using Virtual Functions
You have access to an object of type `Fish`, via pointer `Fish*` or reference `Fish&`. This object could have been instantiated solely as a `Fish`, or be part of a `Tuna` or `Carp` that inherits from `Fish`.
```
class Base {
  virtual ReturnType FunctionName (Parameter List); 
};

class Derived {
  ReturnType FunctionName (Parameter List); 
};
```
Use of keyword `virtual` means that the compiler ensures that any overriding variant of the requested base class method is invoked.

## Need for Virtual Destructors








