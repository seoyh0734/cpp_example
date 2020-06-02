#include <iostream>

using namespace std;

extern void printA();
extern void printA(int);

int main(int argc, char** argv) {
  printA();
  printA(3);

  return 0;
}
