#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
  std::vector<std::string> list;
  std::string key = "a";
  std::vector<std::string>::iterator it;

  list.push_back("b");

  it = std::find(list.begin(), list.end(), key);
  if (it == list.end())
  {
    std::cout << "not found : " << std::endl;
    return -1;
  }
  std::cout << "founded : " << *it << std::endl;

  return 0;
}
