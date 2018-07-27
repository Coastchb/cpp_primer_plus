//
// Created by 操海兵 on 24/05/2018.
//
#include "Brass.h"
#include <iostream>
using std::cout;
using std::endl;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();
void restore(format f, precis p);

Brass::Brass(const string &s, long an, double bal) {
  cout << "Brass default constructor called.\n";
  fullName = s;
  acctNum = an;
  balance = bal;
}

void Brass::Deposit(double amt) {

  if(amt < 0 )
    cout << "Negative deposit is not allowed;"
            << "deposit is cancelled.\n";
  else
    balance += amt;
}

void Brass::Withdraw(double amt) {
  format init_f = setFormat();
  precis init_p = cout.precision(3);

  if(amt < 0)
    cout << "Withdrawal amount must be positive;"
            << "withdrawal cancelled.\n";
  else if (amt <= balance)
    balance -= amt;
  else
    cout << "Withdrawal amount of $" << amt
         << " exceeds your balance;"
            << "Withdrawal cancelled.\n";
  restore(init_f, init_p);
}

double Brass::Balance() const {
  return balance;
}

void Brass::ViewAcct() const {
  format init_f = setFormat();
  precis init_p = cout.precision(3);

  cout << "Client: " << fullName << endl;
  cout << "Account Number:" << acctNum << endl;
  cout << "Balance: $" << balance << endl;
  restore(init_f, init_p);
}

void Brass::new_fun() {
  cout << "A new function in base class.\n";
}

// mark 2
BrassPlus::BrassPlus(const string &s, long an, double bal, double max, double r)
  : Brass(s,an,bal) {
  cout << "BrassPlus constructor called." << endl;
  // Brass(s,an,bal);
  maxLoad = max;
  rate = r;
  owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &brass, double max, double r)
  : Brass(brass)
{
  maxLoad = max;
  rate = r;
  owesBank = 0.0;
}

void BrassPlus::ViewAcct() const {
  format init_f = setFormat();
  precis init_p = cout.precision(3);

  // mark 6
  Brass::ViewAcct();
  cout << "Maximum Load: $" << maxLoad << endl;
  cout << "Owed to bank: $" << owesBank << endl;
  cout.precision(3);
  cout << "Load rate:" << rate * 100 << "%" << endl;
  restore(init_f, init_p);
}

void BrassPlus::Withdraw(double amt) {
  format init_f = setFormat();
  precis init_p = cout.precision(3);

  double bal = Balance();

  if ( amt <= bal)
    Brass::Withdraw(amt);
  else if ( amt <= bal + maxLoad - owesBank ){
    double advance = amt - bal;
    owesBank += advance * ( 1 + rate);
    Deposit(advance);
    Brass::Withdraw(amt);
  }
  else
    cout << "Credit limit exceeded. Transaction cancelled.\n";
  restore(init_f,init_p);
}

void BrassPlus::new_fun() {
  cout << " A new function in child class.\n";
}

format setFormat(){
  return cout.setf(std::ios_base::fixed,
  std::ios_base::floatfield);
}

void restore(format f, precis p){
  cout.setf(f, std::ios_base::floatfield);
  cout.precision(p);
}