/**
 * Created by coast on 2019/4/15
 */
#include <string>
#include <iostream>
using namespace std;

int main() {
  char c_arr[] = "ab", c_arr1[4];
  //char * c_ptr1 = "cd", c_ptr2;
  char * c_ptr1 = new char('c');
  char * c_ptr2;
  const char* c_ptr3 = "ef";
  const char* c_ptr4;
  string str1 = "gh", str2;

  cout << "char* and char[]:\n";
  c_ptr2 = c_arr;
  cout << c_ptr2 << endl;
  //c_arr1 = c_ptr1;      // illegal
  cout << c_arr1 << endl;

  cout << "const char* and char[]:\n";
  c_ptr4 = c_arr;
  cout << c_ptr4 << endl;
  //c_arr1 = c_ptr3;
  cout << c_arr1 << endl;

  cout << "string and char*, char[]:\n";
  str2 = c_arr;
  cout << str2 << endl;
  str2 = c_ptr1;
  cout << str2 << endl;
  str2 = c_ptr3;
  cout << str2 << endl;

  str2 = string(c_ptr3, 1);
  cout << str2 << endl;
  str2 = string(c_arr, 1);
  cout << str2 << endl;
}