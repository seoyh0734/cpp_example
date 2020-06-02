#include <iostream>
#include <stdio.h>
// Shared Memory
#include <sys/ipc.h>
#include <sys/shm.h>

#include <string>

class memoryType
{
 public:
  int id;
  char content[40];
};

int main(int argc, char** argv)
{
  memoryType* memArr = NULL;
  int memCnt = 10;
  std::cout << "shared memory test" << std::endl;

  int shmid;
  void* shared_memory = (void*) 0;

  shmid = shmget((key_t)3836, sizeof(memoryType)*memCnt, 0666|IPC_CREAT);
  std::cout << shmid << std::endl;

  shared_memory = shmat(shmid, (void*) 0, 0);
  std::cout << shared_memory << std::endl;

  memArr = (memoryType*) shared_memory;
  for (int i=0; i<memCnt; i++)
  {
    memArr[i].id = i;
    snprintf(memArr[i].content, sizeof(memArr[i].content), "abcd%d", i);
    std::cout << memArr[i].id << std::endl;
    std::cout << memArr[i].content << std::endl;
  }

  //shmctl(shmid, IPC_RMID, 0);
  
  return 0;
}
