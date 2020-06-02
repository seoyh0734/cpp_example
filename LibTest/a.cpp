#include <stdio.h>
#include "a.h"

A::A() {
  this->num_ = 780;
}

void A::printA() {
  printf("num_ = %d\n", this->num_);
}

A* create() {
  A* a = new A();
  return a;
}

void destroy(A* a) {
  delete a;
}

void printA_(A* a) {
  a->printA();
}
