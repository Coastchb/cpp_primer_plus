/**
 * Created by coast on 2018/8/29
 */

#include <iostream>

// 不要把main函数放在namespace里
// mark 1: std命名可以在自定义的namespace里调用

namespace tmp{
void fun(){
  // mark 1
  std::cout << "ok" << std::endl;
}
}


int main(){
  tmp::fun();
}
