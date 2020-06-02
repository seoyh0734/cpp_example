#include <stdio.h>
#include <string.h>

static bool replaceAll(char *src, const char *olds, const char *news)
{
  char result[100];
  char *first = src;
  char *target;
  size_t len = 0;
  size_t newlen = 0;
  size_t oldlen = strlen(olds);
  printf("src = %s\n", src);
  if (oldlen < 1) return false;

  newlen = strlen(news);
  printf("news = %s, newlen = %d\n", news, newlen);
  target = result;
  printf("target = %p, result = %p\n", target, result);
  int cnt =0;
  while (*src) {
    cnt++;
    printf("cnt = %d\n", cnt);
    printf("src = %s\n", src);
    printf("result = %s\n", result);
    if (memcmp(src, olds, oldlen) == 0) {
      printf("ok\n");
      memcpy(target, news, newlen);
      target += newlen;
      src  += oldlen;
    }
    else
      printf("no\n");
      *target++ = *src++;
  }
  *target = '\0';
  printf(" last result = %s\n", result);

  len = strlen(result);
  printf("len = %d\n", len);
  if( len > 2 )
  {
    memset(first, 0x00, 100 );
    memcpy(first, result, len);

    return true;
  }

  return false;
}


int main(int argc, char* argv[]){
  char tmp[100] = "test-test-test";
  printf("tmp =%s\n",tmp);
  replaceAll(tmp,"-", "/");
  printf("tmp =%s\n",tmp);
  return 0;

}
