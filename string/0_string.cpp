/**
 * Created by coast on 2018/10/31
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string fun1(){
  string str = "This is just a simple string!\n";
  return str;
}

string fun2(){
  string str = "This is string one!\n";
  string str1 = str;
  return str1;
}

string fun3(){
  string str = fun1();
  return str;
}

void fun4(vector<string>* v){
  string str = "This is string two!\n";
  v->at(0) = str;
}
int main(int argc, char* argv[]){
  cout << fun1();

  cout << fun2();
  cout << fun3();

  vector<string> vv(1);
  fun4(&vv);
  cout << vv[0];
  return 0;
}