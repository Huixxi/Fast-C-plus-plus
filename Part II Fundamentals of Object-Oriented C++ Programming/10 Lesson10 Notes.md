# Lesson 10 - Implementing Inheritance
Object-oriented programming is based on four important aspects: encapsulation, abstraction, inheritance, and polymorphism.

## C++ Syntax of Derivation
```
class Base {
  // ... base class members
};

class Derived : access-specifier Base {
  // ... derived class members
};
```
The `access-specifier` can be one of `public` (most frequently used) where a “derived class **is a** base class”(like Carp is Fish) relationship; `private` or `protected` for a “derived class **has a** base class” relationship.  

## Access Specifier Keyword `protected`
Using keyword `protected` in Base class to declare a class attribute or function as `protected`, to make them only accessible to classes that derive(and friends), yet simultaneously inaccessible to everyone else outside the class, including `main()`.
```c++
class Fish {
protected:
  bool isFreshWaterFish; // accessible only to derived classes
  
public:
  void DoSomething() {}
  // ...
};

class Carp : public Fish {
public:
  Carp() {
    isFreshWaterFish = flase;
  }
};

int main() {
  Carp myLunch;  
  myLunch.DoSomething();
  
  // myLunch.isFreshWaterFish = true; // not accessible from outside
}
```

## Base Class Initialization - Passing Parameters to the Base Class
The clue lies in using initialization lists and in invoking the appropriate base class constructor via the constructor of the derived class.
```c++
class Base {
public:
  Base(int someNumber) { // overloaded constructor
    // Use someNumber
  }
};

class Derived : public Base {
public:
  Derived() : Base(25) { // instantiate Base with argument 25
    // derived class constructor code
  }
};
```
> To ensure maximum security, if the derived classes don’t need to access a base class attribute, remember to mark the attribute `private`. 

## Derived Class Overriding Base Class’s Methods
```c++
class Base {
public:
  void DoSomething() {
    // implementation code... Does something 
  } 
};

class Derived : public Base {
public:
  void DoSomething() {
    // implementation code... Does something else 
  }
};
```

## Invoking Overridden Methods of a Base Class
```c++
  Carp myLunch;  
  myLunch.DoSomething(); // will invoke Carp::DoSomething()
  
  myLunch.Fish::DoSomething(); // invokes Fish::DoSomething() using instance of Carp
```

## Invoking Methods of a Base Class in a Derived Class
```c++
class Carp : public Fish {
public:
  Carp() : Fish(true) {}
  void DoSomething() {
    Fish::DoSomething(); // invoke base class function using operator::
  }
};
```

## Derived Class Hiding Base Class’s Methods
Page 296

## Order of Construction
* Base class objects are instantiated before the derived class.  
* The member attributes are instantiated before the constructor is invoked.

## Order of Destruction
The sequence of destruction is the opposite to that of construction.

## Private Inheritance
```c++
class Base {
  // ... base class members and methods 
};

class Derived : private Base { // private inheritance 
  // ... derived class members and methods 
};
```
Private inheritance of the base class means that all public members and attributes of the base class are private (that is, inaccessible) to anyone with an instance of the derived class.   
As private inheritance allows base class attributes and methods to be consumed only by the subclass that derives from it, this relationship is also called a “**has-a**” relationship(like Mammal “has a” Heart).  

## Protected Inheritance
```c++
class Base {
  // ... base class members and methods 
};

class Derived : protected Base { // private inheritance 
  // ... derived class members and methods 
};
```
Protected inheritance is similar to private inheritance in the following ways: 
* It also signifies a **has-a** relationship. 
* It also lets the derived class access all public and protected members of `Base`. 
* Those outside the inheritance hierarchy with an instance of `Derived` cannot access public members of `Base`.
Yet, protected inheritance is a bit different when it comes to the derived class being inherited from:
```c++
class Derived2: protected Derived {
  // can access public & protected members of Base 
};
```
> **Note:**  
Use private or protected inheritance only when you have to.

## The Problem of Slicing
```
Derived objDerived;
Base objectBase = objDerived;
```
Or:
```
void UseBase(Base input); 
...
Derived objDerived; 
UseBase(objDerived); // copy of objDerived will be sliced and sent
```
In both cases, an object of type `Derived` is being copied into another of type `Base`. In these cases, the compiler copies only the `Base` part of `objDerived` — that is, not the complete object. The information contained by the data members belonging to `Derived` is lost in the process.

## Multiple Inheritance
```
class Derived : access-specifier Base1, access-specifier Base2 {
  // class members 
};
```

## Avoiding Inheritance Using `final`
Starting with C++11, compilers support specifier `final`. It is used to ensure that a class declared as `final` cannot be used as a base class.
```c++
class Platypus final : public Mammal, public Bird, public Reptile {
public:
  void Swim() {
    cout << "Platypus: Voila, I can swim!" << endl; 
  } 
};
```

