#include <iostream>

int main(int argc, char** argv) {
  int** arr = new int*[2];
  arr[0] = new int[2];
  arr[1] = new int[2];

  int cnt = 1;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      arr[i][j] = cnt++;
      printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
    }
  }

  delete[] arr[0];
  delete[] arr[1];
  delete[] arr;


  printf("arr[0][0] = %d\n", arr[0][0]);
  printf("arr[0][1] = %d\n", arr[0][1]);
  printf("arr[1][0] = %d\n", arr[1][0]);
  printf("arr[1][1] = %d\n", arr[1][1]);

  return 0;
}
