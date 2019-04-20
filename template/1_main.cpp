/**
 * Created by coast on 2019/4/20
 */
#include "1_template_class.h"

int main(int argc, char* argv[]) {
  Stack<int> stack_int;

  stack_int.push(1);
  stack_int.push(2);
  cout << stack_int.pop() << endl;
  cout << "is empty?" << stack_int.is_empty() << endl;

  return 0;
}