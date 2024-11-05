//
// Created by 操海兵 on 17/05/2018.
//
#include "mytime0.h"
//#include <iostream>

Time::Time() {
  hours = minutes = 0;
}
Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}
void Time::AddHr(int h) {
  hours += h;
}
void Time::AddMin(int m) {
  minutes += m;
  hours += minutes/60;
  minutes %= 60;
}
void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time Time::Sum(const Time &t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + (sum.minutes / 60);
  sum.minutes = sum.minutes % 60;
  return sum;
}

Time Time::operator+(const Time &t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + (sum.minutes / 60);
  sum.minutes = sum.minutes % 60;
  return sum;
}
void Time::Show() const {
  std::cout << hours << " hours," << minutes << " minutes\n";
}

Time Time::operator*(double d) const {
  Time ret;
  long totalMinutes = hours * d * 60 + minutes * d;
  ret.hours = totalMinutes / 60;
  ret.minutes = totalMinutes % 60;
  return ret;
}

Time operator*(double d, const Time & t)
{
  Time ret;
  long totalMinutes = t.hours * d * 60 + t.minutes * d;
  ret.hours = totalMinutes / 60;
  ret.minutes = totalMinutes % 60;
  return ret;
}


std::ostream & operator<<(std::ostream & out, const Time & t)
{
  out << t.hours << "h" << t.minutes <<"m\n";
  return out;
}
