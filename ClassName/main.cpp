#include <iostream>
#include <typeinfo>

using namespace std;

class MyClass {
  private:
    int num;

  public:
    MyClass(int num) {this->num = num;}

    void setNum(int num) {
      this->num=num; 
    }

    int getNum() {return num;}

    MyClass operator+(MyClass &rhs) {
      int num = this->getNum() + rhs.getNum();
      MyClass tmpClass = MyClass(num);
      tmpClass.setNum(num);
      return tmpClass;
    }
};

int main(int argc, char** argv) {
  MyClass myClass = MyClass(3);
  MyClass myClass2 = MyClass(2);

  MyClass myClass3 = myClass + myClass2;

  cout << myClass3.getNum() << endl;
  cout << myClass2.getNum() << endl;

  return 0;
}

