#include <iostream>

using namespace std;

class A {
 public:
  int a;
  int& af = a;

  A() {
    a = 10;
  }
};

int setArray(int* arr, int arrNum)
{
  arr[0] = 97;
  return 0;
}

int main(int argc, char** argv) {
  // 1
  //int a = 10;
  //int& af = a;

  //a = 20;
  //cout << a << " " << af << endl;

  // 2
  int arrNum = 10;
  int arr[1] = { 0, };
  std::cout << "arr : " << arr << std::endl;
  std::cout << "&arr : " << &arr << std::endl;
  std::cout << "*arr : " << *arr << std::endl;

  setArray(arr, arrNum);
  std::cout << arr[0] << std::endl;

  std::cout << (char*)&arr << std::endl;

  return 0;
}
