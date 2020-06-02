#include "myClass.cpp"

bool  myClass::status = false;
int main(int argc, char* argv[]) {
  myClass* myclass = new myClass[3];

  delete[] myclass;
  return 0;
}
