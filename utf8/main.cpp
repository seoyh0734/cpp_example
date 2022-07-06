#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <wchar.h>

#pragma GCC diagnostic ignored "-Wwrite-strings"

int toHex(std::string &hexStr, unsigned int bin)
{
  const unsigned short hexSize = 16;
  char* hexes = "0123456789ABCDEF";

  std::string hexCode = "";

  while (bin > 0)
  {
    unsigned short mod = bin % hexSize;
    hexCode = std::string() + hexes[mod] + hexCode;
    bin /= 16;
  }

  hexStr = hexCode;

  return 0;
}

int main(int argc, char* argv[])
{
  //std::wcout.imbue(std::locale("Korean"));
  //std::wstring str = L"헬로우월드";
  //std::cout << str.size() << std::endl;
  //std::wcout << str.c_str() << std::endl;
  //std::cout << sizeof(wchar_t) << std::endl;
  //std::cout << sizeof(str[0]) << std::endl;
  //std::cout << sizeof(str[0]) << std::endl;

  //for (size_t i=0; i<str.size(); i++)
  //{
  //  std::cout << str[i] << std::endl;
  //  std::string hex;
  //  toHex(hex, str[i]);
  //  std::cout << hex.c_str() << std::endl;
  //}

  //char16_t* test = u"헬로월드";;

  //std::cout << (char*)test << std::endl;
  wchar_t str[10] = L"가라다";
  for (size_t i=0; i<10; i++)
  {
    std::cout << (unsigned int)str[i] << std::endl;
    //std::string hex;
    //toHex(hex, (unsigned char)str[i]);
    // std::cout << hex.c_str() << std::endl;
  }
  return 0;
}
