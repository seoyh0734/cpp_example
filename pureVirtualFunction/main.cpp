#include <iostream>

using namespace std;

class A { 
 public:
  int a;

 virtual void printMe() = 0;
};

void A::printMe() {
  cout << a << "virtual" << endl;
}

class B : public A {
 public:
 void printMe() {
   A::printMe();
 }
};

int main(int argc, char** argv) {
  B b;
  b.printMe();
  return 0;
}
