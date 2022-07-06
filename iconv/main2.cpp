/*
iconv를 활용한 코드 변환 (EUC-KR <-> UTF-8)
gcc 버전에 따라 glibc에 포함된 경우는 -lc를 하고 그렇지 않은 경우는 -liconv를 링크한다.
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iconv.h>
#include <errno.h>
 
 
int main()
{
    int ret;
    char ksc_buf[1024] = "한글과 유니코드";
     
    // KSC(완성형) 코드를 UTF(유니코드)로 변환하면 원래 크기보다 커지므로 크게~
    char utf_buf[1024] = {0x00, };
    size_t in_size, out_size;
 
    //sprintf(ksc_buf, "%s", "한글과 유니코드");
    //memset(utf_buf, '\0', 1024);
 
    // 어떤 시스템에서는 char** 가 아니라 const char** 인 경우도 있음
    char *input_buf_ptr = ksc_buf;
    char *output_buf_ptr = utf_buf;
 
    in_size = strlen(ksc_buf);
    out_size = sizeof(utf_buf);
    iconv_t it;
 
    it = iconv_open("UTF-8", "EUC-KR"); // EUC-KR을 UTF-8로
    ret = iconv(it, &input_buf_ptr, &in_size, &output_buf_ptr, &out_size);
     
    if (ret < 0)
    {
        printf("ret : %d, errno : %d\n", ret, errno);
        return(-1);
    }
    else
    {
        printf("[%s](%d) => [%s][(%d)\n",
            ksc_buf, in_size, utf_buf, out_size);
    }
     
    iconv_close(it);
 
    input_buf_ptr = utf_buf;
    output_buf_ptr = ksc_buf;
 
    in_size = strlen(utf_buf);
    out_size = sizeof(ksc_buf);
 
    it = iconv_open("EUC-KR", "UTF-8"); // UTF-8을 EUC-KR로
    ret = iconv(it, &input_buf_ptr, &in_size, &output_buf_ptr, &out_size);
 
    if (ret < 0)
    {
        printf("ret : %d, errno : %d\n", ret, errno);
        return(-1);
    }
    else
    {
        printf("[%s](%d) => [%s][(%d)\n",
            utf_buf, in_size, ksc_buf, out_size);
    }
     
    iconv_close(it);
}
