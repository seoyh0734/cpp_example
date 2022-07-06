#include <iostream>
#include <vector>
#include <typeinfo>

template <typename T>
class Test
{
 public:
  std::vector<T> list;
  void print(T t)
  {
    std::cout << typeid(t).name() << std::endl;
    if (typeid(t) == typeid(std::string))
    {
      //std::cout << t.c_str() << std::endl;
      std::cout << t << std::endl;
    }
    else
    {
      std::cout << t << std::endl;
    }
    return ;
  }

  int add(T t)
  {
    list.push_back(t);
    return 0;
  }

  std::vector<T> getList()
  {
    return list;
  }
};

int main(int argc, char** argv)
{
  Test<int> test;
  test.add(1);
  test.add(2);
  test.add(3);
  test.print(1);
  std::vector<int> list = test.getList();
  for (int i=0; i<list.size(); i++)
  {
    std::cout << list[i] << std::endl;
  }
  Test<std::string> test2;
  test2.print("hello");
  return 0;
}
