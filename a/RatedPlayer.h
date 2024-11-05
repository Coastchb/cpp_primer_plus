//
// Created by 操海兵 on 23/05/2018.
//

#ifndef CH_13_RATEDPLAYER_H
#define CH_13_RATEDPLAYER_H
#include "TableTennisPlayer.h"

class RatedPlayer : public TableTennisPlayer{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0,
      const string & fn = "none", const string & ln = "none",
        bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const { return rating;}
    void ResetRating(unsigned int r) { rating = r;}
};
#endif //CH_13_RATEDPLAYER_H
