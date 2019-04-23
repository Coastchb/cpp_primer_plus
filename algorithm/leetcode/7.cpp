/**
 * Created by coast on 2019/4/20
 */
#include <iostream>

using namespace std;

class Solution {
  public:
  int reverse(int x) {
    int ret = 0;
    while(x != 0) {
      int tmp = x % 10;
      x = x / 10;
      if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && tmp > 7)) return 0;
      if(ret < INT_MIN / 10 || (ret == INT_MIN / 10 && tmp < -8)) return 0;
      ret = ret*10 + tmp;
    }
    return ret;

  }
};

int main(int argc, char* argv[]) {
  Solution s;
  cout << s.reverse(123) << endl;
  cout << s.reverse(5342364691) << endl;

  //cout << pow(2,31) << endl;
  //cout << pow(-2,31) << endl;
  cout << INT_MAX << endl;
  cout << INT_MIN << endl;
  cout << (-1 % 10) << endl;
  cout << (-11 % 10) << endl;
  cout << (-11 / 10) << endl;
  return 0;

}