#include <iostream>
#include <cstdio>
#define PRE "prefix"
#define CONTENTS "contents"
#define SLASH "/"
#define WIN_SLASH "\\"

int main(int argc, char* argv[])
{
    int ret = -1;
    std::cout << PRE << std::endl;
    std::cout << PRE SLASH CONTENTS << std::endl;
    std::cout << PRE WIN_SLASH CONTENTS << std::endl;
    std::cout << "a" "b" "c"  << std::endl;
    printf("%s\n", "a" "b" "c");
    return ret;
}
