#include "String.hpp"

KString::KString()
{
}

KString::~KString()
{
}

KString::KString(int num, NUMBER_TYPE type)
{
    char numchar[65] = {0};
    int i = 0;
    numchar[0] = '0';
    if (num < 0)
    {
        num = 0 - num;
        push_back('-');
    }
    for (i = 0; i < 64 && num > 0; i++)
    {
        switch (type)
        {
        case NUMTYPE_BIN:
        case NUMTYPE_OCT:
        case NUMTYPE_ORI:
            numchar[i] = ('0' + num % type);
            break;
        case NUMTYPE_HEX:
            if (10 > (num % type))
            {
                numchar[i] = ('0' + num % type);
            }
            else
            {
                numchar[i] = ('A' + num % type - 10);
            }
            break;

        default:
            break;
        }
        num /= type;
    }
    do
    {
        push_back(numchar[i]);
        i--;
    } while (i>=0);
    
}

KString::KString(unsigned int num, NUMBER_TYPE type)
{
    INTAGER_TO_STR(num,type,push_back);
}

KString::KString(long long num, NUMBER_TYPE type)
{
    INTAGER_TO_STR(num,type,push_back);
}

KString::KString(unsigned long long num, NUMBER_TYPE type)
{
    INTAGER_TO_STR(num,type,push_back);
}

KString::KString(float num, int procision)
{
    long long numint = static_cast<long long>(num);
    INTAGER_TO_STR(numint,NUMTYPE_ORI,push_back);
    num -=numint;
    numint = static_cast<long long>(num*100000000);

}

KString::KString(double num, int procision)
{
}
