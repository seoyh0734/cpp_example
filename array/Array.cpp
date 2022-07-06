#include <iostream>

class TestA {
 public:
  TestA()
  {
    std::cout << "TestA" << std::endl;
  }

  ~TestA()
  {
    std::cout << "~TestA" << std::endl;
  }
};

int main(int argc, char** argv)
{
  TestA aList[10];
  return 0;
}

