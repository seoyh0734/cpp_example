#include <iostream>

#define MY_FLAG
#define MY_VER 100

int main(int argc, char** argv)
{
//#if not defined(MY_FLAG) && MY_VER >= 100
#if not MY_VER >= 100 || defined(MY_FLAG)
  std::cout << "TRUE" << std::endl;
#else
  std::cout << "FALSE" << std::endl;
#endif
  return 0;
}
