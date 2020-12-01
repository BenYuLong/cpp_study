#include "common.hpp"
#include <vector>
#include <iostream>
#include <functional>

namespace tt
{
    enum MyEnum
    {
        W = 1,
        R = 2
    };
}

bool divided7(int x)
{    
    return (0 == x % 7);
}


int main(int argc, char const *argv[])
{
    std::vector<int> v(100);
    std::generate(v.begin(),v.end(),std::rand);

    std::cout << std::endl;
    for (auto item : v)
    {
        std::cout << item << "\t";
    }
    std::cout << std::endl;

    int num = std::count_if(v.begin(), v.end(), divided7);
    std::cout << "divided7 count : " << num << std::endl;

    // lambda表达式代替divided7函数
    int lambdaNum = std::count_if(v.begin(), v.end(), [](int x){return x % 7 == 0;});
    std::cout << "Lambda divided7 count : " << lambdaNum << std::endl;

    //
    int aa = 10;
    auto ff = [=]()mutable{return aa *= 10;};
    std::cout << ff() << "  " << aa << std::endl;

    //
    std::function<int(int)> fun = [&fun](int x) {
        return x < 2 ? 1 : fun(x - 1) + fun(x - 2);
    };
    std::cout << fun(5) << std::endl;
    return 0;
}

