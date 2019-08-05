# Lesson 8 - Pointers and References Explained
Understanding how pointers and references work is one step toward being able to write programs that are effective in their consumption of system resources.  

## What Is a Pointer?
A *pointer* is a variable, and like all variables, a pointer occupies space in memory and has its own memory address(in the case of Figure 8.1, at address 0x101). What’s special about pointers is that the value contained in a pointer (in this case, 0x558) is interpreted as a memory address. So, a pointer is a special variable that *points to* a location in memory.
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/pointers.png)
For example:
```c++
int num = 3;
int* numPointer = &num;  // use pointer 'numPointer' to store num's address.
// numPointer is also a variable, and has its own memory address, you can assume its datatype is int*.

/* you can do the following thing to 'num' to get its memory address: */
cout << "variable num's memory address: " << &num << endl;
/* you can do the same thing to 'numPointer': */
cout << "variable numPointer's memory address: " << &numPointer << endl;

/* get the content of variable 'num': */
cout << "value contained in num: " << num << endl;
/* get the content of variable 'numPointer'(the content in that variable is num's address) */
cout << "value contained in numPinter: " << numPointer << endl;

// the specific operator of a pointer, mapping the address it contains to the value contained in that address.
cout << "value contained in address that contained in numPinter: " << *numPointer << endl;  // equals to 'num'

// Output:
/*
variable num's memory address: 0x7fff7532ed5c
variable numPointer's memory address: 0x7fff7532ed60
value contained in num: 3
value contained in numPinter: 0x7fff7532ed5c
value contained in address that contained in numPinter: 3
*/
```

**Declaring a Pointer**  
`PointedType * PointerVariableName;`  
`PointedType * PointerVariableName = NULL; // initializing value (a better choice)`  
for example:
```c++
int* pointsToInt = NULL;  // initilized with NULL to avoid junk value.
```

**Determining the Address of a Variable Using the Reference Operator (`&`)**
```c++
int num = 3;
cout << &num << endl;
```

**Using Pointers to Store Addresses**
`Type* Pointer = &Variable;`
for example:
```c++
int* numPointer = &num;
```

**Access Pointed Data Using the Dereference Operator (`*`)**
```c++
cout << << *numPointer << endl;
```

## What Is the `sizeof()` of a Pointer?
The length of an address, that is the number of bytes required to store it, is a constant for a given system. The `sizeof()` a pointer is hence dependent on the compiler and the operating system the program has been compiled for and is **NOT** dependent on the nature of the data being pointed to.
```c++
float pi = 3.14;
float* piPointer = &pi;
cout << "size of float: " << sizeof(pi) << endl;
cout << "size of float pointer: " << sizeof(piPointer) << endl;
cout << "----------------" << endl;
double dpi = 3.1415926;
double* dpiPointer = &dpi;
cout << "size of double: " << sizeof(dpi) << endl;
cout << "size of double pointer: " << sizeof(dpiPointer) << endl;

// Output:
/*
size of float: 4
size of float pointer: 8
----------------
size of double: 8
size of double pointer: 8
*/
```

## Dynamic Memory Allocation and Release with `new` and `delete`
Pointers being variables that are used to contain memory addresses play a critical role in efficient dynamic memory allocation.
**`new`**  
Note that `new` returns a pointer, and that is the reason it is assigned to one.
`Type* Pointer = new Type; // request memory for one element`  
`Type* Pointer = new Type[numElements]; // request memory for numElements`  

**`delete`**  
Remeber to release the memory that requested by `new` with `delete`, otherwise it will cause **Memory Leak**, and only the memory that requested by `new` can be released by `delete`.     
`delete Pointer; // release memory for one element`  
`delete[] Pointer; // release block for numElements`
> Note the usage of `delete[]` when you allocate a block using `new[...]` and `delete` when you allocate just an element using `new`.

for example:  
```c++
int* newPointer = new int;  // return a pointer, and assign it to newPointer
cin >> *newPointer;
cout << *newPointer << " is stored at 0x" << newPointer << endl;
delete newPointer;  // release memory

int nunNumbers = 10;
int* myNumbers = new int[numNumbers];
cout << "Memory allocated at: 0x" << myNumbers << endl;
delete[] myNumbers;
```
> **free store**  
Operators `new` and `delete` allocate memory from the free store.   
The free store is a memory abstraction in the form of a pool of memory where your application can allocate (that is, reserve) memory from and de-allocate (that is, release) memory to.

