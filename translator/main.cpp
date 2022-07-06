// g++ -o main main.cpp && ./main
#include <iostream>
#include <iconv.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <unistd.h>

enum Language
{
  KOR,
  ENG,
  JPN
};

enum Meaning
{
  FIRST,
  SECOND
};

char* kor[] = { "첫번째", "두번째"};
char* eng[] = { "first", "second"};
char* jpn[] = { "最初のもの", "二番目"};

class Translator {
 private:
  Language language;
  std::string encoding;
  char** stringPtr;

 public:
  int setEncoding(std::string encoding)
  {
    this->encoding = encoding;
  }

  int setLanguage(Language language)
  {
    this->language = language;
    switch(this->language)
    {
      case KOR:
        stringPtr = kor;
        return 0;
      case JPN:
        stringPtr = jpn;
        return 0;
      case ENG:
        stringPtr = eng;
        return 0;
      default:
        stringPtr = NULL;
        return -1;
    }
  }

  void print(Meaning index)
  {
    int ret = -1;

    char conBuf[1024] = { 0x00, };

    char* inPtr = stringPtr[index];
    char* outPtr = conBuf;

    size_t inLen = strlen(stringPtr[index]);
    size_t outLen = sizeof(conBuf);

    iconv_t it = NULL;

    if (this->encoding.empty() == false &&
        this->encoding.compare("UTF-8") != 0)
    {
      it = iconv_open(this->encoding.c_str(), "UTF-8");
      if (it == NULL)
      {
        std::cout << "Failed to open iconv" << std::endl;
        goto clean;
      }
      ret = iconv(it, &inPtr, &inLen, &outPtr, &outLen);
      if (ret < 0)
      {
        std::cout << "Failed to encode text : ret = " << ret << std::endl;
        goto clean;
      }
      std::cout << conBuf << std::endl;
    }
    else
    {
      std::cout << stringPtr[index] << std::endl;
    }

   clean:
    if (it) { iconv_close(it); }

    return ;
  }
};

int main(int argc, char* argv[])
{
  int ret = -1;

  Translator translator;

  translator.setLanguage(JPN);
  translator.setEncoding("UTF-8");
  translator.print(FIRST);
  translator.print(SECOND);

  translator.setLanguage(KOR);
  translator.setEncoding("UHC");
  translator.print(FIRST);
  translator.print(SECOND);

  translator.setLanguage(ENG);
  translator.setEncoding("UTF-8");
  translator.print(FIRST);
  translator.print(SECOND);

  return ret;
}

/**
 * ==========
 * | OutPut |
 * ==========
 * 最初のもの
 * 二番目
 * 첫번쨰
 * 두번째
 * first
 * second
 */
