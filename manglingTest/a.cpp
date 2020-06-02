#include <iostream>
using namespace std;

extern "C" {

void printA() {
  cout << "printA()" << endl;
}

void printA(int a) {
  cout << "printA(int a) a = " << a << endl;
}
}
