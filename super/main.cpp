#include <iostream>

class Base
{
 public:
  int age;
  void printInfo()
  {
    this->age = 10;
    std::cout << "Base Info : " << this->age << std::endl;
  }
};

class Derived : public Base
{
 public:
 typedef Base super;
  void printInfo()
  {
    super::printInfo();
    this->age = 20;
    std::cout << "Derived Info : " << this->age << std::endl;
  }
};

int main(int argc, char* argv[])
{
  int ret = -1;

  Derived derived;
  derived.printInfo();

  return ret;
}
