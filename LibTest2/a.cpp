#include "a.h"

void aPrint() {
  std::cout << "aPrint Function called" << std::endl;
}

void aPrintP() {
  std::cout << "Not Static" << std::endl;
  aPrint();
}
