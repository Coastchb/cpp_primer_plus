/**
 * Created by coast on 2018/10/30
 */
#include <iostream>
#include <string>
using namespace std;

// mark 1: "cin >> " will eat the begining whitespace and newline character, util read a string and ends by newline character

int main(){
  long l = 12345;
  cout.write((char*)&l, sizeof(long));
  cout << endl;

  // mark 1
  string str;
  cin >> str;
  cout << str << endl;
  return 0;
}