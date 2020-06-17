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
## Class is a Data Type
Keyword `class`, C++ has provided you with a powerful way to create your own **data type** that allows you to **encapsulate** attributes and functions that work using those. All attributes of a class and all functions declared within it are called **members** of class.

## An *Object* as an Instance of a Class
To use the features of a class, you typically create an instance of that class, called an **object**.  
`Human firstMan;` just like:  
`double pi = 3.14;`  
Alternatively, you would dynamically create an instance of `class Human` using `new`:  
```c++
Human* firstWoman = new Human();
delete firstWoman;
```
just like:  
```c++
int* numPointer = new int;
delete numPointer;
```

## Accessing Members Using the Dot Operator (.)
```c++
Human firstMan;
firstMan.dateOfBirth = "1970";
firstMan.IntroduceSelf(); 

Human* firstWoman = new Human();
(*firstWoman).IntroduceSelf();
```

## Accessing Members Using the Pointer Operator (->)
If an object has been instantiated on the free store using `new` or if you have a pointer to an object, then you use the pointer operator (`->`) to access the member attributes and functions:  
```c++
Human* firstWoman = new Human(); 
firstWoman->dateOfBirth = "1970"; 
firstWoman->IntroduceSelf(); 
delete firstWoman;
```

## Keywords `public` and `private` 
```c++
class Human {
private:
  // cannot be accessed from outside.
  int age;
  string name;
  
public:
  int GetAge() {
    return age;
  }

  void SetAge(int humanAge) {
    age = humanAge;
  }
  
  // ...
};

int main() {
  Human eve;
  cout << eve.age; // compile error
  cout << eve.GetAge(); // OK
  
  eve.age = 22; // compile error
  eve.SetAge(22); // OK
}
```

## Abstraction of Data via Keyword `private`
You have the possibility to allow controlled access to even information declared `private` via methods that you have declared as `public` i.e. `getter` and `setter`.  

___

## Constructors
A *`constructor`* is a special function (or method) invoked during the instantiation of a class to construct an object. Just like functions, constructors can also be overloaded.   

## Declaring and Implementing a Constructor
```c++
class Human {
public:
  Human() {
    // constructor code here
  }
};
```
Or:  
```c++
class Human {
public: 
  Human(); // constructor declaration 
};
// constructor implementation (definition) 
Human::Human() {
  // constructor code here 
}
```

## When and How to Use Constructors
A constructor that is invoked without arguments is called the default constructor.  
```c++
class Human {
private:
  int age;
  string name;

public:
  Human() {
    age = 1;
    cout << "Constructed an instance of class Human" << endl;
  }
  
  Human(int humansAge, string humansName) { // overloaded
    age = humansAge;
    name = humansName;
  }
  
  // ... 
}

int main() {
  Human firstMan; // use default constructor, no arguments
  // ...
  Human firstWoman(28, "Jim"); // use overloaded constructor with arguments
  // ...
}
```
## Constructors with Initialization Lists
```c++
class Human {
private:
  int age;
  string name;

public:
  // Default Constructor That Accepts Parameters with Default Values
  Human(int humansAge = 25, string humansName = "Adam") : age(humansAge), name(humansName) { 
    // ...
  }
  
  // overloaded constructor (no default constructor) Human(string
  Human(int humansAge, string humansName) : age(humansAge), name(humansName) { 
    // ...
  }
  
  // ...
};
```

## Destructor
A destructor, like a constructor, is a special function, too. A constructor is invoked at object instantiation, and a destructor is automatically invoked when an object is destroyed.

## Declaring and Implementing a Constructor
```c++
class Human {
public:
  ~Human() {
    // constructor code here
  }
};
```
Or:  
```c++
class Human {
public: 
  ~Human(); // constructor declaration 
};
// constructor implementation (definition) 
Human::~Human() {
  // constructor code here 
}
```

## When and How to Use a Destructor 
A destructor is always invoked when an object of a class is destroyed when it goes out of scope or is deleted via `delete`. This property makes a destructor the ideal place to reset variables and release dynamically allocated memory and other resources. `std::string` and other such utilities are nothing but classes themselves that make use of constructors and the destructor.  
```c++
class MyString {
private:
  char* buffer;
  
public:
  MyString(const char* initSting) {
    if(initString != NULL) {
      buffer = new char[strlen(initString) + 1];
      strcpy(buffer, initString);
    }
    else {
      buffer = NULL;
    }
  }
  
  ~MyString() {
    cout << "Invoking destructor, clearing up" << endl;
    if(buffer != NULL) {
      delete [] buffer;
    }
  }
  
  // ...
};
```

