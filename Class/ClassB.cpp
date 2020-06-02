#include "ClassB.h"
#include <iostream>

using namespace std;

ClassB::ClassB(int a, int b) : ClassA(a,b) {
  a=3;
};

void ClassB::printInfo() {
  cout << this->a << endl;
  cout << this->b << endl;  
};
