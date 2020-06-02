#include <iostream>
#include <cstdio>

int main(int argc, char* argv[])
{
  unsigned char a = 0;
  a = ~1;
  printf("%d\n", a & 0xff);
  return 0;
}
