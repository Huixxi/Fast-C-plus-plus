# Lesson 6 - Controlling Program Flow

## Conditional Execution Using `if … else`
```
if (conditional expression) {
  Do something when expression evaluates true;
}
else if (conditional expression) {
  Do something when expression evaluates true;
}
// Optional
else {
  Do something else when condition evaluates false;
}
```

## Conditional Processing Using `switch-case`
**DO** use *enumerators* in switch expressions to make code readable.
```
switch(expression) {
  case LabelA: 
    DoSomething; 
    break;  // keep in mind.

  case LabelB:
    DoSomethingElse; 
    break;
    
  // And so on... 
  default:  // keep in mind.
    DoStuffWhenExpressionIsNotHandledAbove; 
    break;
}
```

## Conditional Execution Using Operator (`?:`)
`(conditional expression evaluated to bool) ? expression1 if true : expression2 if false;`  
For example:  
```c++
int max = (num1 > num2) ? num1 : num2; // max contains greater of num1 and num2
```

___

## A Rudimentary Loop Using `goto`
```
SomeFunction() {
Start: // Called a label 
  CodeThatRepeats;
  
  goto Start;
}
```
You declare a label called Start and use goto to repeat execution from this point on. (`goto` is not the recommended form of programming loops)

## The `while` Loop
```
while(expression) {
  // Expression evaluates to true 
  StatementBlock;
}
```

## The `do…while` Loop
```
do {
  StatementBlock; // executed at least once 
} while(condition); // ends loop if condition evaluates to false
```

## The `for` Loop
```
for (initial expression executed only once; exit condition executed at the beginning of every loop; 
     loop expression executed at the end of every loop) { 
  DoSomething; 
}
```
For examples:  
```c++
// loop for array.
const int ARRAY_LENGTH = 5;
int myNums[ARRAY_LENGTH] = {0};
for (int counter = 0; counter < ARRAY_LENGTH; ++counter) {
  cout << "Element " << counter << " = " << myNums[counter] << endl;
}

// without loop expression (third expression missing) 
for (char userSelection = 'm'; userSelection != 'x';) {
  // ...
}
```

## The Range-Based `for` Loop
```
for (VarType varName : sequence) {
  // Use varName that contains an element from sequence 
}
```
For example:  
```c++
int someNums[] = { 1, 101, -1, 40, 2040 };
for (int aNum : someNums) // range based for loop
  cout << "The array elements are " << aNum << endl;
```
So there is the best place to use `auto`:  
```c++
for (auto anElement : elements) {
  // range based for loop 
  cout << "Array elements are " << anElement << endl;
}
```

## Modifying Loop Behavior Using `continue` and `break`

## Infinite Loops
```c++
// An infinite `while` loop:
while(true)  // while expression fixed to true
{
  DoSomethingRepeatedly; 
}

// An infinite `do...while` loop 
do {
  DoSomethingRepeatedly; 
} while(true);  // do…while expression never evaluates to false

// An infinite `for` loop
for (;;)  // no condition supplied = unending for 
{
  DoSomethingRepeatedly; 
}
```
Controlling it by inserting a `break` (typically used within an `if (condition)` block).

## Nested Loops(Loop in Loop)
```c++
for (int row = 0; row < NUM_ROWS; ++row) {
  for (int column = 0; column < NUM_COLUMNS; ++column) {
    // ...
  }
}
```

