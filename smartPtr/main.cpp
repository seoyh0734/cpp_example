#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include <cstring>

class User {
 public:
  std::string name;

  char* test_name;

  User(std::string name) : name(name) {
    std::cout << "create " << this->name << std::endl;

    test_name = new char[100];
    strcpy(test_name, "inited");
  };

  ~User() {
    std::cout << "delete " << this->name << std::endl;

    strcpy(test_name, "deinited");
    delete[] test_name;
  }

  void print() {
    std::cout << this->name << std::endl;
  }

};

class UserList {
 public:
  std::vector<User> m_list;

  UserList() {
  }

  void add(User& user) {
    m_list.push_back(user);
  }

  User get(const unsigned short i) {
    return m_list[i];
  }

  User* getPtr(const unsigned short i) {
    return &m_list[i];
  }
};

static void argTest(User& user) {
  std::cout << "user : " << user.name << std::endl;
}

int main(int argc, char** argv) {
  User user("hong");
  user.print();

  UserList userList;
  userList.add(user);
  user.name = "kim";
  user.print();
  userList.get(0).print();

  User* userPtr = userList.getPtr(0);
  userPtr->name = "lee";
  userList.get(0).print();
  
  argTest(user);

  std::cout << "Main end" << std::endl;

  return 0;
}
