/**
 * Created by coast on 2018/11/1
 */
#include <string>
#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//#include <cstdlib>
using namespace std;

// if a character pointer only stores the address, then how do cout know a character pointer
// point to a single character (and then output a character) or the first character of a string (and then output a string)
// ref: https://en.cppreference.com/w/cpp/string/basic_string/c_str

int main(int argc, char* argv[]) {
  // deprecated: conversion from string literal to 'char *' is deprecated
  // but can assign a string literal to a const char pointer
  const char * cp1 = "This is string one.";
  cout << "condition 1:" << endl;
  cout << cp1 << endl;
  // cp1[1] = 'H'; // read-only variable is not assignable
  // cout << cp1 << endl;

  // legal
  string str = "This is string two.";
  const char * cp2 = str.c_str();
  cout << "condition 2:" << endl;
  cout << cp2 << endl;
  cout << *cp2 << endl;
  cout << cp2[0] << endl;

  char c = 'c';
  cout << "condition 3:" << endl;
  cout << c << endl;
  cout << &c << endl;
  cout << (void*)&c << endl;

  const char * cp3 = &c;
  cout << "condition 4:" << endl;
  cout << cp3 << endl;
  cout << *cp3 << endl;
  cout << (void*)cp3 << endl;

  const char* cp4;
  cp4 = cp3;
  cout << cp4 << endl;

  cout << "condition 5:" << endl;
  cout << static_cast<char>(68) << endl;
  cout << (68 == 'D') << endl;

}