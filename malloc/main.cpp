#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <cstdio>

int main(int argc, char* argv[])
{
  char* textList = NULL;

  textList = (char*) malloc(sizeof(char) * 10);
  fprintf(stderr, "[%s] malloc returned : %p\n", __FUNCTION__, textList);

  return 0;
}
