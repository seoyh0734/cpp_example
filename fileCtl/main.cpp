#include <iostream>
#include <stdio.h>

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
  FILE *file;
  char *fileName = "test.txt";
  struct stat StBuf;

  file = open(fileName, O_CREAT|O_WRONLY|O_TRUNC,StBuf.st_mode & 0x777);
  if (file == NULL)
  {
    std::cout << "Can not open file" << std::endl;
    return -1;
  }

  fprintf(file, "abcde");

  fclose(file);

  return 0;
}
