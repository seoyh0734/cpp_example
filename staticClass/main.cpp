#include <iostream>

class A {
 public:
  const int& num=13;

  A() {
    std::cout << "A()" << std::endl;
    int& tnum = const_cast<int&>(num);
    tnum=20;
  }

  ~A()
  {
    std::cout << "~A()" << std::endl;
  }

  void print() {
    std::cout << num << std::endl;
  }
};

class B
{
  public:
  B()
  {
    std::cout << "B()" << std::endl;
  }
   static A a;
};

A B::a;

int main(int argc, char** argv) {

  for (int i=0; i < 10; i++)
  {
  B b;
  b.a.print();
  }
  return 0;
}
