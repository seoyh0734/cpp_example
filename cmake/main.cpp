#include <iostream>

#include "src/ClassA.h"
#include "sharedLib/SharedClass.h"

using namespace std;

int main(int argc, char* argv[])
{
  A a;
  a.print();

  Share s;
  s.print();
  return 0;
}
