#include <iostream>

#define FUNC_NAME testFunctionTEMP_MAC

#define STR "string"

int FUNC_NAME()
{
  std::cout << __func__ << std::endl;

  return 0;
}

int main(int argc, char* argv[])
{
  int ret = -1;

  FUNC_NAME();

  std::cout << STR STR << std::endl;
  std::cout << "string""string" << std::endl;
  return ret;
}
