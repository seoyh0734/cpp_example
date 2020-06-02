#include <iostream>
#include <exception>

#include "NamedPipe.h"

#include <fcntl.h>     //
#include <unistd.h>    // access, unlink
#include <sys/stat.h>  // mkfifo
#include <cstdlib>
//#include <stdio.h>
#include <sys/socket.h>

NamedPipe::NamedPipe()
{
  this->fd = -1;
}

NamedPipe::~NamedPipe()
{
}

int NamedPipe::init(std::string pipeFileName)
{
  int ret = -1;

  this->pipeFileName = pipeFileName;

  ret = 0;
 clean:
  return ret;
}

int NamedPipe::create()
{
  int ret = -1;

  if (access(this->pipeFileName.c_str(), F_OK) == 0)
  {
    unlink(this->pipeFileName.c_str());
  }

  if (mkfifo(this->pipeFileName.c_str(), 0666) < 0)
  {
    std::cout << "Failed to mkfifo" << std::endl;
    return 2;
  }

  return ret;
}

int NamedPipe::openPipe(OPEN_MODE mode)
{
  std::cout << "openPipe" << std::endl;
  int ret = -1;

  int openMode = -1;

  switch(mode)
  {
    case READ_ONLY:
      openMode = 0; break;
    case WRITE_ONLY:
      openMode = O_WRONLY; break;
    case READ_WRITE:
      openMode = O_RDWR; break;
    default:
      return -1;
  }

  this->fd = open(pipeFileName.c_str(), mode);
  if (this->fd < 0)
  {
    std::cout << "Failed to open pipe file. : " << this->fd << std::endl;
    ret = 1;
    goto clean;
  }

 clean:
  return ret;
}

int NamedPipe::readPipe(PipeData *pd)
{
  int ret = -1;
  int nread = 0;

  //if ((nread = read(this->fd, pd, sizeof(PipeData))) < 0)
  if ((nread = recvmsg(this->fd,(void*) pd, sizeof(PipeData), 0)) < 0)
  {
    std::cout << "Failed to read from pipe" << std::endl;
    ret = 0;
    goto exit;
  }
  std::cout << "nread : " << nread << std::endl;

  ret = 0;

 exit:
  return ret;
}

int NamedPipe::writePipe(PipeData pd)
{
  int ret = -1;
  int nread = 0;

  std::cout << "write start" << std::endl;
  try {
    //nread = write(this->fd, &pd, sizeof(PipeData));
    nread = sendmsg(this->fd, (void*) &pd, sizeof(PipeData), 0);
    std::cout << "nread : " << nread << std::endl;
  }
  catch (int &e)
  {
    std::cout << "exception!" << std::endl;
  }
  std::cout << "write end" << std::endl;
  if (nread < 0)
  {
    std::cout << "Failed to write to pipe" << std::endl;
    ret = 0;
    goto exit;
  }
  std::cout << "Success write to pipe" << std::endl;
  ret = 0;

 exit:
  return ret;
}
