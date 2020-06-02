#include <iostream>

class classA
{
  public:
    classA(int num)
    {
        this->num = num;
    }
    int num = 0;
};

classA funcB()
{
    std::cout << "funcB" << std::endl;
    return classA(100);
}

int funcA()
{
    std::cout << "funcA" << std::endl;
    static classA a = funcB();
    return 0;
}

int main(int argc, char* argv[])
{
    funcA();
    funcA();
    funcA();
    funcA();
    funcA();
    funcA();
    return 0;
}
