#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {

  //int* ap = new int(10); 
  //printf("pointer %p(%d) = %d\n", ap, ap, *ap);

  //int a = reinterpret_cast<int>(ap);
  //printf("a = %d, addr(a) = %p\n", a, &a);

  int i = 100;
  int i2 = 200;

  int* pi = &i;
  int* pi2 = &i2;

  cout << *pi << endl;
  printf("pi = %p\n", pi);
  printf("pi = %p\n", &pi);

  cout << *pi2 << endl;
  printf("pi2 = %p\n", pi2);
  printf("pi2 = %p\n", &pi2);

  memcpy(&pi, &pi2, sizeof(pi));
  cout << *pi << endl;
  printf("pi = %p\n", pi);
  printf("pi = %p\n", &pi);
  return 0;
}
