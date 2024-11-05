//
// Created by 操海兵 on 23/05/2018.
//
#include "TableTennisPlayer.h"
#include <iostream>
using std::cout;
using std::endl;

TableTennisPlayer::TableTennisPlayer(const string &fn,
                                     const string &ln, bool ht) {
  firstname = fn;
  lastname = ln;
  hasTable = ht;
}

void TableTennisPlayer::Name() const {
  cout << lastname << "," << firstname;
}
