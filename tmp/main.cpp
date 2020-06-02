#include <iostream>

using namespace std;

int bin2hex_nnt(char *buf, char *textbuf, int len)
{
  char hexs[]="0123456789ABCDEF";
  int i;
  int j=0;
  for(i=0;i<len;i++)
  {
    textbuf[j++] = hexs[ (buf[i]>>4)&0x0f ];
    textbuf[j++] = hexs[ buf[i]&0x0f ];
  }
  return j;
}

int main(int argc, char** argv) {
  char* testbuf = "1";

  cout << testbuf << endl;

  return 1;
}
