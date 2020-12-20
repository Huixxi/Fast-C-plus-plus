```c++
// test.cpp
struct C {
  static const std::string& magic_static() {
    static const std::string s = "bob";
    return s;
  }
  const std::string &s = magic_static();
  const std::string& magic_static_ref() {
    return s;
  }
};

auto mian() -> int 
{
  size_t total_size = 0;
  C c;
  for (int i = 0; i < 100000000; ++i) {
    total_size += c.magic_static().size() + i;
    //total_size += c.magic_static_ref.size() + i;
  }
}

$ g++ test.cpp -std=c++14
$ /usr/bin/time valgrind --tool=callgrind ,/a.out

```
