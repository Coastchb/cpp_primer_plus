/**
 * Created by coast on 2019/4/17
 */
#include "0.h"

string global_str = "Hello, World";

void fun2() {
  cout << "global_str\t\t at:" << &global_str << "; content:" << global_str << endl;
  cout << "static_global_str\t at:" << &static_global_str << "; content:" << static_global_str << endl;

  cout << "const_global_str1\t at:" << &const_global_str1 << "; content:" << const_global_str1 << endl;
  cout << "const_global_str\t at:" << &const_global_str << "; content:" << const_global_str << endl;

  cout << "const_static_global_str\t at:" << &const_static_global_str << "; content:" << const_static_global_str << endl;
}