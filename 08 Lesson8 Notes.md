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
int *pointsToInt = NULL;  // initilized with NULL to avoid junk value.
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







