#include <iostream>

void printHexStdErr(char* data, unsigned int size) {

  for (unsigned int i=0; i<size; i++)
  {
    std::cerr << std::hex << (int)data[i] << std::dec << ' ';
  }
  std::cerr << std::endl;

  return;
}

int main(int argc, char** argv)
{
  std::cout << "main" << std::endl;

  char str[] = "asdasdasdjaklsjdklasd";

  printHex(str, sizeof(str));
  return 0;
}
