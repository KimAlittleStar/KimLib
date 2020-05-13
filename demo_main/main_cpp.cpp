#include <iostream>
#include "string/String.hpp"

int main(void)
{
    KString ss(3.9902);
    KString sa("qwertyuio");
    std::cout<<ss<<std::endl;
    std::cout<<sa<<std::endl;
    ss.append("_hello");
    std::cout << ss << ss.size() << std::endl;
    std::cout << "hello world" << std::endl;
    return 0;
}