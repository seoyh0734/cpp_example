#include <iostream>

using namespace std;

class A {
 public:
  int num_;

  A() {
    cout << "create A" << endl;
    this->num_=1;
  }

  virtual ~A() {
    cout << "delete A" << endl;
  }

  A(const A& a) {
    cout << "copy A" << endl;
    num_ = a.num_;
  }

  A(const A&& a) {
    cout << "move A" << endl;
    num_ = a.num_;
  }

  virtual void printInfo() { cout << "class A " << this->num_ << endl; }
};

class B : public A {
 public:
  B() {
    cout << "create B" << endl;
    this->num_=2;
  }
  void printInfo() {
    cout << "class B " << this->num_ << endl;
  }

  ~B() {
    cout << "delete B" << endl;
  }
};

int main(int argc, char** argv) {
  B b;
  A a = (A&&)(b);
  a.printInfo();

  A* ap = new B;
  ap->printInfo();
}
