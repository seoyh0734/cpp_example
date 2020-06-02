#include <iostream>
#include <functional>
using namespace std;

class A {
 public:
  int num_;

  A() {
    num_ = 0;
  }

  int print(int i) {
    cout << "num = " << num_ << "int = " << i << endl;
  }
};

int main(int argc, char** argv) {
  A a;
  function<int(A&, int)> f = &A::print;
  f(a,1);

  return 0;
}
