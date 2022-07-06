#include <iostream>
#include <cstdio>
#include <cstring>
int main(int argc, char* argv[])
{
  char str[2] = {255, 0};
  unsigned char ptr[2] = {255, 0};
  int ret = memcmp(&str, &ptr, 2);
  std::cout << ret << std::endl;
  if (ret == 0)
  {
    std::cout << "Same" << std::endl;
  }

  unsigned char test = '2';
  printf("%d\n", test);

  return 0;
}
