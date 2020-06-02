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
  int i = 0;
  std::vector<cancelRequest*>* cancelList;
  cancelRequest* iterPtr;
  int idCnt = 0;

  shmId = shmget(SHM_KEY, sizeof(std::vector<cancelRequest*>), 0666 | IPC_CREAT);
  if (shmId == -1)
  {
    std::cout << "Failed to get shm" << std::endl;
    goto clean;
  }
  std::cout << "Shm ID : " << shmId << std::endl;

  shmPtr = shmat(shmId, NULL, 0);
  if (shmPtr == (void*) -1)
  {
     std::cout << "Failed shmat" << std::endl;
     goto clean;
  }
  std::cout << "shmPtr : " << shmPtr << std::endl;
  cancelList = (std::vector<cancelRequest*>*) shmPtr;

  shmId = shmget(idCnt++, sizeof(cancelRequest), 0666 | IPC_CREAT);
  shmPtr = shmat(shmId, NULL, 0);
  iterPtr = (cancelRequest*) shmPtr;

  iterPtr->scheduleId = 101;
  std::cout << "scheduleId : " << iterPtr->scheduleId << std::endl;

  std::cout << "cancelList size : " << cancelList->size() << std::endl;
  cancelList->push_back(iterPtr);
  //cancelList->push_back(iterPtr);

  //while(true)
  //{
  //  cancelRequest newRequest;
  //  newRequest.scheduleId = i++;
  //  std::cout << i << std::endl;
  //  cancelList->push_back(newRequest);
  //  sleep(5);
  //}

 clean:
  if (shmPtr) { shmdt(shmPtr); }

  return ret;
}
