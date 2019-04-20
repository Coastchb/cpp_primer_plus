/**
 * Created by coast on 2019/4/20
 */
#include <iostream>
using namespace std;

template <typename Real>
inline Real const& get_max(Real const& a, Real const& b) {
  return a >= b ? a : b;
}

template <typename T1, typename T2>
void print(T1 const& t1, T2 const& t2) {
  cout << "in print1:" << t1 << "\t" << t2 << endl;
}

template <typename T>
void print(T const& t1, T const& t2) {
  cout << "in print2:" << t1 << "\t" << t2 << endl;
}

int main(int argc, char* argv[]) {
  cout << get_max(1, 2) << endl;

  cout << get_max(1.2,0.3) << endl;

  cout << get_max('a', 'c') << endl;

  print(1,2); // 优先调用两个泛型类型相同的函数
  print(1,"2.0");
  return 0;
}