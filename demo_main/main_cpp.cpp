#include <iostream>
#include "string/String.hpp"
#include <string>
using namespace std;
class Employee
{
    
};
int main(void)
{
    KString ss(3.0,2);
    KString sa("qwertyuio");
    KString sb = "QWERTYUIO";
    std::cout << sb << std::endl;
    std::cout << sa << std::endl;
    std::cout << sa.equals(KString("QWERTYUIO")) << std::endl;
    std::cout << sa.equals(sb) << std::endl;
    std::cout << sa.equals(sb,KString::CASE_INSENSITIVE) << std::endl;
    std::cout <<"indexof 1"<< sa.indexOf(sb.toC_str(), KString::CASE_INSENSITIVE) << std::endl;
    std::cout << "indexof 2" <<sa.indexOf(sb.toC_str(), KString::CASE_SENSITIVE) << std::endl;
    std::cout << "indexof 3:" <<sa.indexOf("tyu", KString::CASE_INSENSITIVE) << std::endl;
    std::cout << "indexof 4:" <<sa.indexOf("tyu", KString::CASE_SENSITIVE) << std::endl;

    std::cout << "###" << ss.tofolat() << std::endl;

    ss.append("_hello");
    std::cout << ss << ss.size() << std::endl;
    std::cout << "hello world" << std::endl;
    return 0;
}