## Copy Constructor
`double Area(double radius);`  
The argument sent as parameter `radius` is copied when `Area()` is invoked. This rule applies to objects, that is, instances of classes as well.  
## Shallow Copying and Associated Problems
When an object of this class(contain pointer members) is copied, the pointer member is copied, but not the pointed memory, resulting in two objects pointing to the same dynamically allocated buffer in memory. When an object is destructed, `delete[]` or `delete` deallocates the memory, thereby invalidating the pointer copy held by the other object. Such copies are `shallow` and are a threat to the stability of the program.  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/copy_constructor.png)

## Ensuring Deep Copy Using a Copy Constructor
```c++
class MyString {
private:
  char* buffer;
  
public:
  MyString(const char* initSting) {
    if(initString != NULL) {
      buffer = new char[strlen(initString) + 1];
      strcpy(buffer, initString);
    }
    else {
      buffer = NULL;
    }
  }
  
  MyString(const MyString& copySource) { // Copy constructor
    if(copySource.buffer != NULL) {
      buffer = new char[strlen(copySource.buffer) + 1];
      strcpy(buffer, copySource.buffer);
    }
    else {
      buffer = NULL;
    }
  }
  
  ~MyString() {
    cout << "Invoking destructor, clearing up" << endl;
    if(buffer != NULL) {
      delete [] buffer;
    }
  }
  
  // ...
};
```
Now it's deep copy:  
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/deepcopy_constructor.png)
> **Note:**  
The parameter in the copy constructor is passed by reference as a necessity i.e. `MyString(const MyString& copySource)`.   If this weren’t a reference, the copy constructor would itself invoke a copy, thus invoking itself again and so on till the system runs out of memory.

## Move Constructors Help Improve Performance
```c++
// move constructor
MyString(MyString&& moveSource) {
  if(moveSource.buffer != NULL) {
    buffer = moveSource.buffer; // take ownership i.e. 'move' 
    moveSource.buffer = NULL; // set the move source to NULL
  } 
}

MyString sayHelloAgain(Copy(sayHello)); // invokes 1x copy, 1x move constructors
```

## Different Uses of Constructors and the Destructor
**Class That Does Not Permit Copying**  
To avoid copying by declaring a `private` copy constructor. To avoid assignment, you declare a `private` assignment operator.   
```c++
class President {
private:
  President(const President&); // private copy constructor 
  President& operator= (const President&); // private copy assignment operator
  
  // ...
};
```
> There is no need for implementation of the private copy constructor or assignment operator. Just declaring them as private is adequate and sufficient toward fulfilling your goal of ensuring **non-copyable** objects of `class President`.

***Read More: https://ariya.io/2015/01/c-class-and-preventing-object-copy***

**Singleton Class That Permits a Single Instance**
> **`static`** 
* When the keyword static is used on a class’s data member, it ensures that the member is shared across all instances. 
* When static is used on a local variable declared within the scope of a function, it ensures that the variable retains its value between function calls. 
* When static is used on a member function—a method—the method is shared across all instances of the class.
```c++
// Page 257 Listing 9.10
class President {
private:
  President() {}; // private default constructor
  President(const President&); // private copy constructor
  const President& operator=(const President&); // assignment operator
  
public:
  static President& GetInstance() {
    // static objects are constructed only once
    static President onlyInstance;
    return onlyInstance;
  }
  
  // ...
};

int main() {
  President& onlyPresident = President::GetInstance();
  // President second; // cannot access constructor
  // President* third= new President(); // cannot access constructor 
  // President fourth = onlyPresident; // cannot access copy constructor
  // onlyPresident = President::GetInstance(); // cannot access operator=
  // ...
}
```
Because `GetInstance()` is a static member, it is like a global function that can be invoked without having an object as a handle.

