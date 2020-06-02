#include <iostream>
#include <string>

using namespace std;

class women;
typedef class women women;
enum SEX {
  UNKNOWN,
  MAN,
  WOMEN
};

class human {
 public:
  string name_;
  int age_;
  SEX sex_;

  human() {
    cout << "construct" << endl;
    name_ = "아무개";
    age_ = 0;
    sex_ = UNKNOWN; 
  }

  human(string name, int age) {
    cout << "construct" << endl;
    name_ = name;
    age_ = age;
    sex_ = UNKNOWN;
  }

  ~human() {
    cout << "destruct" << endl;
  }

  virtual void printInfo() {
    cout << "name = " << name_ << endl;
    cout << "age = " << age_ << endl;
  }
};

class man : public human {
 public:
  man() : human() {
    sex_ = MAN;
  }

  man(string name, int age) : human(name, age) {
    sex_ = MAN;
  }

  void printInfo() {
    human::printInfo();
    cout << "sex = MAN" << endl;
  }
  
  void operator=(const women& w);

//  man(women& w);
};

class women : public human {
 public:
   women() : human() {
     sex_ = WOMEN;
   }

   women(string name, int age) : human(name, age) {
     sex_ = WOMEN;
   }

   void printInfo() {
     human::printInfo();
     cout << "sex = WOMAN" << endl;
   }

   operator man()
   {
     cout << "oper" << endl;
     return man(name_, age_); 
   }
};

void man::operator=(const women& w) {
  cout << "type cast" << endl;
  name_ = w.name_ + "_copy";
  age_ = w.age_;
}

//man::man(women& w) {
//  cout << "copy" << endl;
//  name_ = w.name_;
//  age_ = w.age_;
//  sex_ = MAN;
//}

int main(int argc, char** argv) {
  man m("철수", 11);
  women w("영희", 9);

  m.printInfo();
  w.printInfo();

  women w1("민지", 14);
  man m1 = w1;
  m1.printInfo();

  string str1 = "first";
  string str2 = "last";
  cout << str1 + " " + str2 << endl;

  return 0;
}
