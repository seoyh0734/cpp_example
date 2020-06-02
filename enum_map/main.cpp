#include <iostream>
#include <map>

#define f(x) #x 

using namespace std;

enum MyEnum {
  FIRST = 1,
  SECOND,
  THIRD
};

char* enumToStr(MyEnum myEnum) {
  switch(myEnum) {
    case FIRST:
      return "FIRST";
    case SECOND:
      return "SECOND";
  }
}

int main(int argc, char* argv[]) {
  cout << "start" << endl;
  MyEnum myEnum = FIRST;
  cout << enumToStr(FIRST) << endl;

  char* str;
  str = f(myEnum);

  cout << str << endl;

  return 0;
}
