/**
 * Created by coast on 2019/4/17
 */

 // 不能在头文件中定义非常量非静态全局变量；只能声明，然后在源文件中定义；作用域为整个项目；
 // 静态全局变量的作用域为单个源文件；
 // 不能在头文件中定义函数（不包括类成员函数）

 // reference:
 // [1] https://blog.csdn.net/ak47000gb/article/details/80304360
 // [2] https://blog.csdn.net/nyist327/article/details/50904893?utm_source=blogxgwz4
 // [3] https://www.cnblogs.com/graphics/articles/1765895.html
 // [4] https://www.cnblogs.com/dj0325/p/8491748.html

#ifndef _0_H
#define _0_H

#include <string>
#include <iostream>
using namespace std;

extern string global_str;           // field: project
//string global_str1 = "Hello";     // illegal: cannot define global variable (neither const nor static) in header

//extern static string wrong_str1;  // illegal: extern and static cannot be used simultaneously
static string static_global_str = "Hello, Coast"; // field: file

extern const string const_global_str1;            // field: project
const string const_global_str = "Hello";          // field: file

static const string const_static_global_str = "Hello,Kitty";  // field: file

void fun1();
void fun2();


// illegal
/*
void fun3(){
  cout << "global_str at:" << &global_str << ";content:" << global_str << endl;
  cout << "static_global_str at:" << &static_global_str << ";content:" << static_global_str << endl;
  //cout << "const_global_str at:" << &const_global_str << ";content:" << const_global_str << endl;
}
*/

#endif