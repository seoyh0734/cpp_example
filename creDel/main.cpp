#include <iostream>
#include <string.h>

using namespace std;


class MyClass {

  private : 
    int num;
    char name[100];

  public :
    MyClass() {
      cout << "constructor" << endl;
      num = 100;
      cout << "end constructor" << endl;
     }

     MyClass(int num, char name[100]) {
       cout << "constructor2" << endl;
       this->num = num;
       strncpy(this->name, name, 100);
       cout << "end constructor2" << endl;

     }

    ~MyClass() {
      cout << "Destructor" << endl;
      cout << "End destructor" << endl;
    }

    int getNum() {
      return this->num;
    }
};

int main(int argc, char** argv) {
  MyClass myClass;
  cout << myClass.getNum() << endl;
  
  MyClass myClass2(200,"test");
  cout << myClass2.getNum() << endl;

  MyClass *pMyClass = new MyClass(2, "testString");
  delete pMyClass;

  return 0;
}
