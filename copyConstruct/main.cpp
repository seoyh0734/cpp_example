#include <iostream>

using namespace std;

class A {
 public:
  int a;
  int* b;

  A() {
    cout << "construct" << endl;
    a = 10;
    b = new int(10);
  }

  A(const A& a) {
    cout << "copy construct" << endl;
    this->a = a.a;
    this->b = new int;
    *(this->b) = *(a.b);
  }

  void printA() {
    cout << "a = " << a << " b = " << *b << endl;
  }
};

int main(int argc, char** argv) {
  A a;
  a.printA();

  A a1 = A(a);
  a.a = 20;
  *(a.b) = 30;
  a.printA();
  a1.printA();
  return 0;
}
