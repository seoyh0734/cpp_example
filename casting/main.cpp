#include <iostream>

class Base {
 protected:
  int num;
  std::string name;

 public:
  Base()
  {
    std::cout << "Base()" << std::endl;
    this->num = 0;
    this->name = "Base";
  }

  Base(int num, std::string name)
  {
    this->num = num;
    this->name = name;
  }

  virtual void print()
  {
    std::cout << num << std::endl;
    std::cout << name.c_str() << std::endl;
  }
};

class Derived : public Base {
 public:
  int special;
  Derived(int num, std::string name) : Base(num, name)
  {
    this->num = num;
    this->name = name;
    this->special = 100;
  }

  void print()
  {
    std::cout << num << std::endl;
    std::cout << name.c_str() << std::endl;
    std::cout << special << std::endl;
  }

  void print2()
  {
    std::cout << num << std::endl;
    std::cout << name.c_str() << std::endl;
    std::cout << special << std::endl;
  }
};

class Derived2 : public Base {
 public:
  int special2;
  Derived2(int num, std::string name) : Base(num, name)
  {
    this->num = num;
    this->name = name;
    this->special2 = 150;
  }

  void print()
  {
    std::cout << num << std::endl;
    std::cout << name.c_str() << std::endl;
    std::cout << special2 << std::endl;
  }

  void print2()
  {
    std::cout << num << std::endl;
    std::cout << name.c_str() << std::endl;
    std::cout << "2" << special2 << std::endl;
  }
};

int main(int argc, char* argv[])
{
  Base *b = new Base(0, "Base");
  Derived *d = new Derived(1, "Derived");

  // AutoTypeChange : Derived* -> Base*
  Base *tmp = d;

  Base b2(0, "Base");
  Derived d2(1, "Derived");
  Derived* tmp2 = static_cast<Derived*>(&b2);
  //tmp2->print2(); // static_case weakness, it is possible between base and derived

  Base *b3 = &d2;
  //Base *b3 = &b2;
  Derived2 *tmp3 = dynamic_cast<Derived2*>(b3);
  //Derived2 *tmp3 = static_cast<Derived2*>(b3);
  //Derived *tmp3 = dynamic_cast<Derived*>(b3);
  //Derived *tmp3 = dynamic_cast<Derived*>(&b2);
  //if (tmp3)
  //tmp3->print2();

  //int intArr[5] = { 63, 64, 65, 66, 0x00};
  //int *intPtr = intArr;
  ////char* charPtr = static_cast<char*>(intPtr);  // Fail
  ////double *doublePtr = static_cast<double*>(intPtr);  // Fail
  ////short *shortPtr = static_cast<short*>(intPtr);  // Fail
  //long *longPtr = static_cast<long*>(intPtr);  // Fail

  Derived d1(3, "Derived");
  Base b1 = static_cast<Base>(d1);
  b1.print();
  d1.print();

  return 0;
}
