/**
 * Created by coast on 2019/4/23
 */
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  int a = 2;
  long b = 3;
  size_t c = a * b;

  cout << (b > a) << endl;
  cout << "sizeof(int):" << sizeof(int) << endl;
  cout << "sizeof(size_t): " << sizeof(size_t) << endl;
}