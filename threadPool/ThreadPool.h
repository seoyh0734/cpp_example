#include <pthread.h>
#include <vector>

class ThreadPool
{
 public:
  ThreadPool();
  ~ThreadPool();

  int init(int initThreadSize = ThreadPool::defaultThreadNum);

  int putJob(void* (*job)(void*));
  int getJob(void* (**job)(void*));

  int waitAll();

  int initThreadSize;
  pthread_cond_t cond;

 private:
  pthread_mutex_t internalMutex;
  pthread_mutex_t condMutex;
  static const int defaultThreadNum;
  static void* threadLoop(void* arg);
  std::vector<pthread_t> threadArr;
  std::vector<void *(*)(void*arg)> jobArr;
};
