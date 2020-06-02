#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "start" << endl;
  
  int arrLen = 14;

  int arr[14] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

  for (int i=0; i<arrLen; i++) {
    cout << "arr[" << i << "] =" << arr[i] << endl;
    cout << "!arr[" << i << "] =" << !arr[i] << endl;
  }

  return 0;
}
