//
// Created by 操海兵 on 23/05/2018.
//
#include "RatedPlayer.h"
#include <iostream>

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
  : TableTennisPlayer(tp)
{
  rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht)
  : TableTennisPlayer(fn, ln, ht)
{
  rating = r;
}