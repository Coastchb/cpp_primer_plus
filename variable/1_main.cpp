/**
 * Created by coast on 2019/4/18
 */

#include "1_static.h"

int main() {
  A a;
  cout << "before setting b_:\n";
  a.print_str();

  a.set_b(2, "str3");

  cout << "after setting b_:\n";
  a.print_str();
  return 0;
}