#include <iostream>

#include <iostream>
#include <fstream>

#ifdef _WIN32
#else
  #include <sys/types.h>
  #include <dirent.h>
  #include <sys/stat.h>
  #include <unistd.h>
#endif


#include <string>
#include <cstring>
#include <vector>

#define ERROR_SUCCESS 0

int getCurrentDir(std::string& output)
{
  int ret = -1;
  char buf[1024] = { 0x00, };

  if (getcwd(buf, sizeof(buf)) == NULL)
  {
    return 1234;  // Temp error code
  }

  output = buf;
  return ERROR_SUCCESS;
}

int getFileList(std::vector<std::string>& output, const std::string dirPath)
{
  int ret = -1;
  DIR *dirp = NULL;
  struct dirent *dentry = NULL;
  //bool dirChanged = false;  // chdir()에 의한 현재 디렉토리 변경 여부

  output.clear();

  /* 현재 디렉토리 조회 */
  //std::string currentDir;
  //ret = getCurrentDir(currentDir);
  //if (ret != ERROR_SUCCESS)
  //{
  //  return ret;
  //}

  /* 현재 디렉토리 변경 */
  //if (chdir(dirPath.c_str()) < 0)
  //{
  //  goto clean;
  //}
  //dirChanged = true;

  /* 현재 디렉토리 열기 */
  //if ((dirp = opendir(".")) == NULL)
  if ((dirp = opendir(dirPath.c_str())) == NULL)
  {
    goto clean;
  }

  /* 현재 디렉토리 읽기 */
  while(dentry = readdir(dirp))
  {
    /* 삭제된 dentry 제외 */
    if (dentry->d_ino == 0)
    {
      continue;
    }

    /* 현재 디렉토리, 상위 디렉토리 제외 */
    if (strcmp(dentry->d_name, ".") == 0 ||
        strcmp(dentry->d_name, "..") == 0)
    {
      continue;
    }

    /* 파일명 추가 */
    output.push_back(dentry->d_name);
  }

 clean:
  if (dirp) closedir(dirp);
  //if (dirChanged) chdir(currentDir.c_str());  // 현재 디렉토리 되돌리기

  return ERROR_SUCCESS;
}


int main(int argc, char** argv)
{
  std::cout << "main()" << std::endl;
  int ret = -1;
  std::vector<std::string> fileList;

  ret = getFileList(fileList, "/root/cppTest/fileUtil");
  if (ret != 0)
  {
    std::cerr << "Failed to getFileList" << std::endl;
  }

  for (int i=0; i<fileList.size(); i++)
  {
    std::cout << fileList[i].c_str() << std::endl;
  }

  return 0;
}
