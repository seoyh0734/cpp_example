#include <iostream>

//class Test {
//  public:
//  int num;
//};

typedef int Test;

int main(int argc, char* argv[])
{
#ifdef Test
  std::cout << "Test Class Defined" << std::endl;
#else
  std::cout << "Test Class not Defined" << std::endl;
#endif

  return 0;
}
