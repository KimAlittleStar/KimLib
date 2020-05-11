#include "String.hpp"
#include <iostream>
#include <stdio.h>
KString::~KString()
{
}

KString::KString()
{
    check_append();
}
KString::KString(const char *str)
{
    check_append();
    append(str);
}
KString::KString(const char ch)
{
    check_append();
    append(ch);
}
KString::KString(const std::vector<char> &str)
{
    check_append();
    append(str);
}
KString::KString(const std::list<char> &str)
{
    check_append();
    append(str);
}
KString::KString(const std::string &str)
{
    check_append();
    append(str);
}
KString::KString(const KString &str)
{
    check_append();
    append(str);
}
KString::KString(int num, NUMBER_TYPE type)
{
    char numchar[65] = {0};
    int i = 0;
    numchar[0] = '0';
    check_append();
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
    } while (i >= 0);
}

KString::KString(unsigned int num, NUMBER_TYPE type)
{
    check_append();
    INTAGER_TO_STR(num, type, push_back);
}

KString::KString(long long num, NUMBER_TYPE type)
{
    check_append();
    INTAGER_TO_STR(num, type, push_back);
}

KString::KString(unsigned long long num, NUMBER_TYPE type)
{
    check_append();
    INTAGER_TO_STR(num, type, push_back);
}

KString::KString(float num, int procision)
{
    check_append();
    char numstr[66] = {0};
    char fmt[10] = {0};
    procision = (procision > 8) ? (8) : (procision);
    sprintf(fmt, "%%.%dlf", procision);
    if (procision <= 0)
    {
        sprintf(numstr, "%lf", num);
    }
    else
    {
        sprintf(numstr, fmt, num);
    }
    append(numstr);
}

KString::KString(double num, int procision)
{
    check_append();
    char numstr[66] = {0};
    char fmt[10] = {0};
    procision = (procision > 15) ? (15) : (procision);
    sprintf(fmt, "%%.%dlf", procision);
    if (procision <= 0)
    {
        sprintf(numstr, "%lf", num);
    }
    else
    {
        sprintf(numstr, fmt, num);
    }
    for (int i = sizeof(numstr) - 1; i >= 0; i--)
    {
        if (numstr[i] != '0' && numstr[i] != '\0' && numstr[i] != '.')
        {
            numstr[i + 1] = 0;
            break;
        }
    }
    append(numstr);
}
int KString::append(const char *str)
{
    int strlen = 0;
    while (str != nullptr && *(str + strlen) != 0)
        strlen++;
    check_append(_length + strlen);
    strlen = 0;
    while (str != nullptr && *(str + strlen) != 0)
    {
        _data[_length++] = *(str + strlen);
        strlen++;
    }
    return strlen;
}
int KString::append(const char ch)
{
    if (ch != '\0')
    {
        push_back(ch);
        return 1;
    }
    return 0;
}
int KString::append(const std::vector<char> &str)
{
    return append(str.data());
}
int KString::append(const std::list<char> &str)
{
    check_append(_length + str.size());
    for (char i : str)
    {
        if (i == '\0')
            break;
        _data[_length++] = i;
    }
}
int KString::append(const std::string &str)
{
    check_append(_length + str.size());
    for (char i : str)
    {
        if (i == '\0')
            break;
        _data[_length++] = i;
    }
}
int KString::append(const KString &str)
{
    check_append(_length + str.length());
    for (int i = 0; str[i] != 0; i++)
    {
        _data[_length++] = str[i];
    }
}
bool KString::push_back(const char ch)
{
    check_append(_length + 1);
    _data[_length++] = ch;
    return true;
}
int KString::length() const
{
    return _length;
}
bool KString::check_append(int newsize)
{
    if (newsize >= _data.size())
        _data.resize((newsize + 1) * 4 / 3, 0);
    return true;
}

int KString::size() const
{
    return _data.size() - 1;
}

std::ostream &operator<<(std::ostream &os, const KString &str)
{
    os << str._data.data();
    return os;
}

const char KString::operator[](int i) const
{
    return _data[i];
}
char &KString::operator[](int i)
{
    return _data[i];
}
