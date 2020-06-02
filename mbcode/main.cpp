#include <iostream>
#include <cstdio>
#include <cwchar>
#include <clocale>
#include <string>

int main(int argc, char* argv[])
{
  int ret = -1;
  std::setlocale(LC_ALL, "utf8");
  //char16_t *c = u"한글입니다";
  //wchar_t *c = L"한글입니다";
  std::string c = L"한글입니다";
  //wprintf(c);
  std::wcout << L"안녕하세요" << std::endl;
  return ret;
}
