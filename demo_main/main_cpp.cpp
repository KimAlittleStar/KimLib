#include <iostream>
#include "string/String.hpp"

int main(void)
{
    KString ss(1111111111111111111LL,KString::NUMTYPE_ORI);
    std::cout<<ss<<std::endl;
    std::cout<<"hello world"<<std::endl;
    return 0;
}