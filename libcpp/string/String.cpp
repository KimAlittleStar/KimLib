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
    if (num < 0)
    {
        num = 0 - num;
        append("-");
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
    
}

KString::KString(unsigned int num, NUMBER_TYPE type)
{
}

KString::KString(long long num, NUMBER_TYPE type)
{
}

KString::KString(unsigned long long num, NUMBER_TYPE type)
{
}

KString::KString(float num, int procision)
{
}

KString::KString(double num, int procision)
{
}
