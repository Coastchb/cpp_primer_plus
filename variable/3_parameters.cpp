//
// Created by coast on 19-4-25.
//

#include <iostream>
#include <string>
using namespace std;

// 临时变量（比如字面值，函数返回值）只能用来初始化常引用，因为这些临时变量是常量。


void print(const string& s, const int& a) {
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

    const int& b = 1;           // 必须为const，否则： non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    const int& b2 = fun1();
    const string& str1 = "a";


    print(str, a);
    print(str,1);
    print("a",a);
    print(str,fun1());


    print2(fun1());
    return 0;
}