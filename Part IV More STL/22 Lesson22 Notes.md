# Lesson 22 - Lambda Expressions
Lambda expressions are a compact way to define and construct function objects without a name.   
The definition of a lambda expression has to start with square brackets`[]`.

## Lambda Expression for a Unary Function
`[](Type paramName) { // lambda expression code here; }`   
Or pass the parameter by reference if you want to do some changes to the parameter:   
`[](Type& paramName) { // lambda expression code here; }`  

```c++
std::list<char> charsInList{ 'a', 'z', 'k', 'd' };
for_each(charsInList.begin(),
         charsInList.end(),
         [](auto& element) { cout << element << ' '; });
// The compiler would interpret this lambda expression as: 
// [](const char& element) { cout << element << ' '; }
```

## Lambda Expression for a Unary Predicate
`[](int& num) { return ((num % 2) == 0); }  // the return value type is a bool: true or false`
```c++
auto evenNum = find_if(numsInVec.begin(), 
                       numsInVec.end(), 
                       [](const int& num){ return ((num % 2) == 0); });
```
> Remember to use `const` for input parameters, especially when they’re a reference to avoid unintentional changes to the value of elements in a container.

## Lambda Expression with State via Capture Lists `[...]`
```
int divisor = 2; // initial value
auto element = find_if(numsInVec.begin(),
                       numsInVec.end(), 
                       [divisor](int dividend){ return (dividend % divisor) == 0; } );
// divisor is the state-variable
```
A list of arguments transferred as state variables `[...]` is also called the lambda’s capture list.

## The Generic Syntax of Lambda Expressions
A lambda expression always starts with square brackets:
* Taking multiple state variables  
`[stateVar1, stateVar2](Type& param) { // lambda code here; }`  
* Using keyword `mutable` to ensure these state variables are modified within a lambda  
`[stateVar1, stateVar2](Type& param) mutable { // lambda code here; }`
* Using references to ensure that modifications made to the state variables within the lambda are valid outside it, too  
`[&stateVar1, &stateVar2](Type& param) { // lambda code here; }`  
* Taking multiple input parameters  
`[stateVar1, stateVar2](Type1& var1, Type2& var2) { // lambda code here; }`
* Using `->` to mention the return type  
`[stateVar1, stateVar2](Type1 var1, Type2 var2) -> ReturnType { return (value or expression); }`
* Compound statement `{}` can hold multiple statements   
`[stateVar1, stateVar2](Type1 var1, Type2 var2) -> ReturnType `
`{`  
  `  Statement 1;`  
  `  Statement 2;`  
  `  return (value or expression);`  
`}`  
> If your lambda expression spans multiple lines, you are required to supply an explicit return type.

## Lambda Expression for a Binary Function
`[...](Type1& param1Name, Type2& param2Name) { // lambda code here; }`  
```c++
transform(multiplicands.begin (),  // range of multiplicands
          multiplicands.end (),  // end of range
          multipliers.begin (),  // multiplier values
          vecResult.begin (),  // holds result
          [](int a, int b) { return a * b; } );  // lambda
```

## Lambda Expression for a Binary Predicate
`[...](Type1& param1Name, Type2& param2Name) { // return bool expression; }`  
```c++
sort(names.begin(), names.end(), 
     [](const string& str1, const string& str2) -> bool 
     {
       string str1LowerCase;
       // Assign space 
       str1LowerCase.resize(str1.size()); 
       // Convert every character to the lower case
       transform(str1.begin(), str1.end(), str1LowerCase.begin(), ::tolower);
       string str2LowerCase; 
       str2LowerCase.resize (str2.size());
       transform(str2.begin(), str2.end(), str2LowerCase.begin(), ::tolower);
       return (str1LowerCase < str2LowerCase);
     }  // end of lambda
    );  // end of sort
```
