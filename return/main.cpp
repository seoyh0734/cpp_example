#include <iostream>

int funcA()
{
  std::cout << "funcA()" << std::endl;
  return 6;
}

int funcB()
{
  std::cout << "funcB()" << std::endl;
  return 0;
}

int main(int argc, char* argv[])
{
  int ret = -1;

  if ((ret = funcA()) != 0 ||
      (ret = funcB() != 0))
  {
    std::cout << "ret : " << ret << std::endl;
  }

  return 0;
}
