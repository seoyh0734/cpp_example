// g++ -o main main.cpp && ./main
#include <iostream>

class Parent
{
 protected:
  int num;
 public:
  Parent()
  {
    std::cout << "Parent()" << std::endl;
    this->num = 10;
  }

  ~Parent()
  {
    std::cout << "~Parent()" << std::endl;
  }

  virtual void print() // 1 Case
  //void print()       // 2 Case
  {
    std::cout << "Parent print()" << std::endl;
  }
};

class Child : Parent
{
 public:
  Child()
  {
    std::cout << "Child()" << std::endl;
  }

  ~Child()
  {
    std::cout << "~Child()" << std::endl;
  }

  void print()
  {
    std::cout << "Child print()" << std::endl;
  }
};

int main(int argc, char* argv[])
{
  int ret = -1;
  Child c;

  Parent *pPrt;
  pPrt = (Parent*)&c;
  pPrt->print();

  return ret;
}

/**
 * Output
 * ===============
 * 1 Case
 * Parent()
 * Child()
 * Child print() // virtual keyword makes call origin object function
 * ~Child()
 * ~Parent()
 *
 * 2 Case
 * Parent()
 * Child()
 * Parent print()
 * ~Child()
 * ~Parent()
 */
