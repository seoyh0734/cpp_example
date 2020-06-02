#include <string>

typedef struct _PIPE_DATA_
{
  int id;
} PipeData;

class PipeManager
{
 public:
  std::string pipeFileName;
  int fd;

  PipeManager();
  ~PipeManager();

  int init(std::string pipeFileName);
  int create();
  int openPipe(OPEN_MODE mode);
  int readPipe(PipeData *pd);
  int writePipe(PipeData pd);

};
