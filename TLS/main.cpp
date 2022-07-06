#include <iostream>
#include <thread>
#include <cstring>

class testClass {
  public:
  static __thread int a;
};

__thread int testClass::a = 10;

__thread int gInt = 0;
__thread char str[124] = "";

void testFunc(int no)
{
  std::cout << "testFunc : " << no << std::endl;
  std::cout << "gInt : " << gInt++ << std::endl;
  std::cout << "gInt : " << gInt++ << std::endl;
  std::cout << "str : " << str << std::endl;
  std::cout << "testClass::a : " << testClass::a++ << std::endl;
}

int main(int argc, char** argv)
{
  std::cout << "main" << std::endl;

  std::cout << "testClass::a : " << testClass::a++ << std::endl;

  gInt = 10;

  std::cout << "gInt : " << gInt++ << std::endl;
  strcpy(str, "test");
  std::cout << "str : " << str << std::endl;

  std::thread thd(testFunc, 1);
  std::thread thd2(testFunc, 2);
  thd.join();
  thd2.join();
  return 0;
}
