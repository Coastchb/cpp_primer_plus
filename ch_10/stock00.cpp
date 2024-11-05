//
// Created by 操海兵 on 16/05/2018.
//
#include <iostream>
#include "stock00.h"

Stock::Stock(){
  std::cout << "default constructor called\n";
  company_ = "no name";
  share_val_ = 0;
  shares_ = 0;
  set_tot();
}
Stock::Stock(const std::string &company, long n, double pr) {
  std::cout << "constructor called\n";
  company_ = company;
  if (n < 0)
  {
    std::cout << "Number of shares can't be negative; "
              << company_ << " shares set to 0.\n";
    shares_ = 0;
  }
  else
    shares_ = n;
  share_val_ = pr;
  set_tot();
}
Stock::~Stock() {
  std::cout << "Bye, " << company_ << "!\n";
}
void Stock::acquire(const std::string &co, long n, double pr) {
  company_ = co;
  if (n < 0)
  {
    std::cout << "Number of shares can't be negative; "
                 << company_ << " shares set to 0.\n";
    shares_ = 0;
  }
  else
    shares_ = n;
  share_val_ = pr;
  set_tot();
}

void Stock::buy(long num, double price) {
  if (num < 0)
  {
    std::cout << "Number of shares purchasted can't be negative. "
                 << "Transaction is aborted.\n";
  }
  else
  {
    shares_ += num;
    share_val_ = price;
    set_tot();

  }
}

void Stock::sell(long num, double price)
{
  using std::cout;
  if (num < 0)
  {
    cout << "Number of shares purchasted can't be negative. "
              << "Transaction is aborted.\n";
  }
  else if (num > shares_)
  {
    cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
  }
  else
  {
    shares_ -= num;
    share_val_ = price;
    set_tot();
  }
}

void Stock::update(double price)
{
  share_val_ = price;
  set_tot();
}
void Stock::show() const {
  std::cout << "Company: " << company_ << "\n"
            << "Shares: " << shares_ << "\n"
            << "Share price: $" << share_val_ << "\n"
            << "Total worth: $" << total_val_ << "\n";
  int i = 3;
  i++;
  std::cout << "changed local variable in show()\n";
}

const Stock & Stock::topval(const Stock & s) const {
  return this->total_val_ > s.total_val_ ? *this : s;
}