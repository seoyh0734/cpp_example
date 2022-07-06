#include <iostream>
#include <map>

int main(int argc, char* argv[])
{
  std::map<int, std::string> m;
  m.insert(std::make_pair(1, "test"));

  std::cout << m[1].c_str() << std::endl;
  std::cout << m.size() << std::endl;

  return 0;
}
