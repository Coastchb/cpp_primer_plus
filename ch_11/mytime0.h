//
// Created by 操海兵 on 17/05/2018.
//

#ifndef CH_11_MYTIME0_H
#define CH_11_MYTIME0_H

#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int minute=0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time & t) const;
    Time operator+(const Time & t) const;
    void Show() const;
    Time operator*(double d) const;
    friend  Time operator*(double d, const Time & t);
    friend std::ostream & operator<<( std::ostream & out, const Time & t);

};
#endif //CH_11_MYTIME0_H
