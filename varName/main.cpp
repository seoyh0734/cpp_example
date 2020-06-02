#include <iostream>
#include <typeinfo>
#include <string>
#include <wchar.h>

using namespace std;

#define f(x) #x

int main(int argc, char** argv) {
  char c = -1;
  wchar_t wc;

  char star1 = '☆';
  printf("%c\n", star1);
  char* star = "☆";
  printf("%s\n", star);

  setlocale(LC_ALL, "");

  wchar_t wstar = L"☆";
  printf("%ls\n",wstar);

  string str = "test";
  cout << str << endl;
  cout << typeid(str[0]).name() << endl;

  return 0;
}
