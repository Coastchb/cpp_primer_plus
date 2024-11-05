//
// Created by 操海兵 on 23/05/2018.
//

#ifndef CH_13_TABLETENNISPLAYER_H
#define CH_13_TABLETENNISPLAYER_H
#include <string>
using std::string;

class TableTennisPlayer{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none",
      const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable;}
    void SetHasTable(bool v) { hasTable = v;}
};
#endif //CH_13_TABLETENNISPLAYER_H
