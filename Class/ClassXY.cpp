#include <iostream>

using namespace std;

class ClassX {
protected :
  int a;
  int b;
public :
  ClassX(int a, int b) {
    this->a = a;
    this->b = b;
  };

  virtual void printInfo()=0;

};

class ClassY : public ClassX {
private :
  int c;
public :
  ClassY(int a, int b, int c) : ClassX(a,b) {
    this->c = c;
  };

  void printInfo() {
    cout << this->a << endl << this->b << endl << this->c << endl << "ClassY" << endl;
  };  

};

class ClassZ : public ClassX {
  private :
    int c;
  public :
    ClassZ(int a, int b, int c) : ClassX(a,b) {
      this->c = c;
    };

    void printInfo() {
      cout << this->a << endl << this->b << endl << this->c << endl << "ClassZ" << endl;
    };

    void printInfo2() {
       cout << this->a << endl << this->b << endl << this->c << endl << "ClassZ222" << endl;
    };

};

void test1(ClassX* cx) {
  ClassX* cx2 = cx;
  cx2->printInfo();
};

int main( int argc, char** argv) {
  ClassZ cy(1,2,3);

  //cy.printInfo2();
  test1(&cy);

   return 0;
}
