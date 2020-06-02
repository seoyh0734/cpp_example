#include <iostream>

class A {
 public:
  A(int _num) : num(_num) {
  }
  const int num;
  A getInstance()
  {
    return A();
  }

};

class B {
 private:
  A a;
 public:
  B()
  {
    this->a = A(10);
  }
};

int main(int argc, char* argv[])
{
  B b;
  return 0;
}
