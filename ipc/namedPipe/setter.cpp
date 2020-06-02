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

  np.openPipe(WRITE_ONLY);
  std::cout << "Opened" << std::endl;

  PipeData pd;

  while (true)
  {
    std::cout << "Start" << std::endl;
    static int cnt = 0;
    pd.id = cnt++;
    if (cnt == 100) break;
    ret = np.writePipe(pd);
    if (ret != 0)
    {
      ret = 5;
      std::cout << "writePipe error : " << ret << std::endl;
      break;
    }
    std::cout << "write data id : " << pd.id << std::endl;

    std::cout << "End" << std::endl;
    sleep(1);
  }
  return ret;
}
