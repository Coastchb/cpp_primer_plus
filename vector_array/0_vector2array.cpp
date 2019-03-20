/**
 * Created by coast on 2019/3/2
 */

#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector< vector<int> > v_int;

  int element = 0;
  for(int i = 0; i < 2; i++) {
    vector<int> tmp;
    for(int j = 0; j < 5; j++) {
      tmp.push_back(element++);
    }
    v_int.push_back(tmp);

  }
  //cout << v_int.size() << endl;

  int array[2][5];

  for (int i = 0; i < 2; i++) {
    //memcpy(array[i], &(v_int[i].front()), 5);
    int tmp[5] = {1,2,3,4,5};
    copy_n(v_int[i].begin(), 5, array[i]);
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      cout << array[i][j] << std::endl;
    }
  }

  cout << sizeof(array)/sizeof(int) << endl;

  int a[5] = {10,20,30,90,100};
  int b[10] = {1,2,3,4,5,6,7,8,9,10};
  cout << "sizeof(b): " << sizeof(b) << endl;
  cout << "sizeof(*b):" << sizeof(*b) << endl;


  memcpy(b, a, 3* sizeof(*b));
  memset(&b[3], 0, 5*sizeof(*b));
  memcpy(&b[8], &a[3], 2*sizeof(*b));

  for (int i = 0; i < 10; i++) {
    cout << b[i] << std::endl;
  }

  int m[10] = {10,10,10,10,10,10,10,10,10,10};
  int v[10] = {2,2,2,2,2,2,2,2,2,2};



  return 0;

}
