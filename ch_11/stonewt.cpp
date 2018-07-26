//
// Created by 操海兵 on 17/05/2018.
//
#include <iostream>
#include "stonewt.h"
using std::cout;

Stonewt::Stonewt() {
  stone = pds_left = pounds = 0;
}

Stonewt::Stonewt(double lbs) {
  stone = int(lbs) / Lbs_per_stone;
  pds_left = int(lbs) % Lbs_per_stone + lbs - int(lbs);
  pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs) {
  stone = stn;
  pounds = lbs;
  pds_left = stn * Lbs_per_stone + lbs;
}
Stonewt::~Stonewt() {}

void Stonewt::show_stn() const {
  cout << stone << " stone, " << pds_left << " pounds\n";
}
void Stonewt::show_lbs() const {
  cout << pounds << " pounds\n";
}

Stonewt::operator int()
{
  return int(pounds + 0.5);
}

Stonewt::operator double()
{
  return pounds;
}