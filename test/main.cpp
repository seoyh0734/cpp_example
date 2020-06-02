#include <iostream>
#include <vector>
#include <typeinfo>
#include <functional>

using namespace std;

void test1(string str)
{

  cout << str << endl;
  char* cs = "123123312";
  cout << cs << endl;
  str = cs; 
}

enum tenum {
  A=100,
  B,
  C=200,
  D
};

int test2(int i, int j=0, char c='i')
{
  int a = 5;
  cout << oct << a+i << c << endl;
  cout << dec << a+i << c << endl;
  cout << hex << a+i << c << endl;
  return 0;
}

int main(int argc, char** argv)
{
  cout << A << endl;
  cout << B << endl;
  cout << C << endl;
  cout << D << endl;
  //int scanI = 0;
  //cout << "Input : ";
  //cin >> scanI;
  //test2(scanI);
  return 0;
}
