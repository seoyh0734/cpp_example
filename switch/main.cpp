#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  int test = 10;

  switch (test)
  {
    case 0:
      cout << "zero" << endl;
      break;
    case 10:
      cout << "ten" << endl;
      break;
    case 20:
      cout << "twenty" << endl;
      break;
    case 30:
      cout << "thirteen" << endl;
      break;
  }
  return 0;
}
