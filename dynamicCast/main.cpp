#include <iostream>

using namespace std;

class parentC {
 public:
  int num_;

  parentC() {
    this->num_ = 10;
  }

  virtual void print() {
    cout << "num  = " << this->num_ << endl;
  }
};

class childC : public parentC {
 public:
  int num2_;

  //childC() : parentC() {
  childC() {
    num_ = 12;
    num2_ = 11;
  }

  void print() {
    cout << "num  = " << this->num_ << "\nnum2 = " << this->num2_ << endl;
  }
};

int main(int argc, char** argv) {
  cout << "down and up" << endl;
  // 업 캐스팅 후, 다운 캐스팅은 가능
  childC *c = new childC(); 
  parentC *p = NULL;
  parentC *p1 = NULL;

  cout << "up : dynamic" << endl;
  p = dynamic_cast<parentC*> (c);
  p->print();

  cout << "up : static" << endl;
  p1 = static_cast<parentC*> (c);
  p1->print();

  cout << "down : dynamic" << endl;
  c = dynamic_cast<childC*> (p); 
  c->print();


  cout << "\nup and down" << endl;
  // 다운 캐스팅 후 업 캐스팅은 불가능
  childC *c2 = NULL; 
  parentC *p2 = new parentC();
  parentC *p3 = NULL; 

  p2->num_ = 100;

  c2 = static_cast<childC*> (p2);
  c2->print();

  p2 = dynamic_cast<parentC*> (c2);
  p2->print();

  p3 = static_cast<parentC*>(c2);
  p3->print();

  delete c, p, c2, p2;

  return 0;
}
