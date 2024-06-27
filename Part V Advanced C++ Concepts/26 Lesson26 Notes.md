# Lesson 26 - Understanding Smart Pointers
When managing memory on the heap (or the free store), we can make use of smart pointers. A smart pointer in C++ is a class with overloaded operators, which behaves like a conventional pointer.

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
  ~smart_pointer() { delete rawPtr; }  // destructor, allowing for automatic memory release.
  
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
```c++
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

## Copy on Write Mechanism(*COW*)
Sharing pointers until the first attempt at writing to the object is made. On the first attempt at invoking a non-`const` function, a COW pointer typically creates a copy of the object on which the non-const function is invoked, whereas other instances of the pointer continue sharing the source object.

## Reference-Counted Smart Pointers
Reference counting in general is a mechanism that keeps a count of the number of users of an object. When the count reduces to zero, the object is released.  
There are at least two popular ways to keep this count: 
* Reference count maintained in the object being pointed to (*intrusive reference counting*)
* Reference count maintained by the pointer class in a shared object (on the free store)

## Reference-Linked Smart Pointers
Reference-linked smart pointers don’t count the number of references using the object, they just need to know when the number comes down to zero so that the object can be released. They are called `reference-linked` because their implementation is based on a double-linked list.

## Destructive Copy Destructive
Destructive copy is a mechanism where a smart pointer, when copied, transfers complete ownership of the object being handled to the destination and resets itself:
```
destructive_copy_smartptr<SampleClass> smartPtr (new SampleClass()); 
SomeFunc (smartPtr);  // Ownership transferred to SomeFunc 
// Don't use smartPtr in the caller any more!
```
They ensure that at any point in time, only one active pointer points to an object.
```c++
template<typename T> 
class destructivecopy_ptr {
private:
  T* object;
public:
  destructivecopy_ptr(T* input) : object(input) {}
  ~destructivecopy_ptr() { delete object; }
  // copy constructor
  destructivecopy_ptr(destructivecopy_ptr& source)  // note, cannot be const
  {
    // Take ownership on copy
    object = source.object;
    // destroy source
    source.object = 0;
  }
  // copy assignment operator
  destructivecopy_ptr& operator= (destructivecopy_ptr& source)  // note, cannot be const
  {
    if (object != source.object) {
      delete object;
      object = source.object;
      source.object = 0;
    }
  }
};

int main() {
  destructivecopy_ptr<int> num (new int);
  destructivecopy_ptr<int> copy = num;
  // num is now invalid
  return 0;
}
```

## Using the `std::unique_ptr`
`std::unique_ptr` is a simple smart pointer that with a private copy constructor and assignment operator to disallow copy via passing as an argument to a function by value, or copy via assignment.   
To use class `std::unique_ptr`, include header: `#include <memory>`
```c++
#include <memory>  // include this to use std::unique_ptr 
class Fish {
public:
  Fish() {cout << "Fish: Constructed!" << endl;}
  ~Fish() {cout << "Fish: Destructed!" << endl;}
  void Swim() const {cout << "Fish swims in water" << endl;} 
}; 
void MakeFishSwim(const unique_ptr<Fish>& inFish) { 
  inFish->Swim();
} 

int main() { 
  unique_ptr<Fish> smartFish(new Fish);
  smartFish->Swim();
  MakeFishSwim(smartFish); // OK, as MakeFishSwim accepts reference

  unique_ptr<Fish> copySmartFish; 
  // copySmartFish = smartFish; // error: operator= is private
  // move semantics
  unique_ptr<Fish> sameFish(std::move(smartFish)); 
  // smartFish is empty henceforth
  return 0;
}
```
> When writing applications using multiple threads, evaluate using `std::shared_ptr` and `std::weak_ptr`

## Popular Smart Pointer Libraries
Boost (www.boost.org) supplies you with some well-tested and well-documented smart pointer classes, among many other useful utility classes. You can find further information on Boost smart pointers and downloads at http://www.boost.org/libs/smart_ptr/smart_ptr.htm.



