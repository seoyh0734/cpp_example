#include <iostream>

using namespace std;

void printT(int a = 10, int b = 5) {
  cout << "a  = " << a << std::endl << "b = " << b << endl;
}

int main(int argc, char** argv) {
  printT(11);

  return 0;
}
