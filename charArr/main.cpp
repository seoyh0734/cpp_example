#include <iostream>

#define BUFF_MAX_LEN 500

int testCharArrWithPtr();

int main(int argc, char* argv[])
{
  int ret = -1;
  
  //ret = testCharArrWithPtr();

  char* test;
  test = "asd";

  std::cout << test << std::endl;

  return ret;
}

int testCharArrWithPtr()
{
  int ret = -1;

  char* strArr[] = {"test1", "test2", "test3", "test4"};
  int num = 0;

  std::cout << "char* strArr[3] = {\"test1\", \"test2\"};" << std::endl;
  std::cout << "sizeof(strArr) : " << sizeof(strArr) << std::endl;
  std::cout << "strArr : " << strArr << std::endl;
  std::cout << "sizeof(strArr[0]) : " << sizeof(strArr[0]) << std::endl;
  std::cout << "strArr[0] : " << strArr[0] << std::endl;
  std::cout << "sizeof(num) : " << sizeof(num) << std::endl;

  return ret;
}
