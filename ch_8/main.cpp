#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void fun(int a);
void fun(int a,int b=2);

template <typename T>
void Swap(T & a, T & b);

template <typename T>
void Swap(T * a, T * b, int n);
void print_str(string s);
int main() {
  /*
  int i = 1, j = 2;
  Swap(i,j);
  cout << "i=" << i << ",j=" << j << endl;
  int ip[] = {1,2,3,4,5,6};
  int jp[] = {11,22,33,44,55,66};
  Swap(ip,jp,6);
  for(int i = 0; i < 6; i++){
    cout << ip[i] << "\t" << jp[i] << endl;
  }
  */
  const char c1[] = "ab";
  char cp[4];
  strcpy(cp,c1);
  strcat(cp,"AB");
  cout << cp << endl;
}

void print_str(string s){
  cout << s << endl;
}
template <typename T>
void Swap(T &a, T& b){
  T temp;
  temp = a;
  a = b;
  b = temp;
}

template <typename T>
void Swap(T *a, T* b, int n){
  T temp;
  for (int i = 0;i < n; i++){
    temp = a[i];
    a[i] = b[i];
    b[i] = temp;
  }
}
void fun(int a){
  cout << "in fun1, a = " << a << endl;
}
void fun(int a, int b){
  cout << "in fun2, a = " << a << ", b= " << b << endl;
}