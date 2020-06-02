#include <iostream>
#include <string.h>

using namespace std;

class A {
 public:
  static int cnt_;
  static const char str[100];
  int num_;
  char* name_;

  A() {
    cout << "construct" << endl;
    num_= cnt_++;
    name_ = new char[strlen(str)+1];
    strcpy(name_, str);
  }

  A(const A &a) {
    cout << "copy construct" << endl;
    num_ = a.num_;
    name_ = new char[strlen(a.name_)+1];
    name_ = strcpy(name_, a.name_);
  }

  ~A() {
    cout << "destrunct" << endl;
    delete name_;
  }

  void print() {
    cout << "num_ = " << num_ << "\nname_ = " << name_ << endl;
  }
};

int A::cnt_ = 1;
const char A::str[100] = "hello!!";

int main(int argc, char* argv[]) {
  A a = A();

  a.print();

//  A a2 = a;
//
//  a.num_ = 2;
//  strcpy(a.name_, "Bello");
//
//  a2.print();

  return 0;
}
