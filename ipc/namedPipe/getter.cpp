#include <iostream>
#include "NamedPipe.h"

#include <unistd.h>

std::string pipeFileName = "./test_pipe";

int main(int argc, char* argv[])
{
  int ret = -1;

  NamedPipe np;
  if (np.init(pipeFileName) != 0)
  {
    ret = 1;  // Failed init
    return ret;
  }

  np.create();
  np.openPipe(READ_WRITE);

  PipeData pd;

  while (true)
  {
    if (np.readPipe(&pd) != 0)
    {
      ret = 3;
      break;
    }
    std::cout << "read data id : " << pd.id << std::endl;
    if (pd.id == 98)
    {
      break;
    }

    sleep(2);
  }

  return ret;
}
