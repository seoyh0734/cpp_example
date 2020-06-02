#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRLEN 32768

char* rtrim(char* s)
{
  char t[MAX_STRLEN];
  char *end;

  strcpy(t, s);
  end = t + strlen(t) - 1;
  while (end != t && isspace(*end))
    end--;
  *(end + 1) = '\0';
  s = t;

  return s;
}

int main(int argc, char* argv[])
{
  char a[100]="abcdegfd  sdf  dsds    ";
  char *b;
  printf("a = [%s]\n", a);
  printf("strlen(a) = %d\n", strlen(a));

  b = rtrim(a);
  printf("b = [%s]\n", b);
  printf("strlen(b) = %d\n", strlen(b));

  return 0;
}
