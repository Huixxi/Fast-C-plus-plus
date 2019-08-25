# Lesson 27 - Using Streams for Input and Output
* `operator<<` used when writing into a stream is called the *stream insertion operator*
* `operator>>` used when writing a stream into a variable is called the *stream extraction operator*

## Important C++ Stream Classes and Objects
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/std_streamss.png)
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/std_stream.png)

# Using `std::cout` for Writing Formatted Data to Console
## Changing Display Number Formats Using `std::cout`
```c++
int input = 253;
cout << "Integer in octal: " << oct << input << endl;  // 375
cout << "Integer in hexadecimal: " << hex << input << endl;  // fd
// Integer in hex using base notation: 
cout << setiosflags(ios_base::hex | ios_base::showbase | ios_base::uppercase);  
cout << input << endl;  // 0XFD
// Integer after resetting I/O flags:
cout << resetiosflags(ios_base::hex | ios_base::showbase | ios_base::uppercase);
cout << input << endl;  // 253

const double Pi = (double)22.0 / 7;  // 3.14286
cout << setprecision(7);  
cout << "Pi = " << Pi << endl;  // 3.142857
cout << fixed << "Fixed Pi = " << Pi << endl;  // 3.1428571
cout << scientific << "Scientific Pi = " << Pi << endl;  // 3.1428571e+000
```

## Aligning Text and Setting Field Width Using `std::cout` 
```c++
cout << "Hey - default!" << endl;
cout << setw(35); // set field width to 25 columns
cout << "Hey - right aligned!" << endl;
cout << setw(35) << setfill('*');
cout << "Hey - right aligned!" << endl; 12:
cout << "Hey - back to default!" << endl;

// Output
Hey - default!
               Hey - right aligned!
***************Hey - right aligned! 
Hey - back to default!
```

# Using `std::cin` for Input
## Using `std::cin` for Input into a Plain Old Data Type
```c++
int inputNum = 0;
cin >> inputNum;

char char1 = '\0', char2 = '\0', char3 = '\0';
cin >> char1 >> char2 >> char3;
```

## Using `std::cin::get` for Input into `char*` Buffer
```c++
char charBuf[10] = {0}; 
cin.get(charBuf, 9); // stop inserting at the 9th character

// what you input is: Testing if I can cross the bounds of the buffer 
// the final charBuf is: Testing i
```

## Using `std::cin` for Input into a `std::string`
```c++
std::string name; 
cin >> name; // stops insertion at the first space

// what you input is: Siddhartha Rao
// the final name is: Siddhartha

// using getline
getline(cin, name);

// what you input is: Siddhartha Rao
// the final name is: Siddhartha Rao
```

# Using `std::fstream` for File Handling
To use class `std::fstream` or its base classes, include header: `#include <fstream>`

## Opening and Closing a File Using `open()` and `close()`
```c++
fstream myFile; 
myFile.open("HelloFile.txt",ios_base::in | ios_base::out | ios_base::trunc);
// alternatively
fstream myFile("HelloFile.txt",ios_base::in|ios_base::out|ios_base::trunc);
// write only
ofstream myFile("HelloFile.txt", ios_base::out);
// read only
ifstream myFile("HelloFile.txt", ios_base::in);

if(myFile.is_open()) // check if open() succeeded 
{
  // do reading or writing here
  myFile.close();
}
```
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/ios_base.png)

## Creating and Writing a Text File Using `open()` and `operator<<`
```c++
ofstream myFile;
myFile.open("HelloFile.txt", ios_base::out);
if(myFile.is_open()) {
  myFile << "My first text file!" << endl;  // write a line into the file
  myFile << "Hello file!";  // write another line into the file
}
myFile.close();
```

## Reading a Text File Using `open()` and `operator>>`
```c++
ifstream myFile;
myFile.open("HelloFile.txt", ios_base::in);
if(myFile.is_open()) {
  mstring fileContents;
  while(myFile.good()) {
    getline (myFile, fileContents);
    cout << fileContents << endl;
  }
}
myFile.close();
```

## Writing to and Reading from a Binary File
```c++
Human Input("Siddhartha Rao", 101, "May 1916");
ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);
if(fsOut.is_open()) {
  fsOut.write(reinterpret_cast<const char*>(&Input), sizeof(Input));
  fsOut.close();
}
ifstream fsIn ("MyBinary.bin", ios_base::in | ios_base::binary);
if(fsOut.is_open()) {
  Human somePerson;
  fsIn.read((char*)&somePerson, sizeof(somePerson));
}
```

## Using `std::stringstream` for String Conversions
To use class `std::stringstream`, include header: `#include <sstream>`
```c++
int input = 45;
stringstream converterStream;
converterStream << input; 
string inputAsStr;
converterStream >> inputAsStr;  // 45 -> inputAsStr: "45"

stringstream anotherStream;
anotherStream << inputAsStr;
int Copy = 0;
anotherStream >> Copy;  // "45" -> Copy: 45
```
