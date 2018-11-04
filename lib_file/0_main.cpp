/**
 * Created by coast on 2018/11/4
 */
#include "libadd/add.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[]) {
  int a = 1, b = 2;
  cout << a << "+" << b << "=" << add_fun(a, b) << endl;

  return 0;
}
