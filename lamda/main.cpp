#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
  int sum = 0;

  int arr[100] = { 0x00, };
  int *fst = &arr[0];
  int *end = &arr[100];

  for(int i=0; i<100; i++)
  {
    arr[i] = i+1;
  }

  std::for_each(fst, end, [&sum](int addValue) { sum += addValue; });
  std::cout << "sum : " << sum << std::endl;

  return 0;
}
