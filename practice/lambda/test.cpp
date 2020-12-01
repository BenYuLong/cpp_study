#include <vector>
#include <iostream>

class Hello
{   
    typedef enum
    {
        A = 1,
        B = 2,
    }TTTT;
};

namespace test
{
    class Hello;
    
    typedef enum
    {
        A = 1,
        B = 2,
    } TTTT;

    enum MyEnum
    {
        W = 1,
        R = 2
    };
}
int main(int argc, char const *argv[])
{
    std::cout << test::W << std::endl;
    Hello *hello = new Hello();
    std::cout << test::B << std::endl;
    return 0;
}

