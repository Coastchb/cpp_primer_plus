//
// Created by 操海兵 on 18/05/2018.
//

#ifndef CH_12_STRNGBAD_H
#define CH_12_STRNGBAD_H

#include <iostream>
class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const char * s);
    StringBad();
    StringBad(StringBad &);
    ~StringBad();
    StringBad&operator=(StringBad & s);
    friend std::ostream &operator<<(std::ostream & os,
      const StringBad & st);
};

#endif //CH_12_STRNGBAD_H
