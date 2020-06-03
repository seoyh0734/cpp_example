// g++ -o main main.cpp && ./main
#include <iostream>

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

char* kor[] = { "첫번쨰", "두번째"};
char* eng[] = { "first", "second"};
char* jpn[] = { "最初のもの", "二番目"};

class Translator {
 private:
  Language language;
  char** stringPtr;

 public:
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
    std::cout << stringPtr[index] << std::endl;
  }
};

int main(int argc, char* argv[])
{
  int ret = -1;

  Translator translator;

  translator.setLanguage(JPN);
  translator.print(FIRST);
  translator.print(SECOND);

  translator.setLanguage(KOR);
  translator.print(FIRST);
  translator.print(SECOND);

  translator.setLanguage(ENG);
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
