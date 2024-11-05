//
// Created by Apple on 2018/5/18.
//

#ifndef CH_12_STRING_H
#define CH_12_STRING_H


#include <iostream>
class string
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    string();
    string(const string & s);
    string(const char * s);
    ~string();
    char & operator[](int i);
    const char & operator[](int i) const;
    int length() const;
    static int HowMany();
    string operator=(const char * s);
    string& operator=(const string & s);

    friend bool operator<(const string &s1, const string &s2);
    friend bool operator>(const string &s1, const string &s2);
    friend bool operator==(const string &s1, const string &s2);
    friend std::ostream &operator<<(std::ostream & os, const string& s);
    friend std::istream & operator>>(std::istream & is, string& s);

};

#endif //CH_12_STRING_H
