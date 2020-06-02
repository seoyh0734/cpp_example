#include <iostream>

int add(int a, int b)
{
  return a + b;
}

class calc
{
 public:
  static int add(int a, int b)
  {
    return a + b;
  }
};

int main(int argc, char* argv[])
{
  int ret = -1;

  int (*function)(int, int);
  //function = calc::add;  // Have to static method
  function = add;

  int c = function(1, 2);

  std::cout << c << std::endl;

  return ret;
}
