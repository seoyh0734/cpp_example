#include <iostream>
#include <string>

class String : public std::string
{
 public:
  int n;
  String(const int i)
  {
    this->n = i;
  }

  String(const char* str1)
  {
    std::string(str1);
  }

  String operator=(__null)
  {
    return String(i);
  }

  String operator=(const char* str)
  {
    return String(str);
  }
};

int foo(std::string str)
{
  std::cout << "foo" << std::endl;
  if (str.empty() != false)
  {
    std::cout << str.c_str() <<std::endl;
    return 0;
  }

  return -1;
}

int main(int argc, char* argv[])
{
  std::cout << "main()" << std::endl;
  int ret = -1;

  String a = (int)NULL;
  std::cout << a.n << std::endl;

  String b = "test";
  std::cout << b.c_str() << std::endl;

  std::string testString;

  //foo(NULL);

  std::cout << "terminate main()" << std::endl;

  return ret;
}
