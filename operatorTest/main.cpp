#include <iostream>

class Example {
 public:
  int num;
 public:
  Example operator+(Example rightExample)
  {
    Example example;
    example.num = this->num + rightExample.num;
    return example;
  }

};

int operator-(Example leftExample, Example rightExample)
{
  return leftExample.num - rightExample.num;
}

int main(int argc, char* argv[])
{
  Example a, b, c;

  std::cin >> a.num >> b.num;

  c = a + b;

  std::cout << c.num << std::endl;

  int value = a - b;
  std::cout << value << std::endl;

  return 0;
}
