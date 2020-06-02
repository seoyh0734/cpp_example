#include <iostream>
#include "ThreadPool.h"

#include <stdlib.h>
#include <unistd.h>

const int ThreadPool::defaultThreadNum = 5;

ThreadPool::ThreadPool()
{
  std::cout << "ThreadPool()" << std::endl;
  this->initThreadSize = 0;
}

ThreadPool::~ThreadPool()
{
  std::cout << "~ThreadPool()" << std::endl;
}

int ThreadPool::init(int initThreadSize)
{
  std::cout << "initThreadSize : " << initThreadSize << std::endl;
  int ret = -1;

  this->initThreadSize = initThreadSize;
  pthread_mutex_init(&this->internalMutex, NULL);
  pthread_mutex_init(&this->condMutex, NULL);
  this->cond = PTHREAD_COND_INITIALIZER;

  for (int i=0; i<this->initThreadSize; i++)
  {
    pthread_t tmpThd;
    pthread_create(&tmpThd, NULL, &(ThreadPool::threadLoop), (void*)this);
    this->threadArr.push_back(tmpThd);
  }

  return ret;
}

int ThreadPool::waitAll()
{
  int ret = -1;
  //pthread_join(this->threadArr[5], NULL);
  for (int i=0; i<threadArr.size(); i++)
  {
    pthread_join(threadArr[i], NULL);
  }
  return -1;
}

int ThreadPool::putJob(void* (*job)(void*))
{
  jobArr.push_back(job);
  return 0;
}

int ThreadPool::getJob(void* (**job)(void*))
{
  int ret = -1;
  static int cnt = 0;
  if (!this->jobArr.empty())
  {
    std::cout << "Not Empty" << std::endl;
    *job = this->jobArr[0];
    this->jobArr.erase(this->jobArr.begin());
    ret = 0;
    std::cout << "cnt : " << ++cnt << std::endl;
    goto exit;
  }
  else
  {
    std::cout << "Empty" << std::endl;
    ret = -1;
    goto exit;
  }

 exit:
  return ret;
}

void* ThreadPool::threadLoop(void* arg)
{
  int ret = -1;
  ThreadPool* pool = (ThreadPool*)arg;
  void* (**job)(void*) = (void* (**)(void*))malloc(4);
  *job = NULL;
  while(1)
  {
    pthread_mutex_lock(&pool->internalMutex);
      pthread_cond_wait(&pool->cond, &pool->internalMutex);
    ret = pool->getJob(job);
    pthread_mutex_unlock(&pool->internalMutex);
    if (ret == 0)
    {
      std::cout << "find job" << std::endl;
      (*job)(NULL);
      sleep(5);
    }
    else
    {
      pthread_mutex_lock(&pool->condMutex);
      pthread_cond_wait(&pool->cond, &pool->internalMutex);
      pthread_mutex_unlock(&pool->condMutex);
      std::cout << "no job" << std::endl;
    }
    sleep(1);
  }
  return 0;
}
