# Lesson 16 - The STL String Class

## The Need for String Manipulation Classes
Typically, to generate a string, the following two syntaxes have their own flaws:  
`char staticName [20];`    
`char* dynamicName = new char [arrayLen];`  

## Instantiating the STL String and Making Copies
```c++
const char* constCStyleString = "Hello String!";
// Initialization
std::string strFromConst(constCStyleString);
// or
std::string strFromConst = constCStyleString;
// or 
std::string str2("Hello String!");
// or 
std::string str2 = "Hello String!";

// use one string object to initialize another: 
std::string str2Copy (str2);

// Initialize a string to the first 5 characters of another 
std::string strPartialCopy (constCStyleString, 5);

// Initialize a string object to contain 10 'a's 
std::string strRepeatChars (10, 'a');
// or
std::string strRepeatChars (10, "day");
```

To use character strings to copy from another of the same kind:  
```c++
const char* constCStyleString = "Hello World!";

// To create a copy, first allocate memory for one... 
char* copy = new char [strlen (constCStyleString) + 1]; 

strcpy (copy, constCStyleString); // The copy step
// deallocate memory after using copy 
delete [] copy;
```

## Accessing Character Contents of a `std::string`
```c++
string stlString ("Hello String");

for(size_t charCounter = 0; charCounter < stlString.length(); ++ charCounter) {
  cout << stlString [charCounter] << endl;
}

// Access the contents of a string using iterators
for(auto charLocator = stlString.cbegin(); charLocator != stlString.cend(); ++ charLocator) {
  cout << *charLocator << endl;
}
```
> **Understand `size_t`**  
Alias of one of the fundamental **unsigned integer types**.  
`size_t` is the type returned by the `sizeof` operator and is widely used in the standard library to represent sizes and counts.  

## Concatenating One String to Another Using `append()`
```c++
string sampleStr1 ("Hello"); 
string sampleStr2 (" String! ");
// use std::string::operator+=
sampleStr1 += sampleStr2;
// alternatively use std::string::append() 
sampleStr1.append (sampleStr2); // (overloaded for char* too)
```

## Finding a Character or Substring in a String Using `find()`
```c++
// Find substring "day" in sampleStr, starting at position 0 
size_t charPos = sampleStr.find("day", 0);

// Check if the substring was found, compare against string::npos 
if (charPos != string::npos) {  // std::string::npos (that is actually –1)
  // ...
}

// find() all with while
while(charPos != string::npos) {
  // Make find() search forward from the next character onwards
  size_t searchOffset = charPos + 1;
  charPos = sampleStr.find ("day", searchOffset);
}
```

## Truncating an STL `string` Using `erase()`
`string sampleStr ("Hello String! Wake up to a beautiful day!");`  
* `sampleStr.erase (13, 28);  // Hello String!`
* `sampleStr.erase (iCharS);  // iterator points to a specific character`
* `sampleStr.erase (sampleStr.begin (), sampleStr.end ());  // erase from begin to end`

## String Reversal with `reverse()`
`reverse (sampleStr.begin (), sampleStr.end ());`

## String Case Conversion Using `transform()`
```c++
string inStr = "Hello World!";
// switch to upper case
transform(inStr.begin(), inStr.end(), inStr.begin(), ::toupper);
// switch to lower case
transform(inStr.begin(), inStr.end(), inStr.begin(), ::tolower);
```
**Read More: https://en.cppreference.com/w/cpp/algorithm/transform**

## Template-Based Implementation of an STL String
`template<class _Elem, class _Traits, class _Ax> class basic_string`

## C++14 `operator` `""s` in `std::string`
Operator ""s that convert the string contained within the quotes, in entirety.
```c++
string str1("Traditional string \0 initialization");  // Str1: Traditional string Length: 19
string str2("C++14 \0 initialization using literals"s);  // Str2: C++14 initialization using literals Length: 37
```

## Tips
* Remember to include `<algorithm>` when you use `std::reverse()`
* Can use `auto` to replace `std::string::iterator`
