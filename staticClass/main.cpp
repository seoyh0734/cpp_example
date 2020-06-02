#include <iostream>

class A {
 public:
  const int& num=13;

  A() {
    int& tnum = const_cast<int&>(num);
    tnum=20;
  }

  void print() {
    std::cout << num << std::endl;
  }
};
//int A::num = 10;

int main(int argc, char** argv) {
  A a;
  a.print();

  return 0;
}
