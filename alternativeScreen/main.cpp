#include <iostream>

int main(int argc, char** argv) {
  std::cout << "main" << std::endl;

  std::cout << "\033[?47h" << std::endl;

  //std::cout << "\033[?47l" << std::endl;

  return 0;
}
