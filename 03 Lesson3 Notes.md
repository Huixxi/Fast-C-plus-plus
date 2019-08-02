## Lesson 3 - Using Variables, Declaring Constants
**Variables** are tools that help the programmer temporarily store data for a finite amount of time. **Constants** are tools that help the programmer define artifacts that are not allowed to change or make changes.  

## Memory and Addressing in Brief 
All computers, smart phones, and other programmable devices contain a microprocessor and a certain amount of memory for temporary storage called **Random Access Memory (RAM)**. 
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/what_is_ram.png)
The RAM itself can be considered to be a storage area akin to a row of lockers in the dorms, each locker having a number—that is, an **address**.
![](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/ram_address.png)

## Declaring Variables to Access and Use Memory
**Defining a variable:**  
* `VariableType VariableName;`   
or:  
* `VariableType VariableName = InitialValue;`

(It is always good to give the variable an `InitialValue`, rather than leave it with an unknown value of that memory location which can be bad for the program.)  
The `VariableType` attribute tells the compiler <u>*the nature of data the variable can store*</u>, and the compiler <u>*reserves the necessary space for it*</u>. The `VariableName` chosen by the programmer is <u>*a friendly replacement for the address*</u> in the memory where the variable’s value is stored, i.e. a readable name not a confusing address number.
