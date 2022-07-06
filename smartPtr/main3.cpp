#include <iostream>
#include <memory>

class Item {
  public:
  int id;

  virtual void print() {
    std::cout << "Item print" << std::endl;
  }
};

class Box : public Item {
  public:
  virtual void print() {
    std::cout << "Box print" << std::endl;
  }

  void print2() {
    std::cout << "Box print!!!!!" << std::endl;
  }
};

class SingleTon {
  private:

  static std::shared_ptr<SingleTon> instance;

  public:
  int id = 50;
  SingleTon() { std::cout << "create singleton" << std::endl; };
  ~SingleTon() { std::cout << "delete singleton" << std::endl; };

  static std::shared_ptr<SingleTon> getInstance() {
    if (!instance) {
      instance = std::make_shared<SingleTon>();
    }
    std::cout << instance << std::endl;

    return instance;
  }
};

std::shared_ptr<SingleTon> SingleTon::instance;

int main(int argc, char** argv) {
  auto instance = SingleTon::getInstance();
  std::cout << instance->id << std::endl;

  //std::shared_ptr<Item> item = std::make_shared<Box>();
  //std::shared_ptr<Box> box = std::dynamic_pointer_cast<Box>(item);

  //item->print();
  //box->print2();

  return 0;
}
