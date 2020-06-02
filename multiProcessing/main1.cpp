#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

int main(int argc, char* argv[])
{
  int ret = -1;

  int shmid;
  int* data = 0;

  void* shmPtr = NULL;

  const key_t key = 3369;
  int dataSize = sizeof(int);
  int shmFlag = IPC_CREAT;
  int shmId;

  shmId = shmget(3369, dataSize, 0666 | shmFlag);
  if (shmId == -1)
  {
    goto clean;
  }
  std::cout << "shmId : " << shmId << std::endl;

  shmPtr = shmat(shmId, NULL, 0);
  data = (int*)shmPtr;
  std::cout << "data : " << *data << std::endl;

  if (argc > 1)
  {
    *data = 0;
    goto clean;
  }

  *data += 7;

 clean:
  return ret;
}
