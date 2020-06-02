#include <iostream>
#include <ctime>
#include <unistd.h>
const unsigned int repeatCnt = 10000000;
unsigned int sum = 0;

int funcA()
{
  //std::cout << "funcA" << std::endl;
  sum++;
  return 0;
}

int funcB()
{
  //std::cout << "funcB" << std::endl;
  sum+=2;
  return 0;
}

int (*pFunc)(void) = funcB;

int testIf(int flag)
{
  clock_t start;
  clock_t end;
  sum = 0;

  start = clock();
  for (unsigned int i=0; i<repeatCnt; i++){
   if (flag == 0)
   {
     funcA();
   }
   else
   {
     funcB();
   }
  }

  end = clock();

  double runningTime = (double) (end - start);

  std::cout << "sum : " << sum << std::endl;
  std::cout << "if start : " << start << std::endl;
  std::cout << "if end : " << end << std::endl;
  std::cout << "if run : " << runningTime/CLOCKS_PER_SEC << std::endl;

  return 0;
}

int testCF(int flag)
{
  clock_t start;
  clock_t end;
  sum = 0;

  start = clock();
  for (unsigned int i=0; i<repeatCnt; i++){
    pFunc();
  }
  end = clock();
  double runningTime = (double) (end - start);

  std::cout << "sum : " << sum << std::endl;
  std::cout << "cb start : " << start << std::endl;
  std::cout << "cb end : " << end << std::endl;
  std::cout << "cb run : " << runningTime/CLOCKS_PER_SEC << std::endl;

  return 0;
}


int main(int argc, char* argv[])
{
  int flag = 0;

  std::cin >> flag;

  testIf(flag);
  testCF(flag);
  return 0;
}
