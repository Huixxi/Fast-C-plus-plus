# Lesson 26 - Understanding Smart Pointers
when managing memory on the heap (or the free store), we can make use of smart pointers. A smart pointer in C++ is a class with overloaded operators, which behaves like a conventional pointer.

## The Problem with Using Conventional (Raw) Pointers
For example:
```
SomeClass* ptrData = anObject.GetData(); 
/*
  Questions: Is object pointed by ptrData dynamically allocated using new? 
  If so, who calls delete? Caller or the called? 
  Answer: No idea!
*/ 
ptrData->DoSomething();
```

## How Do Smart Pointers Help?
```
smart_pointer<SomeClass> spData = anObject.GetData();
// Use a smart pointer like a conventional pointer! 
spData->Display(); 
(*spData).Display();
// Don't have to worry about de-allocation 
// (the smart pointer's destructor does it for you)
```
Smart pointers behave like conventional pointers, and supply useful features via their *overloaded operators* and *destructors* to ensure that dynamically allocated data is destroyed in a timely manner.

## How Are Smart Pointers Implemented?
Smart pointer classes overload derefencing operator (`*`) and member selection operator (`->`) to make the programmer use them as conventional pointers.
```c++
template <typename T>
class smart_pointer {
private:
  T* rawPtr;

public:
  smart_pointer(T* pData) : rawPtr(pData) {}  // constructor
  ~smart_pointer() { delete rawPtr; };  // destructor, allowing for automatic memory release.
  
  // copy constructor
  smart_pointer(const smart_pointer& anotherSP);  
  // copy assignment operator
  smart_pointer& operator= (const smart_pointer& anotherSP);
  
  T& operator* () const // dereferencing operator
  {
    return *(rawPtr);
  }
  
  T* operator-> () const // member selection operator
  {
    return rawPtr; 
  }
};
```

# Types of Smart Pointers
Classification of smart pointers is actually a classification of their memory resource management strategies. 
* Deep copy
* Copy on Write (COW)
* Reference counted
* Reference linked
* Destructive copy

## Deep copy
In a smart pointer that implements deep copy, every smart pointer instance holds a complete copy of the object that is being managed. Whenever the smart pointer is copied, the object pointed to is also copied (thus, deep copy). When the smart pointer goes out of scope, it releases the memory it points to (via the destructor).   
Its advantage becomes apparent in the treatment of polymorphic objects, the slicing problem:
```
// Example of Slicing When Passing Polymorphic Objects by Value 
// Fish is a base class for Tuna and Carp, Fish::Swim() is virtual
void MakeFishSwim(Fish aFish)  // note parameter type, not a reference, but a copied value
{ 
  aFish.Swim();  // virtual function 
}
// ... Some function 
Carp freshWaterFish;
MakeFishSwim(freshWaterFish);  // Carp will be 'sliced' to Fish 
// Slicing: only the Fish part of Carp is sent to 
```
```c++
template<typename T>  
class deepcopy_smart_ptr {
private:
  T* object;
public:
  //... other functions
  // copy constructor of the deepcopy pointer
  deepcopy_smart_ptr(const deepcopy_smart_ptr& source)
  {
    // Clone() is virtual: ensures deep copy of Derived class object
    object = source->Clone();
  }
  // copy assignment operator
  deepcopy_smart_ptr& operator= (const deepcopy_smart_ptr& source)
  {
    if(object)
      delete object;
    object = source->Clone(); 
  }
};

// the smart pointer itself is passed as a pointer to base class type Fish:
deepcopy_smart_ptr<Carp> freshWaterFish(new Carp); 
MakeFishSwim (freshWaterFish); // Carp will not be 'sliced'
```

## Copy on Write Mechanism




