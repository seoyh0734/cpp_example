#include "staticFunc.h"

void staticFunc() {
  static int staticVar = 0;
  cout << staticVar++ << endl;
}

int main(int argc, char **argv) {
  staticFunc();
  staticFunc();
  staticFunc();
  return 0;
}
