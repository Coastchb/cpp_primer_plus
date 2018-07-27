//
// Created by 操海兵 on 04/06/2018.
//

#include "acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

// Abstract Base Class
AcctABC::AcctABC(const std::string &s, long an, double bal) {
  fullName = s;
  acctNum = an;
  balance = bal;
}
void AcctABC::Deposit(double amt){
  if(amt < 0) {
    cout << "Negative deposit is not allowed;"
         << "deposit is cancelled.\n";
  }
  else{
      balance += amt;
  }
}
void AcctABC::Withdraw(double amt) {
  balance -= amt;
}
AcctABC::Formatting AcctABC::SetFormat() const {
  Formatting f;
  f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
  f.pr = cout.precision(2);
  return f;
}
void AcctABC::Restore(AcctABC::Formatting &f) const {
  cout.setf(f.flag, ios_base::floatfield);
  cout.precision(f.pr);
}
// Brass Methods
void Brass1::Withdraw(double amt) {
  double balance = Balance();
  if(amt < 0)
    cout << "Withdrawal amount must be positive;"
         << "withdrawal cancelled.\n";
  else if (amt <= balance)
    balance -= amt;
  else
    cout << "Withdrawal amount of $" << amt
         << " exceeds your balance;"
         << "Withdrawal cancelled.\n";
}
void Brass1::ViewAcct() const {
  Formatting f = SetFormat();
  cout << "Brass client: " << FullName() << endl;
  cout << "Account number: " << AcctNum() << endl;
  cout << "Balance: $" << Balance() << endl;
  Restore(f);
}
// BrassPlus Methods
BrassPlus1::BrassPlus1(Brass1 &brass, double ml, double r) :
AcctABC(brass) {
  maxLoan = ml;
  rate = r;
  owesBank = 0.0;
}
BrassPlus1::BrassPlus1(const std::string &s, long an, double bal, double ml, double r) :
AcctABC(s,an,ml){
  maxLoan = ml;
  rate = r;
  owesBank = 0.0;
}
void BrassPlus1::ViewAcct() const {
  Formatting f = SetFormat();
  cout << "BrassPlus client: " << FullName() << endl;
  cout << "Account number: " << AcctNum() << endl;
  cout << "Balance: $" << Balance() << endl;
  cout << "Maximum loan: $" << maxLoan << endl;
  cout << "Owed to bank: $" << owesBank << endl;
  cout.precision(3);
  cout << "Loan Rate: " << 100 * rate << "%.\n";
  Restore(f);
}
void BrassPlus1::Withdraw(double amt) {
  Formatting f = SetFormat();
  double bal = Balance();
  if(bal >= amt){
    AcctABC::Withdraw(amt);
  }
  else if(amt <= bal + maxLoan - owesBank){
    double advance = maxLoan - owesBank;
    owesBank += advance * (1 + rate);
    cout << "Bank advance: $" << advance << endl;
    cout << "Finance charge: $" << advance * rate << endl;
    Deposit(advance);
    AcctABC::Withdraw(amt);
  }
  else{
    cout << "Credit limit exceeded. Transaction cancelled.\n";
  }
  Restore(f);
}