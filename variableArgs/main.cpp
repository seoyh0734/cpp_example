#include <iostream>
#include <cstdio>
#include <cstdarg>

std::string getString(const char *fmt, ...)
{
    int totalLen = 0;
    va_list vlist;

#ifdef _WIN32
    va_start(vlist, fmt);

    totalLen = _vscprintf(fmt, vlist) + 1;
    char* buffer = new char[totalLen + 1];
    vsprintf(buffer, fmt, vlist);

    va_end(vlist);

    std::string s(buffer);

    delete[](buffer);

    return s;
#else
    static FILE *fpNull = NULL;
    std::string retString;

    if (fpNull == NULL)
    {
        if ((fpNull = fopen("/dev/null", "w")) == NULL)
        {
            return std::string("");
        }
    }
    va_start(vlist, fmt);
    //totalLen = vsnprintf(NULL, 0, fmt, vlist);
    totalLen = vfprintf(fpNull, fmt, vlist);
    vprintf(fmt, vlist);
    va_end(vlist);

    if (totalLen > 0)
    {
        retString.resize(totalLen + 1);
        va_start(vlist, fmt);
        //char * bufferCorrectSize = new char[length];
        totalLen = vsnprintf((char *)retString.data(), totalLen + 1, fmt, vlist);
        va_end(vlist);
        retString.resize(totalLen);
    }

    return retString;
#endif
}

std::string test(const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  std::string str = getString(fmt, args);
  std::cout << "str : " << str << std::endl;

  va_end(args);

  return str;
}

int main(int argc, char* argv[])
{
  //int a = 1;
  //std::string str = getString("String %s, Integer %d\n", "str", 1);

  //std::cout << str.c_str() << std::endl;
  //std::cout << test("String %s, Integer %d\n", "str", 1) << std::endl;
  //
  printf("a = %d "
         "b = %d\n",
         1, 2);

  return 0;
}
