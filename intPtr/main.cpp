#include <iostream>

int main(int argc, char* argv[])
{
  int ret = -1;

  unsigned char lenInfo[2] = { 168, 2 };

  unsigned int oneB = (unsigned int)*(lenInfo + 1);
  std::cout << "oneB : " << oneB << std::endl;

  return ret;
}
