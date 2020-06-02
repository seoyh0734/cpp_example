#include <iostream>

class myClass
{
 private:
  static bool status;
  static int num;

 public:
  myClass() {
    std::cout << "contruct myClass() : " << ++num << std::endl;
  }

  ~myClass() {
    std::cout << "decontruct myClass() : " << num-- << std::endl;
  }

  static void printInfo() {
    std::cout << "printInfo" << std::endl;
    if (status) {
      std::cout << "status == true" << std::endl;
    }
    else {
      std::cout << "status == false" << std::endl;
      status = true;
    }
  }
};

//bool myClass::status = false;
int myClass::num = 0;
