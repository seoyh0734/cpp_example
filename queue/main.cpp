#include <iostream>
#include <queue>

void clear(std::queue<std::string> &queue)
{
  std::queue<std::string> empty;
  std::swap(queue, empty);
}

int main(int argc, char* argv[])
{
  int ret = -1;

  std::queue<std::string> q;
  q.push("test");
  q.push("test");
  q.push("test");
  q.push("test");
  q.push("test");

  std::cout << q.size() << std::endl;
  clear(q);
  std::cout << q.size() << std::endl;


  return ret;
}
