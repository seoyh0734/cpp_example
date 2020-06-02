#include <iostream>
#include "staticClass.h"

int main(int argc, char* argv[]) {
  //std::cout <<  staticClass::i << std::endl;
  unsigned int* i = new unsigned int(12);

  std::cout << *i << std::endl;
  return 0;
}

