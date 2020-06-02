#include <iostream>
//#include "a.h"

using namespace std;

extern int a;
extern int b;

int main(int argc, char** argv) {
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  return 0;
}
