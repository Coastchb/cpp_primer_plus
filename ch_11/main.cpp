//#include <iostream>
#include "mytime0.h"
#include "stonewt.h"

void about_mytime();
void about_weight();
void display(const Stonewt & st, int n);
int main() {
  about_weight();
  return 0;
}

void about_weight()
{
  Stonewt incognito = 275;
  Stonewt wolfe(285.37);
  Stonewt taft(21,8);

  std::cout << "The celebrity weighted: ";
  incognito.show_stn();
  std::cout << "The detective weighted: ";
  wolfe.show_stn();
  std::cout << "The president weighted: ";
  taft.show_lbs();

  incognito = 276.8;
  taft = 325;
  std::cout << "After dinner, the celebrity weighted: ";
  incognito.show_stn();
  std::cout << "After dinner, the president weighted: ";
  taft.show_lbs();
  display(taft, 2);
  std::cout << "The wrestler weighted even more.\n";
  display(422,2);
  std::cout << "No stone left unearned.\n";
  std::cout << int(incognito) << std::endl;
  std::cout << double(wolfe);
  //incognito.show_lbs();
}
void display(const Stonewt & st, int n)
{
  for ( int i = 0;i < n; ++i){
    std::cout << "Wow! ";
    st.show_stn();
  }
}
void about_mytime()
{
  using std::cout;
  using std::endl;
  Time planning;
  Time coding(2,40);
  Time fixing(5,55);
  Time total;

  cout << "planning time=";
  planning.Show();

  cout << "fixing time=";
  fixing.Show();

  //total = coding.Sum(fixing);
  total = coding + fixing;
  cout << "coding.Sum(fixing) = ";
  total.Show();

  Time t = total * 3.0; //3.0 * total;
  cout << "after *:";
  t.Show();

  //operator<<(cout, t);
  cout << t << fixing;

}