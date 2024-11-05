//
// Created by 操海兵 on 16/05/2018.
//

#ifndef CH_10_STOCK00_H
#define CH_10_STOCK00_H

#include <string>

class Stock
{
private:
    std::string company_;
    long shares_;
    double share_val_;
    double total_val_;
    void set_tot() { total_val_ = shares_ * share_val_;}
public:
    Stock();
    Stock(const std::string & company, long n = 0, double pr = 0);
    ~Stock();
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & ) const;
};
#endif //CH_10_STOCK00_H
