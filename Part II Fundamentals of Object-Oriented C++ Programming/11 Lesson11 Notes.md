# Lesson 11 - Polymorphism
```c++
clss Fish {
public:
  void Swim() {}
  // ...
};

class Carp : public Fish {
public:
  void Swim() {}
  // ...
};

void MakeFishSwim(Fish& inputFish) {
  // calling Fish::Swim
  inputFish.Swim();
}

int main() {
  Carp myLunch;
  
  // calling Carp::Swim
  myLunch.Swim();
  
  // sending Carp as Fish, calling Fish::Swim where we also want to call Carp::Swim
  MakeFishSwim(myLunch);
}
```

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
What happens when a function calls operator `delete` using a pointer of type `Base*` that actually points to an instance of type `Derived`?
```c++
void DeleteFishMemory(Fish* pFish) {
  delete pFish; // calling Fish::~Fish
}

int main() {
  Carp* pCarp = new Carp;
  cout << "Deleting the Carp: " << endl;
  DeleteFishMemory(pCarp);
  
  // Output
  // Destroyed Fish
}
```
The destructor of a deriving class that has been instantiated on the free store using `new` would not be invoked if `delete` is called using a pointer of type `Base*`.  
To avoid this problem, you use `virtual` destructors:  
```c++
clss Fish {
public:
  Fish() {
    cout << "Constructed Fish" << endl;
  }
  virtual ~Fish() {
    cout << "Destroyed Fish" << endl;
  }
};

clss Carp : public Fish {
public:
  Carp() {
    cout << "Constructed Carp" << endl;
  }
  ~Carp() {
    cout << "Destroyed Carp" << endl;
  }
};

  // Output
  // Destroyed Carp
  // Destroyed Fish
```
So: Always declare the base class destructor as virtual:  
```c++
class Base {
public: 
  virtual ~Base() {}; // virtual destructor 
};
```

## How Do `virtual` Functions Work? Understanding the Virtual Function Table(VFT)
The **Virtual Function Table** can be visualized as a **static array** containing **function pointers**, each pointing to the virtual function (or override) of interest.
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/vft.png)
```c++
class SimpleClass {
    int a, b;
public:
    void DoSomething() {}
};

class Base {
    int a, b;
public:
    virtual void DoSomething() {}
};

// sizeof(SimpleClass) = 8 (two int)
// sizeof(Base) = 16 (For 64-bit Compiler, two int + pointer)
```
The difference in adding this `virtual` keyword is that the compiler generates a virtual function table for class `Base` and a reserved place for a pointer to the same in `Base` as a hidden member.

## Abstract Base Classes and Pure Virtual Functions
A base class that cannot be instantiated is called an *`abstract base class`*. Such a base class fulfills only one purpose, that of being derived from.   
A virtual method is said to be *`pure virtual`* when it has a declaration.
```c++
class AbstractBase {
public: 
  virtual void DoSomething() = 0; // pure virtual method 
};

class Derived: public AbstractBase {
public:
  void DoSomething() { // pure virtual fn. must be implemented 
    cout << "Implemented virtual function" << endl; 
  } 
};
```
Abstract Base Classes are often simply called ABCs.

## Using `virtual` Inheritance to Solve the Diamond Problem 
```
class Derived1: public virtual Base {
  // ... members and functions 
};
class Derived2: public virtual Base {
  // ... members and functions 
};

class FinalDerived final : public Derived1, public Derived2 {
  // ... members and functions 
};
```
The virtual keyword in C++ often is used in different contexts for different purposes.  
* A function declared *virtual*.
* An inheritance relationship declared using keyword `virtual`.
> **Diamond Problem**  
Problems caused in an inheritance hierarchy containing two or more base classes that inherit from a common base, which results in the need for ambiguity resolution in the absence of virtual inheritance, is called the Diamond Problem.

## Specifier `Override` to Indicate Intention to Override
```c++
class Base {
    int a, b;
public:
    virtual void DoSomething() {
        cout << "la" << endl;
    }

    virtual void DoSomething2() {
        cout << "la2" << endl;
    }
};

class Derived : public Base {
public:
    void DoSomething() override { // ok, it indeed override the DoSomething() function in Base class
        cout << "lala" << endl;
    }

    void DoSomething2() const { // ok, but not override the DoSomething2() function in Base class
        cout << "lala2" << endl;
    }
    // If you mark it as override, like:
    /*
    void DoSomething2() const override { // error
        cout << "lala2" << endl;
    }
     */
};

void Do(Base& baseClass) {
    baseClass.DoSomething();
    baseClass.DoSomething2();
}

int main() {
    Derived derivedClass;
    derivedClass.DoSomething(); // lala
    derivedClass.DoSomething2(); // lala2
    Do(derivedClass); // lala, la2(which is not override)
    return 0;
}
```
`override` supplies a powerful way of expressing the explicit intention to override a base class virtual function.
* The base class function is `virtual`.
* The signature of the base class virtual function exactly matches the signature of the derived class function declared to `override`.

## Use `final` to Prevent Function Overriding
```c++
class Base {
    int a, b;
public:
    virtual void DoSomething() {}
};

class Derived : public Base {
public:
    void DoSomething() override final { 
        cout << "lala" << endl;
    }
};

class NextDerived : public Derived {
public:
    void DoSomething() { // error
        cout << "lala" << endl;
    }
};
```

## Virtual Copy Constructors?
It is technically impossible in C++ to have virtual copy constructors. Yet, such a feature would help you create a collection (for example, a static array) of type `Base*`, each element being a specialization of that type:  
// Tuna, Carp and Trout are classes that inherit public from base class Fish 
```
Fish* pFishes[3]; 
Fishes[0] = new Tuna(); 
Fishes[1] = new Carp(); 
Fishes[2] = new Trout();
```
There is a nice workaround in the form of defining your own clone function that allows you to do just that:
```c++
class Fish {
public: 
  virtual Fish* Clone() const = 0; // pure virtual function 
};

class Tuna : public Fish {
// ... other members 
public:
  Tuna * Clone() const { // virtual clone function 
    return new Tuna(*this); // return new Tuna that is a copy of this 
  }
};
```

## Tips
* DO remember to mark base class functions that need to be overridden by the derived class as virtual.
* DO remember that pure virtual functions make your class an Abstract Base Class, and these functions must be implemented by a deriving class.
* DON’T forget to supply your base class with a virtual destructor.
