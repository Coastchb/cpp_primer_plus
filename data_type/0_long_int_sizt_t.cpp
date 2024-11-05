/**
 * Created by coast on 2019/4/23
 */
#include <iostream>
using namespace std;

// sizt_t 一定不要出现负数情况！否则结果会意想不到。　可以通过两个sizt_t的变量进行大小比较来规避负数情况

int main(int argc, char* argv[]) {
  int a = 2;
  long b = 3;
  size_t c = a * b;

  cout << (b > a) << endl;
  cout << "sizeof(int):" << sizeof(int) << endl;
  cout << "sizeof(long):" << sizeof(long) << endl;
  cout << "sizeof(size_t): " << sizeof(size_t) << endl;

  size_t t = 3;
  cout << (2 > t) << endl;

  long k = 2;
  cout << (k > t) << endl;  // false
  k = 0;
  cout << (k > t) << endl;  // false
  k = -1;
  cout << (k > t) << endl;  // true !!!
  cout << long(t) << endl;
  cout << (k > long(t)) << endl;  // false

  size_t t1 = 1, t2 = 2;
  cout << (t1 - t2) << "\t(t1-t2)<0:" << ((t1-t2) < 0 ) << endl; // false !!!
  cout << "t1<t2:" << (t1 < t2) << endl;
}