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
Before we start, let's walk through the [Basic Introduction About C++](https://github.com/Huixxi/Fast-C-plus-plus/blob/master/00%20Basic%20C++.md) roughly to recall some basic and important points. (All the codes in this introduction are from this tutorial video: https://www.youtube.com/watch?v=vLnPwxZdW4Y, I just sort the video content into text form.)
* Part I, The Basics.

* Part II, Fundamentals of Object-Oriented C++ Programming.

* Part III, Learning the Standard Template Library (STL).

* Part IV, More STL.

* Part V, Advanced C++ Concepts.











[1]: https://www.youtube.com/playlist?list=PLGLfVvz_LVvQ9S8YSV0iDsuEU8v11yP9M
[2]: https://www.amazon.com/One-Hour-Sams-Teach-Yourself/dp/0789757745/ref=as_li_ss_tl?ie=UTF8&qid=1520641767&sr=8-9&keywords=C++&linkCode=sl1&tag=nethta-20&linkId=4bddb996d7f5ff86f0fbaf4647594d32

