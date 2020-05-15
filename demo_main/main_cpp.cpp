#include <iostream>
#include "string/String.hpp"

int main(void)
{
    KString ss(3.0);
    KString sa("qwertyuio");
    KString sb = "QWERTYUIO";
    std::cout << sb << std::endl;
    std::cout << sa << std::endl;
    std::cout << sa.equals(KString("QWERTYUIO")) << std::endl;
    std::cout << sa.equals(sb) << std::endl;
    std::cout << sa.equals(sb,KString::CASE_INSENSITIVE) << std::endl;
    std::cout << "###"<<ss.tofolat()<< std::endl;

    ss.append("_hello");
    std::cout << ss << ss.size() << std::endl;
    std::cout << "hello world" << std::endl;
    return 0;
}