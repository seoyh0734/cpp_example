#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  char str[] = "testString";
  const char* ptr = str;

  //ptr[0] = 'z';
  
  char* c = const_cast<char*>(ptr);
  c[0] = 'z';

  cout << ptr << endl;

  int i = 10;
  const int& ri = i;

  //ri = 20; // error, because of read-only.

  int& ci = const_cast<int&>(ri);

  ci = 20;

  cout << ri << endl;

  return 0;
}
