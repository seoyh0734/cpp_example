#include <iostream>
#include <malloc.h>

using namespace std;

class SizeTest {
  private:
    int _num;
    char* _str="asdasd";
  public:
    SizeTest(int num) {
      _num=num;
    }
    void printInfo() {
      cout << "num : " << _num << "str : " << _str << endl;
    }
};

int main(int argc, char** argv) {
  int arrSize=10;
  int* arr;

  arr = (int*) malloc(sizeof(int)*10);

  cout << sizeof(arr) << endl;
  cout <<  malloc_usable_size(arr) << endl;
  /* Windows 
  cout << _msize(arr) << endl;
  */
  cout << sizeof(int) << endl;

  SizeTest* arrSizeTest;
  int size=10;
  arrSizeTest = (SizeTest*) malloc(sizeof(SizeTest)*size); 
  for(int i=0; i<size; i++) {
    arrSizeTest[i]=SizeTest(i*10);
    arrSizeTest[i].printInfo();
  }
  cout << sizeof(SizeTest) << endl;
  cout <<  malloc_usable_size(arrSizeTest) << endl;
  cout << sizeof(char) << endl;
  return 0;
}
