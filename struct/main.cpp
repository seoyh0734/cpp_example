#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

typedef struct Info {
  char id[100];
  char name[100];
  char comment[100];

  Info()
  {
    std::cout << "Info()" << std::endl;
    sprintf(id, "id");
    sprintf(name, "name");
    sprintf(comment, "comment");
  }
} Info;

int main(int argc, char* argv[])
{
  Info info;
  std::cout << info.id << std::endl;
  std::cout << info.name << std::endl;
  std::cout << info.comment << std::endl;
  return 0;
}
