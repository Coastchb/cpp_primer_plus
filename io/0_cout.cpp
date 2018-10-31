/**
 * Created by coast on 2018/10/30
 */
#include <iostream>
using namespace std;

int main(){
  long l = 12345;
  cout.write((char*)&l, sizeof(long));
  cout << endl;

  return 0;
}