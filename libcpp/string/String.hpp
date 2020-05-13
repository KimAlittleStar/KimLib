#ifndef _STRING_HPP_
#define _STRING_HPP_
#include <string>
#include <list>
#include <vector>

class KString
{

public:
    enum NUMBER_TYPE
    {
        NUMTYPE_BIN = 2,
        NUMTYPE_OCT = 8,
        NUMTYPE_ORI = 10,
        NUMTYPE_HEX = 16
    };
    enum CASE_SENSITIVE_e
    {
        CASE_SENSITIVE = 0,
        CASE_INSENSITIVE
    };
    KString();
    KString(const char *str);
    KString(const char ch);
    KString(const std::vector<char> &str);
    KString(const std::list<char> &str);
    KString(const std::string &str);
    KString(const KString &str);
    KString(int num, NUMBER_TYPE type = NUMTYPE_ORI);
    KString(unsigned int num, NUMBER_TYPE type = NUMTYPE_ORI);
    KString(long long num, NUMBER_TYPE type = NUMTYPE_ORI);
    KString(unsigned long long num, NUMBER_TYPE type = NUMTYPE_ORI);
    KString(float num, int procision = 0);
    KString(double num, int procision = 0);
    ~KString();
    // 数字转字符串
    static KString number(int num, NUMBER_TYPE type = NUMTYPE_ORI);
    static KString number(unsigned int num, NUMBER_TYPE type = NUMTYPE_ORI);
    static KString number(long long num, NUMBER_TYPE type = NUMTYPE_ORI);
    static KString number(unsigned long long num, NUMBER_TYPE type = NUMTYPE_ORI);
    static KString number(float num, int procision = 0);
    static KString number(double num, int procision = 0);
    KString utf8ToANSI(const KString &utf8);
    std::list<KString> split(const KString &spchar, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE) const;
    std::list<KString> split(const std::string &spchar, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE) const;
    std::list<KString> split(const char &spchar, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE) const;
    std::list<KString> split(const char *spchar, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE) const;
    std::list<KString> extract(const char *exstr) const;
    std::list<KString> extract(const std::string &exstr) const;
    signed int toint32(bool &err) const;
    unsigned int touint32(bool &err) const;
    signed short toint16(bool &err) const;
    unsigned short touint16(bool &err) const;
    signed char toint8(bool &err) const;
    unsigned char touint8(bool &err) const;
    float tofolat(bool &err) const;
    double todouble(bool &err) const;
    int remove(int start, int end);
    int remove(const KString &str, int rmcount = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int remove(const std::string &str, int rmcount = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int remove(const char *str, int rmcount = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int removeFromLast(const KString &str, int rmcount = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int removeFromLast(const std::string &str, int rmcount = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int removeFromLast(const char *str, int rmcount = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int replace(const KString &des, const KString &src, int replace_count = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int replace(const std::string &des, const std::string &src, int replace_count = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int replace(const char *des, const char *src, int replace_count = -1, CASE_SENSITIVE_e case_sensitive = CASE_SENSITIVE);
    int replace(int start, int end = -1);

    inline int length() const { return _length; }

    int size() const { return _length; }

    std::string toStdString() const;
    std::vector<char> toVector() const;
    const char *toC_str() const;
    char *toC_str();

    int append(const char *str);
    int append(const char ch);
    int append(const std::vector<char> &str);
    int append(const std::list<char> &str);
    int append(const std::string &str);
    int append(const KString &str);
    friend std::ostream &operator<<(std::ostream &os, const KString &str);
    const char operator[](int i) const;
    char &operator[](int i);

private:
    std::vector<char> _data;
    int _length = 0;
    bool push_back(const char ch);
    bool check_append(int newsize = 0);

#define INTAGER_TO_STR(num, type, append_function)            \
    ({                                                        \
        if (type != 0)                                        \
        {                                                     \
            char numchar[65] = {0};                           \
            int i = 0;                                        \
            numchar[0] = '0';                                 \
            if (num < 0)                                      \
            {                                                 \
                num = 0 - num;                                \
                append_function('-');                         \
            }                                                 \
            for (i = 0; i < 64 && num > 0; i++)               \
            {                                                 \
                switch (type)                                 \
                {                                             \
                case NUMTYPE_BIN:                             \
                case NUMTYPE_OCT:                             \
                case NUMTYPE_ORI:                             \
                    numchar[i] = ('0' + num % type);          \
                    break;                                    \
                case NUMTYPE_HEX:                             \
                    if (10 > (num % type))                    \
                    {                                         \
                        numchar[i] = ('0' + num % type);      \
                    }                                         \
                    else                                      \
                    {                                         \
                        numchar[i] = ('A' + num % type - 10); \
                    }                                         \
                    break;                                    \
                default:                                      \
                    break;                                    \
                }                                             \
                num /= type;                                  \
            }                                                 \
            if (i == 0)                                       \
            {                                                 \
                i = 1;                                        \
            }                                                 \
            do                                                \
            {                                                 \
                i--;                                          \
                append_function(numchar[i]);                  \
            } while (i >= 0);                                 \
        }                                                     \
    })
};

#endif