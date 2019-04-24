/**
 * Created by coast on 2019/4/17
 */
#include <iostream>

using namespace std;

// const变量、引用必须在定义的同时手动指定初始化值
// 局部非静态变量系统不会对其做自动初始化，需要手动赋值
// 全局变量、static系统会自动初始化
//

int global_a;

int main() {
  const int a = 1; // must initialize
  static int b;
  b=1;
  const int& ref_a = a; // must initialize
  int c;
  string s;

  cout << global_a << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << s << endl;

}