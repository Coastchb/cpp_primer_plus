/**
 * Created by coast on 2019/4/22
 */
#include "1_1_template_class.h"

// 类模板成员函数实现方式一：跟头文件分离
// Caution: comiple it with: g++ -o g++ -o 1_1_main 1_1_main.cpp
// if compile with: g++ -o 1_1_main 1_1_main.cpp 1_1_template_class.cpp, redefinition error will occur
// reference:
//   [1]https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

int main(int argc, char* argv[]) {
  Stack<int, 1> stack_int;

  stack_int.push(1);
  stack_int.push(2);
  cout << "stack size:" << stack_int.get_size() << endl;
  int ret;
  stack_int.pop(ret);
  cout << "poped:" << ret << endl;
  cout << "is empty?" << stack_int.is_empty() << endl;

  return 0;
}