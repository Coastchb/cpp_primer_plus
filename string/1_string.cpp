/**
 * Created by coast on 2018/11/1
 */
#include <string>
#include <iostream>
using namespace std;

// if a character pointer only stores the address, then how do cout know a character pointer
// point to a single character (and then output a character) or the first character of a string (and then output a string)
// ref: https://en.cppreference.com/w/cpp/string/basic_string/c_str

int main(int argc, char* argv[]) {
  // deprecated: conversion from string literal to 'char *' is deprecated
  char * cp1 = "This is string one.";
  cout << cp1 << endl;

  // legal
  string str = "This is string two.";
  const char * cp2 = str.c_str();
  cout << cp2 << endl;

  char c = 'c';
  cout << c << endl;
  cout << &c << endl;
  cout << (void*)&c << endl;

  char * cp3 = &c;
  cout << cp3 << endl;
  cout << *cp3 << endl;
  cout << (void*)cp3 << endl;
}