#include <iostream>
#include "a.h"
#include <dlfcn.h>

using namespace std;

int main(int argc, char** argv) {
  //A a = A();
  //a.printA();
  
  const char* lib_path[] = {"/root/cppTest/LibTest/liba.so"};
  void* lib_handle = dlopen(lib_path[0], RTLD_NOW);
  if(lib_handle == NULL) {
    cout << "failed load lib" << endl;
    return -1;
  }
  
  A* (*creator)() = (A*(*)())dlsym(lib_handle, "create");

  A* p = (*creator)();

  void (*prt)(A*) = (void (*)(A*))dlsym(lib_handle, "printA_");

  prt(p);

  cout << p->num_ << endl;
  
  //p->printA();

  return 0;
}
