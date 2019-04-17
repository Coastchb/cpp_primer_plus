/**
 * Created by coast on 2019/4/17
 */
#include "0.h"

void fun1() {
  global_str[7] = 'w';
  static_global_str[7] = 'c';
  cout << "global_str at:" << &global_str << ";content:" << global_str << endl;
  cout << "static_global_str at:" << &static_global_str << ";content:" << static_global_str << endl;
}