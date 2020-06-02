#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
  int arr[10];

  // common for statement
  //for(int i=0; i<10; i++) {
  //  arr[i] = int(i);
  //  cout << arr[i] << endl;
  //}
  
  // ranged for statement
  int cnt = 1;
  for(int& val : arr) { // check &val vs val
    val = cnt++;
  }
  
  for(int val : arr) {
    cout << val << endl;
  }
  return 0;
}
