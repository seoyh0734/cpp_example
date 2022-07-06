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
    std::cout << "Base(num, name)" << std::endl;
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

int main(int argc, char* argv[])
{
  Base *b = new Base(1, "Base");
  Derived *d = new Derived(1, "Derived");
  //b->print();
  //d->print();
  Derived d1(2, "Derived");
  //d1.print();
  Base *b1 = &d1;
  //b1->print();

  return 0;
}