**Class That Prohibits Instantiation on the Stack**  
The key to ensuring this is declaring the **destructor** `private`:  
```c++
class MonsterDB {
private:
  ~MonsterDB(); // private destructor
  //... members that consume a huge amount of data
};

int main() {
  MonsterDB myDatabase; // compile error 
  // … more code 
  return 0;
}
```
This instance, if successfully constructed, would be on the **stack**.    
A `private` destructor would not stop you from instantiating on the **heap**:
```c++
int main() {
  MonsterDB* myDatabase = new MonsterDB(); // on heap, no error 
  // … more code 
  MonsterDB::DestroyInstance(myDatabase);
  
  return 0;
}
```
As the destructor is not accessible from main, you cannot do a `delete`, either. What `class MonsterDB` needs to support is a `public static` member function that would destroy the instance (a class member would have access to the private destructor).
```c++
class MonsterDB {
private:
  ~MonsterDB() {}; // private destructor
  //... members that consume a huge amount of data
  
public:
  static void DestroyInstance(MonsterDB* pInstance) {
    delete pInstance; // member can invoke private destructor
  }
};
```

**Using Constructors to Convert Types**  
Using keyword `explicit` before constructor to avoid implicit conversions:  
```c++
class Human {
private:
  int age;
public:
  explicit Human(int humanAge) : age(humanAge) {}
};
```
then, something like that is not allowed:  
`Human anotherKid = 11; // int converted to Human`  
***Read More: https://weblogs.asp.net/kennykerr/Explicit-Constructors***

## `This` Pointer
`this` is a reserved keyword applicable within the scope of a class and contains the address of the object. In other words, the value of `this` is `&object`. 

## `sizeof()` a Class
Basically it reports the sum of bytes consumed by each data attribute contained within the class declaration. Note that member functions and their local variables do not play a role in defining the `sizeof()` a class.  

## How `struct` Differs from `class`
`struct` is treated by a C++ compiler similarly to a `class`. Unless specified, members in a `struct` are `public` by default (`private` for a class), and unless specified, a `struct` features `public` inheritance from a base `struct` (`private` for a class).  
```c++
struct Human {
  // constructor, public by default (as no access specified is mentioned) 
  Human(const MyString& humansName, int humansAge, bool humansGender) 
      : name(humansName), age (humansAge), Gender(humansGender) {}
      
  int GetAge () {
    return age; 
  } 
  
private: 
  int age;
  bool gender; 
  MyString name;
};
```

## Declaring a `friend` of a `class`
A class does not permit external access to its data members and methods that are declared `private`. This rule is waived for classes and functions that are disclosed as friend classes or functions, using keyword `friend`.
```c++
class Human {
private:
  friend void DisplayAge(const Human& person);
  friend class Utility;
  int age;
  
public:
  Human(int humanAge) : age(humanAge) {}
};

void DisplayAge(const Human& person) {
  cout << person.age << end;
}

class Utility {
public:
  static void DisplayAge(const Human& person) {
    cout << person.age << endl;
  }
};

int main() {
  Human firstMan(13);
  DisplayAge(firstMan);
  Utility::DisplayAge(firstMan);
  
  return 0;
}
```

## `union`: A Special Data Storage Mechanism
A `union` is a special class type where only one of the non-static data members is active at a time. Often a `union` is used as a member of a `struct` to model a complex data type.  
**Declaring a Union**  
```
union UnionName {
  Type1 member1; 
  Type2 member2;
  ...
  TypeN memberN; 
};
```
And instantiate and use a `union` like:  
```
UnionName unionObject;
unionObject.member2 = value; // choose member2 as the active member
```
Additionally, the `sizeof()` a `union` is always fixed as the size of the largest member contained in the `union`.

## Using Aggregate Initialization on Classes and Structs
`Type objectName {argument1, ..., argumentN};`  
```c++
class Aggregate1 {
public:
  int num; 
  double pi;
}; 
struct Aggregate2 {
  char hello[6];
  int impYears[3];
  string world;
}; 

int main() {
  Aggregate1 a1{ 2017, 3.14 };
  Aggregate2 a2{ {'h', 'e', 'l', 'l', 'o'}, {2011, 2014, 2017}, "world"};
  // Alternatively
  Aggregate2 a2_2{'h', 'e', 'l', 'l', 'o', '\0', 2011, 2014, 2017, "world"};
}
```

## `constexpr` with Classes and Objects

