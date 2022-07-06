#ifndef _SHARED_MEM_H_
#define _SHARED_MEM_H_

#include <sys/ipc.h>
#include <sys/shm.h>

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

class SharedMem
{
  public:
   int create(int& id, int key, unsigned int size, int optionFlag)
   {
     id = shmget((key_t) key, size, optionFlag);
     if (id < 0)
     {
       return -1;
     }
     return 0;
   }

   int get(void*& addr, int id)
   {
     addr = shmat(id, 0, 0);
     if (addr == NULL)
     {
       return -2;
     }
     return 0;
   }

   int remove(int id)
   {
     int ret = -1;
     ret = shmctl(id, IPC_RMID, 0);
     return ret;
   }
};

class SharedData
{
  public:
  char data[8];

  int setData(std::string data)
  {
    strcpy(this->data, data.c_str());
    return 0;
  }
};

int main(int argc, char** argv)
{
  std::cout << "main" << std::endl;
  int ret = -1;
  SharedMem sm;
  int id = -1;
  int key = 9999;
  ret = sm.create(id, key, sizeof(SharedData) * 2, 0666 | IPC_CREAT);
  if (ret != 0)
  {
    std::cerr << "Failed sm.create" << std::endl;
    ret = sm.remove(id);
    if (ret != 0)
    {
      std::cerr << "Failed sm.remove" << std::endl;
    }

    return ret;
  }
  std::cout << "id : " << id << std::endl;

  void* addr = NULL;
  ret = sm.get(addr, id);
  if(ret != 0)
  {
    std::cerr << "Failed sm.get" << std::endl;
    return ret;
  }
  std::cout << "addr : " << addr << std::endl;

  //SharedData* data = (SharedData*)addr;
  //std::cout << "data : " << data->data << std::endl;
  //data->setData("test");
  //SharedData* data2 = (SharedData*)addr + sizeof(SharedData);
  //std::cout << "data2 : " << data2->data << std::endl;
  //data2->setData("test2");
  SharedData** dataList = (SharedData**)malloc(sizeof(SharedData*)*2);
  dataList[0] = (SharedData*)addr;
  dataList[1] = (SharedData*)addr + sizeof(SharedData*);
  std::cout << "dataList[0] : " << dataList[0]->data << std::endl;
  std::cout << "dataList[1] : " << dataList[1]->data << std::endl;
  std::cout << "sizeof(SharedData*) : " << sizeof(SharedData*) << std::endl;
  std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
  std::cout << "sizeof(long) : " << sizeof(long) << std::endl;
  std::cout << "sizeof(long long) : " << sizeof(long long) << std::endl;

  free(dataList);

  return 0;
}

#endif  // _SHARED_MEM_H_
