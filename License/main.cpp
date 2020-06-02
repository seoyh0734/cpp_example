#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]) {
  char tmp[100]="MDFLtestM1DFL";

  int result = strncmp(tmp, "MDFL", 4);

  printf("result =%d\n", result);

return 0;
}
