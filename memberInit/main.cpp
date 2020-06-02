#include <iostream>

using namespace std;

class A {
 public:
  const int num;
  const char* str;

  A() : num(1), str("char string") {
    cout << "construct" << endl;
  }

  void printInfo() { cout << num << " " << str << endl; }
};

int main(int argc, char** argv) {
  A a;
  a.printInfo();
  return 0;
}
