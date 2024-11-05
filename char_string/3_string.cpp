/**
 * Created by coast on 2018/11/2
 */
#include <string>
#include <iostream>
using namespace std;

// mark 1: cannot implement "+" to two string literal

int main(int argc, char* argv[]) {
  // mark 1
  // cout << ("a" + "b") <<endl; // Error

  // mark 1
  string str = "a"; // + "b"

  str = str + "b"; // the least efficient
  str = "b" + str;
  str += "c";  // the second most efficient
  str.append("d"); // the most efficient

  cout << str << endl;
  return 0;
}