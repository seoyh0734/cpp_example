#include <iostream>

using namespace std;

class A {
 public:
  int a;
  int* ap;

  A() {
    cout << "construct" << endl;
    a = 1;
    ap = new int(2);
  }

  A(A&& rhs) {
    cout << "move construct" << endl;
    this->a = rhs.a;
    this->ap = rhs.ap;
    rhs.ap = NULL;
  }

  ~A() {
    cout << "destruct" << endl;
    if(ap)
    delete ap;
  }

  void printA() {
    cout << "a = " << a << " b = " << *ap << endl;
  }

};

int main(int argc, char** argv) {
  A a;
  a.printA();

  A a1 = move(a);

  a1.printA();

  A a2;

  a2 = (A&&) a;

  return 0;
}
