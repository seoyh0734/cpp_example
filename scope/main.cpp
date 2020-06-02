#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  goto test;  
  return 0;

  test:
  {
    cout << "test!!" << endl;
  }

  test2:
  {
    cout << "test2!!" << endl;
  }
}