## Effect of Incrementing and Decrementing Operators (`++` and `--`) on Pointers
The address contained in the pointer is incremented or decremented by the `sizeof` the type being pointed to (and not necessarily a byte).
```c++
#include <iostream> 
using namespace std;

int main() {
  int numEntries = 10;
  int* pointsToInts = new int [numEntries];
  for(int counter = 0; counter < numEntries; ++counter) {
    cin >> *(pointsToInts + counter);
  }

  cout << "Displaying all numbers entered: " << endl;
  for(int counter = 0; counter < numEntries; ++counter) {
    cout << *(pointsToInts++) << " ";
  }
  cout << endl;

  // return pointer to initial position, because the present pointsToInts is not the one allocated by new.
  // and delete can only release the memory requested by new.
  pointsToInts -= numEntries;  

  // done with using memory? release
  delete[] pointsToInts;
  
  return 0; 
}
```
The original pointer address returned by `new` during allocation needs to be used in the call to `delete[]` during de-allocation.

## Using the `const` Keyword on Pointers
The value of a const-variable cannot be changed, and therefore it cannot be used as an **l-value**.
* The address contained in the pointer is constant and cannot be changed, yet the data at that address can be changed:  
`int* const pDaysInMonth = &daysInMonth;`  
`*pDaysInMonth = 31; // OK! Data pointed to can be changed`
`pDaysInMonth = &daysInLunarMonth; // Not OK! Cannot change address!`
* Data pointed to is constant and cannot be changed, yet the address contained in the pointer can be changed—that is, the pointer can also point elsewhere:
`const int* pointsToInt = &hoursInDay;`  
`pointsToInt = &monthsInYear; // OK!`  
`*pointsToInt = 13; // Not OK! Cannot change data being pointed to`
* Both the address contained in the pointer and the value being pointed to are constant and cannot be changed (most restrictive variant):
`const int* const pHoursInDay = &hoursInDay;`  
`*pHoursInDay = 25; // Not OK! Cannot change data being pointed to`  
`pHoursInDay = &daysInMonth; // Not OK! Cannot change address`

## Passing Pointers to Functions Pointers
Pointers are an effective way to pass memory space that contains relevant data for functions to work on.
```c++
void CalcArea(const double* const ptrPi, // const pointer to const data
              const double* const ptrRadius, // i.e. no changes allowed
              double* const ptrArea) { // can change data pointed to
  if (ptrPi && ptrRadius && ptrArea) { // use to check whether there is NULL address
    *ptrArea = (*ptrPi) * (*ptrRadius) * (*ptrRadius);
  }
}

int main() {
  const double Pi = 3.1416;
  cout << "Enter radius of circle: "; double radius = 0;
  cin >> radius;
  double area = 0;
  // Note that there much pass in the variables' addresses.
  CalcArea (&Pi, &radius, &area);
  cout << "Area is = " << area << endl;
  
  return 0; 
}
```

## Similarities between Arrays and Pointers 
`myNumbers` is a pointer to the first element `myNumbers[0]`.  
`myNumbers[1]` equals to `* (pointToNums + 1)`. 
> Note that one can assign an array to a pointer as `int* pointToNums = myNumbers;`, but one cannot assign a pointer to an array. This is because by its very nature, an array like `myNumbers` is static and cannot be used as an **l-value**. myNumbers cannot be modified.

## Common Programming Mistakes When Using Pointers
* **Memory Leaks**
```
int* pointToNums = new int[5]; // initial allocation 
// use pointToNums 
...
// forget to release using delete[] pointToNums; 
...
// make another allocation and overwrite 
pointToNums = new int[10];  // leaks the previously allocated memory
```
* **When Pointers Don’t Point to Valid Memory Locations**
Logical as this may seem, invalid pointers are quite a common reason for application crashes.
* **Dangling Pointers (Also Called Stray or Wild Pointers)**
Note that any valid pointer is invalid after it has been released using delete.
> **DON’T invoke delete on a memory address more than once.**  
**Q I have two pointers:**  
`int* pointToAnInt = new int;`  
`int* pCopy = pointToAnInt;`  
Am I not better off calling `delete`   using both to ensure that the memory is gone?  
**A** That would be wrong. **You are allowed to invoke delete only once on the address returned by new.** Also, you would ideally avoid having two pointers pointing to the same address because **performing `delete` on any one would invalidate the other.** Your program should also not be written in a way that you have any uncertainty about the validity of pointers used.

* **Checking Whether Allocation Request Using new Succeeded**
  * Use `try ... catch(bad_alloc) ...`
  * Use `new(nothrow)` which will return `NULL` when failed.
  
## What Is a Reference?
The reference variable is just a different way to access the data stored in the variable being referenced.  
`VarType original = Value;`  
`VarType& ReferenceVariable = original;`

## Using Keyword `const` on References
```c++
int original = 30;
const int& constRef = original;
constRef = 40; // Not allowed: constRef can’t change value in original 
int& ref2 = constRef; // Not allowed: ref2 is not const 
const int& constRef2 = constRef; // OK
```

## Passing Arguments by Reference to Functions(Important)
The copying step can be quite an overhead if the argument in question consumes a lot of memory.   
It is often important to ensure that the called function cannot change the value of the variable at the caller’s end. A const reference parameter cannot be used as an l-value.
```c++
void GetSquare(const int& number, int& result) {
  result = number * number;
}
```


