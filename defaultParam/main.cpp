#include <iostream>

using namespace std;

void printT(int a = 10, int b = 20) {
  cout << "a  = " << a << "b = " << b << endl;
}

int main(int argc, char** argv) {
  printT(5, 10);

  return 0;
}
