#include <iostream>
#include <dlfcn.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  const char* lib_path[] = {"./liba.so"};
  void* lib_handle = dlopen(lib_path[0], RTLD_NOW);
  if(lib_handle == NULL) {
    cout << "failed load lib" << endl;
    return -1;
  }

  string funcName;
  if (argv[1] != NULL)
  {
    funcName = string(argv[1]);
  }
  else
  {
    funcName = string("aPrintP");
  }
  void (*prt)() = (void(*)())dlsym(lib_handle, funcName.c_str());
  prt();

  return 0;
}
