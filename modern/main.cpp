#include <iostream>
#include "myEnum.h"

enum myEnum : int;

struct MyClass
{
 public:
  MyClass() = default;
  MyClass(size_t s_arg, enum myEnum e_arg) : e{e_arg}, s(s_arg)
  {
  }
  enum myEnum e;
  size_t s{5};
};


int main(int argc, char* argv[])
{
 //struct MyClass m(1, ZERO);
 struct MyClass m;

 std::cout << m.s << std::endl;

  return 0;
}
