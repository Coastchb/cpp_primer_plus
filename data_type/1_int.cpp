//
// Created by coast on 19-4-25.
//
#include <iostream>
#include <climits>
using namespace std;

// int值算术运算的结果是int值，所以一定要小心运算结果是否会溢出！
// int值的运算一定要保证在int所能表示的数值范围内！比如下面用 a > INT_MAX / b; 而不要用 a * 10 > INT_MAX; 因为a * 10　可能就溢出了。
//　形参如果是引用，那就不能将字面值传递给它。比如compute中的b,c定义为int& 就会出错。
//INT_MIN=-2147483648
//INT_MAX=2147483647

bool compute(int& a, int b, int c) {
    if( a > INT_MAX / b || ((a == INT_MAX / b) && c > (INT_MAX - a * b))) {
        cout << "overflow!\n";
        return false;
    }
    cout<< a * b + c << endl;
    return true;
}


int main() {
    cout << "INT_MIN=" << INT_MIN << endl;
    cout << "INT_MAX=" << INT_MAX << endl;

    int a = 214748364;
    cout << (a * 10 + 7) << endl;
    cout << (a * 10 + 8) << endl;   // overflow !
    cout << (a * 10 + 9) << endl;   // overflow !

    //　正确的运算方式！
    compute(a, 10, 7);
    compute(a, 10, 9);

    return 0;
}