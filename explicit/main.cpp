/* g++ -o main main.cpp  && ./main */

#include <iostream>

class Integer {
 private:
  int value;

 public:
  Integer()
  {
    this->value = 100;
  }

  //Integer(explicit int value)  // Compile Error
  Integer(int value)
  {
    this->value = value;
  }

  void print()
  {
    std::cout << "value : " << value << std::endl;
  }
};


int main(int argc, char* argv[])
{
  long num = 10;

  Integer integer(num);
  integer.print();

  return 0;
}
