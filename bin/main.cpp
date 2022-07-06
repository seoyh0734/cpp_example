#include <iostream>
#include <cmath>
#include <sstream>
#include <bitset>

#define ERR_SUCCESS 0

std::string intToBinStr(unsigned long num, int size)
{
  std::string str = "";

  std::cout << "num : " << num << std::endl;

  for (int i=0; i<size; i++)
  {
    std::cout << "num : " << num << std::endl;
    if ((num%2) == 0)
    {
      str = std::string("0") + str;
    }
    else
    {
      str = std::string("1") + str;
    }
    num = num >> 1;
  }

  return str;
}

int codePointToUtf8(char* output, unsigned int &outputLen, long codePoint)
{
    /* Return ASCII */
    if (codePoint <= 126)
    {
        output[0] = codePoint;
        output[1] = '\0';
        outputLen = 1;

        return 0;
    }

    /* Mapping 2 Bytes Code */
    if (codePoint <= 2047)
    {
        output[0] = '\0';
        outputLen = 0;
        return -1;
    }

    /* Mapping 3 Bytes Code */
    if (codePoint <= 65535)
    {
        //std::string binary = std::bitset<24>(codePoint).to_string();
        std::string binary = intToBinStr(codePoint, 24);

        output[0] = (char)std::bitset<8>(std::string("1110") + binary.substr(8, 4)).to_ulong();
        output[1] = (char)std::bitset<8>(std::string("10") + binary.substr(12, 6)).to_ulong();
        output[2] = (char)std::bitset<8>(std::string("10") + binary.substr(18, 6)).to_ulong();
        output[3] = '\0';
        outputLen = 3;

        return 0;
    }

    output[0] = '\0';
    outputLen = 0;
    return -1;
}

int stringUTF8(std::string &str, std::wstring codePoint)
{
    std::string utf8;

    for (unsigned int i = 0; i<codePoint.size(); i++)
    {
        char buf[4] = { 0x00, };
        unsigned int bufLen = 4;

        if (codePointToUtf8(buf, bufLen, (int)codePoint[i]) != 0)
        {
            return -1;

        }
        utf8 += std::string(buf);
    }

    str = utf8;

    return ERR_SUCCESS;
}

std::string stringUTF8(std::wstring codePoint)
{
    std::string utf8;

    for (unsigned int i = 0; i<codePoint.size(); i++)
    {
        char buf[4] = { 0x00, };
        unsigned int bufLen = 4;

        if (codePointToUtf8(buf, bufLen, (int)codePoint[i]) != 0)
        {
            return "";
        }
        utf8 += std::string(buf);
    }

    return utf8;
}


int main(int argc, char* argv[])
{
  //long i = 16214;
  //std::string str = intToBinStr(i, 24);
  //std::cout << str.c_str() << std::endl;
  ////while (1)
  //{
  //std::cout << stringUTF8(L"가.민이asdkl").c_str() << std::endl;
  //}
  //int codePoint = 100;
  //std::string str = "";
  //std::bitset<24> bit(codePoint);

  //std::cout << bit << std::endl;

  //std::cout << str.c_str() << std::endl;
  std::cout << 1 / 15 << std::endl;
  return 0;
}
