#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
  string strMulti = "멀티바이트";
  int nLen = MultiByteToWideChar(CP_ACP, 0, &strMulti[0], strMulti.size(), NULL, NULL);
  cout << "len = " << nLen << endl;

  wstring strUni(nLen, 0);
  MultiByteToWideChar(CP_ACP, 0, &strMulti[0], strMulti.size(), &strUni[0], nLen);

  cout << strUni << endl;

  return 0;
}
