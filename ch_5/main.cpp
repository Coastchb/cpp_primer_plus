#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

#include "h2.h"

/*
void print_str(const string str){
  std::cout << str << std::endl;
}
 */
struct s{
    int a;
    float b;
    string str;
};
void rw_file();
void fun_arr();
void sub_fun_arr(int a[]);
inline void str_fun(char []);
void refer_fun(const int & a);
void change_str(const string & origin, const string & pad, string & ret);

int main() {
  print_func("ab");
  refer_fun(1);
}

void change_str(const string & origin, const string & pad, string & ret){
  ret = pad + origin + pad;
}
void refer_fun(const int & a)
{
  cout << "in function, a=" << a << endl;
}
inline void str_fun(char a[])
{
  cout << a << endl;
}
void fun_arr()
{
  int arr[3] = {2,3,1};
  cout << "address of array: " << arr << endl;
  cout << "size of array: " << sizeof(arr) << endl;
  sub_fun_arr(arr);

}
void sub_fun_arr(int a[])
{
  cout << "address of parameter: " << a << endl;
  //cout << "size of parameter: " << sizeof(a) << endl;

}
void rw_file()
{
  string filename = "tmp.txt";
  ofstream fout;
  fout.open(filename);

  char autoname[50];
  int year;
  double price;
  cout << "Enter the make and model of the auto:";
  cin.getline(autoname, 50);
  cout << "Enter the year:";
  cin >> year;
  cout << "Enter the price:";
  cin >> price;

  fout << fixed;
  fout.precision(2);
  fout.setf(ios_base::showpoint);
  fout << "auto name: " << autoname << endl;
  fout << "year: "  << year << endl;
  fout << "price:" << price << endl;

  fout.close();

  ifstream fin;
  fin.open(filename);
  char * c = new char[50];
  //fin >>
  //    fin.close();
  delete [] c;
}