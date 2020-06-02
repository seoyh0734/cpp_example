#include <iostream>
#include <unistd.h>
#include "ThreadPool.h"

void* job1(void* arg)
{
  std::cout << "job1" << std::endl;
}

void* job2(void* arg)
{
  std::cout << "job2" << std::endl;
}

int main(int argc, char* argv[])
{
  int ret = -1;

  ThreadPool tp;
  tp.init();

  for (int i=1; i<=13; i++)
  {
    tp.putJob(&job1);
    pthread_cond_signal(&tp.cond);
    std::cout << "job puted : " << i << std::endl;
    usleep(500 * 1000);
  }

  tp.waitAll();
  return ret;
}
