#include <iostream>

#define FUNC_NAME testFunctionTEMP_MAC

int FUNC_NAME()
{
  std::cout << __func__ << std::endl;

  return 0;
}

int main(int argc, char* argv[])
{
  int ret = -1;

  FUNC_NAME();
  return ret;
}
