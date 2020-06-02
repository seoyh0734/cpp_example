#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<int> v;
  v.push_back(7);

  std::vector<int>::iterator iter = v.begin();

  std::cout << v.empty() << std::endl;
  std::cout << iter[0] << std::endl;
  v.erase(iter);
  std::cout << v.empty() << std::endl;
  //std::cout << iter[0] << std::endl;
  //std::cout << iter[0] << std::endl;

  return 0;
}
