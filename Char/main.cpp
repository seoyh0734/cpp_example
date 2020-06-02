#include <iostream>
#include <string.h>

using namespace std;

class MyClass {
  public : 
    static string name;
    static const string c_name; 

    MyClass() {
      cout << "constructor" << endl;
    }
};

string MyClass::name = "static";
const string MyClass::c_name = "static const";

int main(int argc, char** argv) {
  MyClass myClass;

  myClass.name = "MyClass";

  cout << myClass.name.c_str() << endl;
  cout << myClass.c_name.c_str() << endl;
  return 0;
}
