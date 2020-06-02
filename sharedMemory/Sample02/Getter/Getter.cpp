#include <iostream>

#include <sys/ipc.h>
#include <sys/shm.h>

#include <vector>

#include <unistd.h>

#include "../typeDefine.h"

int main(int argc, char* argv[])
{
  int ret = -1;

  int shmId = 0;
  void *shmPtr = (void*) 0;

  std::vector<cancelRequest>* cancelList;

  shmId = shmget(SHM_KEY, sizeof(std::vector<cancelRequest>), 0666 | IPC_CREAT);
  if (shmId == -1)
  {
    std::cout << "Failed to get shm" << std::endl;
    goto clean;
  }

  shmPtr = shmat(shmId, NULL, 0);
  if (shmPtr == (void*) -1)
  {
     std::cout << "Failed shmat" << std::endl;
     goto clean;
  }
  std::cout << "shmPtr : " << shmPtr << std::endl;
  cancelList = (std::vector<cancelRequest>*) shmPtr;

  while(true)
  {
    for (int i=0; i<cancelList->size(); i++)
    {
      std::cout << (*cancelList)[i].scheduleId << std::endl;
    }
    sleep(2);
    std::cout << "-----------" << std::endl;
  }

 clean:
  if (shmPtr) { shmdt(shmPtr); }

  return ret;
}
