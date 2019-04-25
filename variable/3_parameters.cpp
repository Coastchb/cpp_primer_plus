//
// Created by coast on 19-4-25.
//

#include <iostream>
#include <string>
using namespace std;

//　形参如果是引用，那就不能将右值（比如字面值，函数返回值）传递给它。


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
    string a = "a";
    int b = 1;
    print(a, b);
    // print(a,1);
    // print("a",b);
    //print(a,fun1());


    print2(fun1());
    return 0;
}