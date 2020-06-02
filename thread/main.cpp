#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

static void signalHandler(int sig);
static void setupSignalHandling();
void cleanup(void * arg);

pthread_cond_t g_cond;
pthread_mutex_t g_mutex;
pthread_t g_thread;
pthread_t g_thread1;

void* (threadFunc)(void* arg)
{
  std::cout << "threadFunc" << std::endl;
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  pthread_cleanup_push(cleanup, (void *)NULL);

  //while(true)
  {
    std::cout << "thread Running" << std::endl;
    pthread_mutex_lock(&g_mutex);

    //std::cout << "thread wait" << std::endl;
    pthread_cond_wait(&g_cond, &g_mutex);
    //std::cout << "thread waken!" << std::endl;

    pthread_mutex_unlock(&g_mutex);

    sleep(1);
  }
  std::cout << "thread stop" << std::endl;
  pthread_cleanup_pop(0);

  return NULL;
}

int main(int argc, char* argv[])
{
  int ret = -1;
  std::cout << (char)0x01 << std::endl;
  setupSignalHandling();

  pthread_cond_init(&g_cond, NULL);
  pthread_mutex_init(&g_mutex, NULL);

  pthread_create(&g_thread, NULL, threadFunc, NULL);
  pthread_create(&g_thread1, NULL, threadFunc, NULL);

  //while(true)
  //{
  //  pthread_mutex_lock(&g_mutex);
  //  std::cout << "lets wake up!" << std::endl;
  //  pthread_cond_signal(&g_cond);
  //  pthread_mutex_unlock(&g_mutex);
  //  sleep(1);
  //}

  sleep(100);
  std::cout << "join" << std::endl;
  pthread_join(g_thread, NULL);
  std::cout << "joined! 1" << std::endl;
  pthread_join(g_thread1, NULL);
  std::cout << "joined! 2" << std::endl;

  return ret;
}

void cleanup(void *arg)
{
  std::cout << "cleanup()" << std::endl;
  //pthread_mutex_unlock(&g_mutex);
  //pthread_cond_broadcast(&g_cond);
}

void cancel(int sig)
{
  if(sig == SIGUSR1)
  {
    std::cout << "cancel" << std::endl;
    pthread_cancel(g_thread);
    //pthread_cancel(g_thread1);
  }
  else if (sig == SIGALRM)
  {
    std::cout << "signal" << std::endl;
    pthread_cond_signal(&g_cond);
  }
}

static void signalHandler(int sig)
{
  cancel(sig);
}
static void setupSignalHandling()
{
  struct sigaction sa;
  sa.sa_handler = signalHandler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGALRM, &sa, NULL);
}
