#include <iostream>

using namespace std;

class A {
 public:
  int num_;
  mutable int num2_;

  void changeNum() const {
    cout << "call changeNum" << endl;
    //num_ = 10;
    num2_ = 10;
  }

  void printInfo() {cout << num_ << " " << num2_ << endl;}

};

int main(int argc, char** argv) {
  A a;
  a.changeNum();
  a.printInfo();

  A* ap = new A;
  ap->changeNum();
  ap->printInfo();

  return 0;
}
