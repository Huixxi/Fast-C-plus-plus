# Lesson 13 - Casting Operators
**Casting** is a mechanism by which the programmer can temporarily or permanently change the interpretation of an object by the compiler. Operators that change the interpretation of an object(not the object itself) are called *casting operators*.
There are two kinds of cast:  
* C-Style Casts
* Casting Keywords Introduced By C++ Compilers

## C-Style Casts
```
double Pi = 3.14159265;
int num = (int)Pi;
```  

## The C++ Casting Operators Despite
The four C++ casting operators are:
* `static_cast` 
* `dynamic_cast` 
* `reinterpret_cast` 
* `const_cast`

The usage syntax of the casting operators is consistent:   
`destination_type result = cast_operator<destination_type> (object_to_cast);`

## Using `static_cast`
`static_cast` is a mechanism that can be used to convert pointers between related types, and perform explicit type conversions for standard data types that would otherwise happen automatically or implicitly.  
`static_cast` implements a basic compile-time check to ensure that the pointer is being cast to a related type. Using `static_cast`, a pointer can be **upcasted** to the base type, or can be **downcasted** to the derived type, as the following code-sample indicates.   
```
Base* objBase = new Derived ();
Derived* objDer = static_cast<Derived*>(objBase); // ok! 

// class Unrelated is not related to Base
Unrelated* notRelated = static_cast<Unrelated*>(objBase); // Error 
// The cast is not permitted as types are unrelated
```
> Casting a `Derived*` to a `Base*` is called **upcasting** and can be done without any explicit casting operator:  
`Derived objDerived;`   
`Base* objBase = &objDerived; // ok!`

You would also need to use `static_cast` when using conversion operators or constructors that have been declared using keyword `explicit`.

## Using `dynamic_cast` and Runtime Type Identification
Dynamic casting is the opposite of static casting and actually executes the cast at runtime—that is, at application execution time.  
`dynamic_cast` helps determine the type at runtime and use a casted pointer when it is safe to do so.
```
destination_type* Dest = dynamic_cast<class_type*>(Source);
if(Dest) { // Check for success of the casting operation, It is NULL when the cast fails.
  Dest->CallFunc ();
}
```

## Using `reinterpret_cast`
`reinterpret_cast` is the closest a C++ casting operator gets to the C-style cast.
```
Base* objBase = new Base ();
Unrelated* notRelated = reinterpret_cast<Unrelated*>(objBase); 
// The code above compiles, but is not good programming! 
// You should refrain from using reinterpret_cast in your applications
```

## Using `const_cast`
`const_cast` enables you to turn off the `const` access modifier to an object.  
In the following case:  
```c++
class SomeClass {
public: 
  // ... 
  void DisplayMembers(); //problem - display function isn't const 
};

void DisplayAllData (const SomeClass& object) {
  object.DisplayMembers (); // Compile failure
  // reason: call to a non-const member using a const reference
}
```
After all, a display function should be read-only and should not be allowed to call non-const member functions—that is, should not be allowed to call a function that can change the state of the object.
```c++
void DisplayAllData (const SomeClass& object) {
  SomeClass& refData = const_cast<SomeClass&>(object);
  refData.DisplayMembers(); // Allowed!
}
```

## Problems with the C++ Casting Operators
The reasons range from the syntax being cumbersome and non-intuitive to being redundant.
