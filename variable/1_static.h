/**
 * Created by coast on 2019/4/18
 */

#include <iostream>
#include <string>
using namespace std;

// 对于类成员变量：
// （1）必须初始化静态变量或静态常量，而且在头文件中声明，在源文件中初始化；不能在头文件中定义；不能在构造函数内或者初始化列表中初始化。
// （2）如果是其他变量或常量，声明时可以不初始化；如果声明时初始化，声明和初始化必须在同一行（都在头文件中）。

class A {
private:
    int a_ = 2;
    int b_;
    //static string str_ = "wrong"; // illegal: non-const static data member must be initialized out of line
    static string str_;

    const static string str1_; //= "str1";

    const string str2_ = "str2";
    string str3_ ;
    static string str4_;

public:
    void print_str(){
      cout << str_ << endl;
      str_[0] = 'S';
      cout << str_ << endl;
      cout << str1_ << endl;
      cout << str2_ << endl;
      cout << str3_ << endl;
      cout << str4_ << endl;
      cout << a_ << endl;
      cout << b_ << endl;
    }
    void set_b(int bb, string str) {
      b_ = bb;
      str3_ = str;
    }
    A(){
      str4_ = "str4";
    }
};