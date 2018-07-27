//
// Created by 操海兵 on 04/06/2018.
//

#ifndef CH_13_ACCTABC_H
#define CH_13_ACCTABC_H

#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting{
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string& FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const std::string& s = "Nobody", long an = -1,
      double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0;
    virtual ~AcctABC() {}
};

// Brass Account Class
class Brass1 : public AcctABC
{
public:
    Brass1(const std::string& s = "Nobody", long an = -1,
      double bal = 0.0) : AcctABC(s,an,bal){}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass1() {};
};

// BrassPlus Account Class
class BrassPlus1 : public AcctABC{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus1(const std::string& s = "Nobody", long an = -1,
      double bal = 0.0, double ml = 500, double r = 0.1);
    BrassPlus1(Brass1& brass, double ml = 500.0, double r = 0.10);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double ml) { maxLoan = ml; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};
#endif //CH_13_ACCTABC_H
