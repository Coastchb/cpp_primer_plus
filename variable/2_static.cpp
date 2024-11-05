/**
 * Created by coast on 2019/4/22
 */
#include <iostream>
using namespace std;

void fun1() {
  static int a = 3;
  a++;
  cout << a << endl;
}

void fun2() {
  static int a;
  a = 3;
  a++;
  cout << a << endl;
}

void fun3() {
  static int a;
  a++;
  cout << a << endl;
}

int main() {
  for(int i = 0; i < 10; i++){
    fun1();
    fun2();
    fun3();
    cout << endl;
  }
  return 0;
}