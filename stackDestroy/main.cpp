#include <iostream>

class Object
{
  public:
  int num;
  Object()
  {
    num=10;
    std::cout << "Object()" << std::endl;
  }
  ~Object()
  {
    num=0;
    std::cout << "~Object()" << std::endl;
  }
};

void func1()
{
  Object *object = new Object();
  int *ptr = &Object->num;
  delete object;
}

int main(int argc, char*argv[])
{
  int ret = -1;

  func1();
  return ret;
}
