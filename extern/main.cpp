#include <iostream>
#include "extern.h"

extern int X;

int main(int argc, char* argv[])
{
  int ret = 1;
  std::cout << "main X : " << X << std::endl;
  printX();
  return ret;
}
