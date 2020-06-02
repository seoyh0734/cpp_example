#include <stdio.h>

void print(int i) {
  printf("integer %d\n", i);
}

void print(int* ptr) {
  printf("pointer %p\n", ptr);
}

int main(int argc, char** argv) {
  float* ptr1;
  float* ptr2 = 0;

  printf("%p\n", ptr1);
  printf("%p\n", ptr2);

  if (ptr1)
    printf("True\n");
  else
    printf("False\n");
     
  if (ptr2)
    printf("True\n");
  else
    printf("False\n");

  print(0);
  print(NULL);
  print(nullptr);

  return 0;
}
