/**
 * Created by coast on 2019/2/25
 */
#include <string>
#include <iostream>
using namespace std;

int main() {
  char* c_pt = new char[3];
  c_pt[0] = 'a';
  c_pt[1] = 'b';
  c_pt[2] = 'c';
  cout << c_pt << endl;

  string str;
  str = c_pt;
  cout << str << endl;
  return 0;
}