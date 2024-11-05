/**
 * Created by coast on 2019/2/25
 */
#include <string>
#include <iostream>
using namespace std;

// use string(char*) to pass a char* to string, instead of assignment(=)
// what about strcpy?

int main() {
  char* c_pt = new char[3];
  c_pt[0] = 'a';
  c_pt[1] = 'b';
  c_pt[2] = 'c';
  cout << c_pt << endl;
  cout << c_pt[3] << endl;
  cout << c_pt[4] << endl;

  string str;
  str = c_pt;   // don't use it!!! because the end of str may not be the expected '\0'
  cout << str.size() << endl;
  cout << str << endl;

  str = string(c_pt, 3);
  cout << str.size() << endl;
  cout << str  << endl;
  return 0;
}