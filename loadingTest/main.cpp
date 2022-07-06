#include <iostream>
#include <dlfcn.h>

#include "stLib/stLib.h"
#include "stLib/stLib2.h"

int main(int argc, char* argv[])
{
  int ret = -1;
  firstFunc();

  void* libHandler = NULL;
  void (*callFunc)() = NULL;

  libHandler = dlopen("./dyLib/libdyLib.so", RTLD_NOW);
  if (libHandler == NULL)
  {
    std::cout << "Can not find dynamic library : " << dlerror() << std::endl;
    ret = -1;
    goto clean;
  }

  callFunc = (void (*)()) dlsym(libHandler, "callFirstFuncOnDyLib");
  if (callFunc == NULL)
  {
    std::cout << "Failed to loading function()" << std::endl;
    ret = -1;
    goto clean;
  }

  callFunc();

 clean:

  return ret;
}
