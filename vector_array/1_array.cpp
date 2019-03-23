/**
 * Created by coast on 2019/3/22
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N = 10;
  string* arr = new string[1];
  for (int i = 0; i < N; i++) {
    *(arr+i) = to_string(i);
  }

  for (int i = 0; i < N; i++)
    cout << *(arr+i) << endl;

  return 0;
}