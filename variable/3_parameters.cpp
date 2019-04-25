//
// Created by coast on 19-4-25.
//

#include <iostream>
#include <string>
using namespace std;

// 引用不能指向右值（比如字面值，函数返回值）！
//　也因此，形参如果是引用，那就不能将右值传递给它。


void print(string& s, int& a) {
    cout << s << "\t" << a << endl;
}

void print2(int a) {
    cout << a << endl;
}

int fun1(){
    int a = 1;
    return a*a;
}

int main () {
    string str = "a";
    int a = 1;

    //int& b = 1;
    //int& b = fun1();
    //string& str1 = "a";


    print(str, a);
    // print(str,1);
    // print("a",a);
    //print(str,fun1());


    print2(fun1());
    return 0;
}