#include <iostream>

#include <cstdlib>
#include <cstring>

#include <memory>
#include <vector>

#define NAME_MAX_SIZE 100

class Item {
  public:
  char* name = NULL;

  Item() {
    std::cout << "created item" << std::endl;
    this->name = new char[NAME_MAX_SIZE];
    memset(this->name, 0, NAME_MAX_SIZE);
  }

  Item(const char* const name ) {
    std::cout << "created item" << std::endl;
    this->name = new char[NAME_MAX_SIZE];
    strcpy(this->name, name);
  }

  ~Item() {
    std::cout << "deleted item" << std::endl;
    delete[] this->name;
    this->name = NULL;
  }

  void setName(const char* const name) {
    strcpy(this->name, name);
  }

  void print() {
    std::cout << "Item : " << name << std::endl;
  };
};

class ItemList {
  public:
  std::vector<std::shared_ptr<Item>> itemList;
  const unsigned int maxSize = 5;

  void add(std::shared_ptr<Item> item) {
    if (itemList.size() >= maxSize) {
      throw new std::runtime_error("Hello!");
    }

    itemList.push_back(item);
  }

  std::shared_ptr<Item> get(int index) {
    if (index >= itemList.size()) {
      throw std::runtime_error("Invalid index");
    }
    return itemList[index];
  }
};

int main(int argc, char** argv) {
  ItemList itemList;

  try {
    itemList.add(std::make_shared<Item>("1"));
    std::cout << "Try 1" << std::endl;
    itemList.add(std::make_shared<Item>("2"));
    std::cout << "Try 2" << std::endl;
    itemList.add(std::make_shared<Item>("3"));
    std::cout << "Try 3" << std::endl;
    itemList.add(std::make_shared<Item>("4"));
    std::cout << "Try 4" << std::endl;
    itemList.add(std::make_shared<Item>("5"));
    std::cout << "Try 5" << std::endl;
    itemList.add(std::make_shared<Item>("6"));
    std::cout << "Try 6" << std::endl;
    itemList.add(std::make_shared<Item>("7"));
    std::cout << "Try 7" << std::endl;
    std::cout << "End Try!" << std::endl;
  } catch (int e) {
    std::cout << e << std::endl;
  } catch (std::runtime_error re) {
    std::cout << re.what() << std::endl;
  } catch (std::runtime_error* rePtr) {
    std::cout << rePtr->what() << std::endl;
    delete rePtr;
  }

  auto item = itemList.get(0);
  item->print();

  return 0;
}
