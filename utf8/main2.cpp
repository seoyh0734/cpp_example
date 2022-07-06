#include <iostream>
#include <bitset>

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
        std::string binary = std::bitset<24>(codePoint).to_string();

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

    return 0;
}

int main(int argc, char* argv[])
{
    int ret = -1;

    //std::string utf8;    
    //stringUTF8(utf8, L"가안녕하세요. 반갑습니다.핡");

    //std::cout << utf8.c_str() << std::endl;
    //std::cout << utf8.size() << std::endl;
    char str[4] = "长";
    wchar_t c = L'长';
    std::cout << (int)c << std::endl;

    for (unsigned int i=0; i<4; i++)
    {
      std::cout << (unsigned short)str[i] << std::endl;
    }
    std::cout << str << std::endl;

    return ret;
}
