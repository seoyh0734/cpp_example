#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int size_x = 2;
  int size_y = 2;
  char** c = new char*[size_x];
  for(int i = 0; i < size_x; i++) c[i] = new char[size_y];
  void* v = c;

  for(int i = 0; i < size_x; i++) {
    for(int j = 0; j < size_y; j++) {
      c[i][j] = 80 + j + i;
      cout << ((char**)v)[i][j] << endl;
    }
  }
  return 0;
}
