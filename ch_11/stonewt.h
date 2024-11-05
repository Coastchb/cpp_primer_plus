//
// Created by 操海兵 on 17/05/2018.
//

#ifndef CH_11_STONEWT_H
#define CH_11_STONEWT_H

class Stonewt
{
private:
    static const int Lbs_per_stone = 14; //enum {Lbs_per_stone = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_stn() const;
    void show_lbs() const;
    operator int();
    operator double();

};
#endif //CH_11_STONEWT_H
