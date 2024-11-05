//
// Created by 操海兵 on 24/05/2018.
//

#ifndef CH_13_BRASS_H
#define CH_13_BRASS_H

#include <string>
using std::string;

const int A = 3;

class Brass{
private:
    string fullName;
    long acctNum;
    double balance;
public:
    Brass(const string& s = "NoBody", long an = -1,
      double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    void new_fun();
    virtual ~Brass(){};
};

class BrassPlus : public Brass{
private:
    double maxLoad;
    double rate;
    double owesBank;
public:
    // mark 3
    BrassPlus(const string& s = "subNoBody", long an = -2,
      double bal = 0.1, double max = 500, double rate = 0.11125); // : Brass(s,an,bal){};
    BrassPlus(const Brass& brass, double max = 500, double rate = 0.11125);
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    void new_fun();
    void ResetMaxLoad(double m) { maxLoad = m;}
    void ResetRate(double r) { rate = r;}
    void ResetOwes() { owesBank = 0;}

};
#endif //CH_13_BRASS_H
