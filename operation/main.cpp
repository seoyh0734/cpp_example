#include <iostream>

int main(int argc, char** argv)
{
  for (int i=0; i<3; i++)
  {
    std::cout << i << std::endl;
  }

  for (int i=0; i<3; ++i)
  {
    std::cout << i << std::endl;
  }

  return 0;
}
