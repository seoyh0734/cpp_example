#include <iostream>
//#include <tuple>
#include <memory>

int main(int argc, char* argv[])
{
  int a,b;
  std::tie(a,b) = std::make_pair(2, 3);
  std::cout << a << b << std::endl;
  return 0;
}
