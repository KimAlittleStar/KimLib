#include "String.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
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
    int old_size = _length;
    check_append(_length + str.size());
    for (char i : str)
    {
        if (i == '\0')
            break;
        _data[_length++] = i;
    }
    return _length - old_size;
}
int KString::append(const std::string &str)
{
    int old_size = _length;
    check_append(_length + str.size());
    for (char i : str)
    {
        if (i == '\0')
            break;
        _data[_length++] = i;
    }
    return _length - old_size;
}
int KString::append(const KString &str)
{
    int old_size = _length;
    check_append(_length + str.length());
    for (int i = 0; str[i] != 0; i++)
    {
        _data[_length++] = str[i];
    }
    return _length - old_size;
}
bool KString::push_back(const char ch)
{
    check_append(_length + 1);
    _data[_length++] = ch;
    return true;
}

inline bool KString::check_append(int newsize)
{
    if (static_cast<size_t>(newsize) >= _data.size())
        _data.resize((newsize + 1) * 4 / 3, 0);
    return true;
}

std::ostream &operator<<(std::ostream &os, const KString &str)
{
    os << str._data.data();
    return os;
}
inline bool KString::equal_char(const char &ch1, const char &ch2, CASE_SENSITIVE_e case_sensitive)
{
    switch (case_sensitive)
    {
    case CASE_SENSITIVE:
        return ch1 == ch2;

    case CASE_INSENSITIVE:
        return ((ch1 ^ ch2) == 0x20) && ((ch1 | 0x20) >= 'a') && ((ch1 | 0x20) <= 'z');

    default:
        return false;
    }
}
bool KString::equals(const KString &str, CASE_SENSITIVE_e case_sensitive)
{
    if (this->_length != str.length())
    {
        return false;
    }
    if (case_sensitive == CASE_INSENSITIVE)
    {
        for (int i = 0; i < _length; i++)
        {
            if (equal_char(_data[i], str[i], case_sensitive) == false)
                return false;
        }
    }
    else
    {
        std::cout << "memcmp = " << memcmp(_data.data(), str.toC_str(), _length) << std::endl;
        return memcmp(_data.data(), str.toC_str(), _length) == 0;
    }
    return true;
}
signed int KString::toint32(bool &err) const
{
    int ret = 0;
    if(sscanf(this->toC_str(),"%d",&ret) != 1)
        err = false;
    else
        err = true;
    return ret;
}
unsigned int KString::touint32(bool &err) const
{
    unsigned int ret = 0;
    if (sscanf(this->toC_str(), "%u", &ret) != 1)
        err = false;
    else
        err = true;
    return ret;
}
signed short KString::toint16(bool &err) const
{
    int ret = 0;
    if (sscanf(this->toC_str(), "%hd", &ret) != 1)
        err = false;
    else
        err = true;
    return ret;
}
unsigned short KString::touint16(bool &err) const
{
    unsigned short ret = 0;
    if (sscanf(this->toC_str(), "%hu", &ret) != 1)
        err = false;
    else
        err = true;
    return ret;
}
signed char KString::toint8(bool &err) const
{
    int ret = 0;
    if (sscanf(this->toC_str(), "%d", &ret) != 1)
        err = false;
    else
        err = true;
    return static_cast<signed char>(ret);
}
unsigned char KString::touint8(bool &err) const
{
    unsigned int ret = 0;
    if (sscanf(this->toC_str(), "%u", &ret) != 1)
        err = false;
    else
        err = true;
    return static_cast<unsigned char> (ret);
}
float KString::tofolat(bool &err) const
{
    float ret = 0;
    if (sscanf(this->toC_str(), "%f", &ret) != 1)
        err = false;
    else
        err = true;
    return ret;
}
double KString::todouble(bool &err) const
{
    double ret = 0;
    if (sscanf(this->toC_str(), "%lf", &ret) != 1)
        err = false;
    else
        err = true;
    return ret;
}

signed int KString::toint32() const
{
    bool err = true;
    return toint32(err);
}
unsigned int KString::touint32() const
{
    bool err = true;
    return touint32(err);
}
signed short KString::toint16() const
{
    bool err = true;
    return toint16(err);
}
unsigned short KString::touint16() const
{
    bool err = true;
    return touint16(err);
}
signed char KString::toint8() const
{
    bool err = true;
    return toint8(err);
}
unsigned char KString::touint8() const
{
    bool err = true;
    return touint8(err);
}
float KString::tofolat() const
{
    bool err = true;
    return tofolat(err);
}
double KString::todouble() const
{
    bool err = true;
    return tofolat(err);
}

KString KString::subStr(int star, int end) const
{
    KString ret;
    if (star >= _length)
        return ret;
    if (end >= _length)
        end = _length;
    ret.check_append(end - star);
    for (int i = star; i < end;i++)
    {
        ret[i] = _data[i];
    }
    return ret;
}
