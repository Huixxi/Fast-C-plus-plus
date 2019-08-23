![Source: https://www.geeksforgeeks.org/c-plus-plus/](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/images/c_plusplus.png)
# A Fast C++ Tutorial For Beginners.
C++ is a very important programming language, even though python is really hot in today's AI context.

## Introduction.
This is a basic tutorial of C++ for beginners. From **Basic Datatypes** to **Standard Template Library(STL)**.   
It is mainly based on the book [C++ in One Hour a Day, Sams Teach Yourself(8th Edition)][2].

## C++ IDE Recommend
* [Visual Studio](https://visualstudio.microsoft.com/) is highly recommended if you do c++ development on Windows or Mac. It is free(the community version), and powerful, which is suited to large project development.
* [Clion](https://www.jetbrains.com/clion/) is also highly recommended. It is cross-platform(pc, mac, linux), powerful and  easy to compile and debug. But it is not free and don't have the community version. If you are a student, you can apply for a free individual license for one year.
* Some lightweight tools: [Code Blocks](http://www.codeblocks.org/) | [Visual Studio Code](https://code.visualstudio.com/) |  [Qt, open source version](https://www.qt.io/developers/)
* Online IDE runs in browser: [Cpp Online](http://www.tutorialspoint.com/compile_cpp_online.php)

## Trouble Shoot During Clion Installation
Error after you type in you username and password: `Can not connect to the remove sever, ...`, then you should edit your hosts file(`/etc/hosts` on Linux) to comment the urls that related to `JetBrains`.

## Hello World!
``` c++
#include <iostream>

int main(){
  std::cout << "Hello World!" << std::endl;
  return 0;
}
```
## Tutorial Catalogue
First, I assume that you have some basic knowledge of C or C++.  
Before we start, let's walk through the [Basic Introduction About C++](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/00%20Basic%20C%2B%2B.cpp) roughly to recall some basic and important points. (All the codes in this introduction are from this tutorial video: https://www.youtube.com/watch?v=vLnPwxZdW4Y, I just sort the video content into text form.)
* Part I, The Basics.
  * [Lesson 1 - Getting Start](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/01%20Lesson1%20Notes.md)
  * [Lesson 2 - The Anatomy of a C++ Program](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/02%20Lesson2%20Notes.md)
  * [Lesson 3 - Using Variables, Declaring Constants](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/03%20Lesson3%20Notes.md)
  * [Lesson 4 - Managing Arrays and Strings](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/04%20Lesson4%20Notes.md)
  * [Lesson 5 - Working with Expressions, Statements, and Operators](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/05%20Lesson5%20Notes.md)
  * [Lesson 6 - Controlling Program Flow](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/06%20Lesson6%20Notes.md)
  * [Lesson 7 - Organizing Code with Functions](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/07%20Lesson7%20Notes.md)
  * [Lesson 8 - Pointers and References Explained](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/08%20Lesson8%20Notes.md)

* Part II, Fundamentals of Object-Oriented C++ Programming.
  * [Lesson 9 - Classes and Objects](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/09%20Lesson9%20Noets.md)
  * [Lesson 10 - Implementing Inheritance](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/10%20Lesson10%20Notes.md)
  * [Lesson 11 - Polymorphism](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/11%20Lesson11%20Notes.md)
  * [Lesson 12 - Operator Types and Operator Overloading](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/12%20Lesson12%20Notes.md)
  * [Lesson 13 - Casting Operators](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/13%20Lesson13%20Notes.md)
  * [Lesson 14 - An Introduction to Macros and Templates](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/14%20Lesson14%20Notes.md)

* Part III, Learning the Standard Template Library (STL).
  * [Lesson 15 - An Introduction to the Standard Template Library](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/15%20Lesson15%20Notes.md)
  * [Lesson 16 - STL String Class](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/16%20Lesson16%20Notes.md)
  * [Lesson 17 - STL Dynamic Array Classes](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/17%20Lesson17%20Notes.md)
  * [Lesson 18 - STL List Classes](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/18%20Lesson18%20Notes.md)
  * [Lesson 19 - STL Set Classes](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/19%20Lesson19%20Notes.md)
  * [Lesson 20 - STL Map Classes](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/20%20Lesson20%20Notes.md)

* Part IV, More STL.

* Part V, Advanced C++ Concepts.











[1]: https://www.youtube.com/playlist?list=PLGLfVvz_LVvQ9S8YSV0iDsuEU8v11yP9M
[2]: https://www.amazon.com/One-Hour-Sams-Teach-Yourself/dp/0789757745/ref=as_li_ss_tl?ie=UTF8&qid=1520641767&sr=8-9&keywords=C++&linkCode=sl1&tag=nethta-20&linkId=4bddb996d7f5ff86f0fbaf4647594d32

