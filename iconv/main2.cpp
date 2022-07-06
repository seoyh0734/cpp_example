/*
iconv�� Ȱ���� �ڵ� ��ȯ (EUC-KR <-> UTF-8)
gcc ������ ���� glibc�� ���Ե� ���� -lc�� �ϰ� �׷��� ���� ���� -liconv�� ��ũ�Ѵ�.
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
    char ksc_buf[1024] = "�ѱ۰� �����ڵ�";
     
    // KSC(�ϼ���) �ڵ带 UTF(�����ڵ�)�� ��ȯ�ϸ� ���� ũ�⺸�� Ŀ���Ƿ� ũ��~
    char utf_buf[1024] = {0x00, };
    size_t in_size, out_size;
 
    //sprintf(ksc_buf, "%s", "�ѱ۰� �����ڵ�");
    //memset(utf_buf, '\0', 1024);
 
    // � �ý��ۿ����� char** �� �ƴ϶� const char** �� ��쵵 ����
    char *input_buf_ptr = ksc_buf;
    char *output_buf_ptr = utf_buf;
 
    in_size = strlen(ksc_buf);
    out_size = sizeof(utf_buf);
    iconv_t it;
 
    it = iconv_open("UTF-8", "EUC-KR"); // EUC-KR�� UTF-8��
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
 
    it = iconv_open("EUC-KR", "UTF-8"); // UTF-8�� EUC-KR��
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
