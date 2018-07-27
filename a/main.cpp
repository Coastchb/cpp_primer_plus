#include <iostream>
#include <string>
#include "TableTennisPlayer.h"
#include "RatedPlayer.h"
#include "Brass.h"
#include "acctabc.h"
#include "dma.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * (1)通常，可以使用基类对象的地方，可以用派生类对象来替代。比如，赋值，初始化，函数实参等。
 * (2)mark 1: 总之，通常对象被声明为什么类型，那么该对象就访问该类型里的函数（的实现）；除非是基类引用或者指针实际指向
 *            派生类的对象，这时候被声明的引用或者指针访问的是派生类中虚函数（的实现）。
 * (3)mark 2: 定义派生类构造函数时，可以不在初始化列表中显式调用基类构造函数，这时候就会调用基类默认构造函数。通常调用
 *            基类构造函数是为了初始化在基类中定义的（私有）成员变量，所以这种情况适用于基类中没有定义任何成员变量或者
 *            基类默认构造函数中对其成员变量做了初始化。
 *            另外，派生类构造函数中做初始化时，如果要调用基类构造函数（以初始化基类中的成员变量），那只能在初始化列表中，
 *            而不能在构造函数体内。
 * (4)mark 3: 在派生类的构造函数中，如果需要调用基类构造函数来初始化基类中定义的私有成员变量，那么初始化列表（包含对基类构造函数
 *            的调用）只能出现在函数定义中（可以在头文件中，或者源文件中），而不是函数原型中（只有函数原型，没有定义）。
 * (5)mark 4: 派生类函数中调用基类中的重载运算符函数。可以理解为this->baseDMA::operator=(rs); 其实就是在派生类中调用基类函数，mark 6也是如此。
 * (6)mark 5: 派生类函数中调用基类的友元函数。然编译器根据参数类型来选择合适的函数。
 *
 */

void fun_player();
void basic_brass();
void my_implement();
void high_brass();
void super_brass();
void dma();

int main() {
  dma();
}

void dma(){
  baseDMA shirt("Portabelly", 8);
  lacksDMA balloon("red", "Blimpo", 4);
  hasDMA map("Mercator", "Buffalo Keys", 5);

  cout << "Display baseDMA object:\n";
  cout << shirt << endl;
  cout << "Display lacksDMA object:\n";
  cout << balloon << endl;
  cout << "Display hasDMA object:\n";
  cout << map << endl;
  lacksDMA balloon2(balloon);
  cout << "Result of lacksDMA copied:\n";
  cout << balloon2 << endl;
  hasDMA map2;
  map2 = map;
  cout << "Result of hasDMA assignment:\n";
  cout << map2 << endl;

}
void super_brass(){
  const int CLIENTS = 4;
  AcctABC * p_clients[CLIENTS];
  string temp;
  long tempnum;
  double tempbal;
  char kind;

  for (int i = 0; i < CLIENTS; ++i){
    cout << "Enter client's' name:";
    getline(cin,temp);
    cout << "Enter client's account num:";
    cin >> tempnum;
    cout << "Enter opening balance:";
    cin >> tempbal;
    cout << "Enter 1 for Brass Account;"
         << "2 for BrassPlus Account.\n";

    while ( cin >> kind && kind != '1' && kind != '2')
      cout << "Enter either 1 or 2:";

    if (kind == '1')
      p_clients[i] = new Brass1(temp, tempnum, tempbal);
    else{
      double tmax, trate;
      cout << "Enter the overdraft limit: $";
      cin >> tmax;
      cout << "Enter the interest rate "
           << "as a decimial fraction: ";
      cin >> trate;
      p_clients[i] = new BrassPlus1(temp, tempnum, tempbal, tmax, trate);
    }
    while (cin.get() != '\n')
      continue;
  }

  cout << endl;
  for (int i = 0; i < CLIENTS; ++i){
    p_clients[i]->ViewAcct();
    cout << endl;
  }

  cout << "Done.\n";
}

void high_brass(){
    const int CLIENTS = 4;
    Brass * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; ++i){
      cout << "Enter client's' name:";
      getline(cin,temp);
      cout << "Enter client's account num:";
      cin >> tempnum;
      cout << "Enter opening balance:";
      cin >> tempbal;
      cout << "Enter 1 for Brass Account;"
              << "2 for BrassPlus Account.\n";

      while ( cin >> kind && kind != '1' && kind != '2')
        cout << "Enter either 1 or 2:";

      if (kind == '1')
        p_clients[i] = new Brass(temp, tempnum, tempbal);
      else{
        double tmax, trate;
        cout << "Enter the overdraft limit: $";
        cin >> tmax;
        cout << "Enter the interest rate "
                << "as a decimial fraction: ";
        cin >> trate;
        p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);

        }
      while (cin.get() != '\n')
        continue;
    }

     cout << endl;
    for (int i = 0; i < CLIENTS; ++i){
      p_clients[i]->ViewAcct();
      cout << endl;
    }

    for (int i = 0; i< CLIENTS; ++i){
      p_clients[i]->new_fun();
      delete p_clients[i];
    }
    cout << "Done.\n";
}

// mark 1
void my_implement(){
  BrassPlus bp;
  Brass b1 = bp;
  Brass & b2 = bp;
  Brass * b3 = &bp;

  // virtual function
  b1.ViewAcct();  // call Brass::ViewAcct()
  b2.ViewAcct();  // call BrassPlus::ViewAcct()
  b3->ViewAcct(); // call BrassPlus::ViewAcct()

  /* 无法访问派生类特有成员
  b1.ResetOwes();
  b2.ResetOwes();
  b3.ResetOwes();

  b1.maxLoad;
  b2.maxLoad;
  b3.maxLoad;
   */

  // non-virtual overloaded function
  b1.new_fun();   // call Brass:new_fun()
  b2.new_fun();   // call Brass:new_fun()
  b3->new_fun();  // call Brass:new_fun()

  // non-virtual inherited function
  b1.Deposit(0.1);  // call Brass:Deposit()
  b2.Deposit(0.2);  // call Brass:Deposit()
  b3->Deposit(0.3); // call Brass:Deposit()
}

void basic_brass(){
  Brass Piggy("Porcelog Pigg", 381299, 4000.00);
  BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
  Piggy.ViewAcct();
  cout << endl;
  Hoggy.ViewAcct();
  cout << endl;
  cout << "Depositing $1000 into the Hogg Account:\n";
  Hoggy.Deposit(1000);
  cout << "New balance: $" << Hoggy.Balance() << endl;
  cout << "Withdrawing $4200 from the Pigg Account:\n";
  Piggy.Withdraw(4200);
  cout << "Pigg account balance: $" << Piggy.Balance() << endl;
  cout << "Withdrawing $4200 from the Hoggy Account:\n";
  Hoggy.Withdraw(4200);
  Hoggy.ViewAcct();
}

void fun_player(){
  TableTennisPlayer player1("Chuck", "Blizzard", true);
  RatedPlayer rplayer1(1140, "Mallory", "Duck", false);
  player1.Name();
  if(player1.HasTable())
    cout << ": has a table.\n";
  else
    cout << ": doesnot have a table.\n";

  rplayer1.Name();
  if(rplayer1.HasTable())
    cout << ": has a table.\n";
  else
    cout << ": dosenot have a table.\n";

  rplayer1.Name();
  cout << ", rating:" << rplayer1.Rating() << endl;

  RatedPlayer rplayer2(1212, rplayer1);
  rplayer2.Name();
  cout << ", rating:" << rplayer2.Rating() << endl;
}
