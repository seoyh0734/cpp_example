#include <iostream>

std::string toHex(int i)
{
  const char HEX_VALUE[17] = "0123456789ABCDEF";
  std::string hex;
  while(i>0)
  {
    hex += HEX_VALUE[i%16];
    i /= 16;
  }

  return std::string(hex.rbegin(), hex.rend());
}

std::string toHex(std::string str)
{
  std::string hexStr;
  for (size_t i=0; i<str.length(); i++)
  {
    hexStr += toHex(str[i]);
  }

  return hexStr;
}

int main(int argc, char* argv[])
{
  std::cout << toHex(212355).c_str() << std::endl;
  return 0;
}
