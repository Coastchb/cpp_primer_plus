//
// Created by coastcao(操海兵) on 2019-09-17.
//

#include <iostream>
using namespace std;
class A {
    int i = 0;
public:
    virtual void fun1() {
        cout << "fun1 in A\n";
    }
};

class B : public A {
    int j = 1;
public:
    void fun1() {
        cout << "fun1 in B\n";
    }

    void fun2() {
        cout << "fun2 in B\n";
    }

};

class C : public A {
    int k = 2;
};

int main() {
    A* b = new B();

    if (B * p = dynamic_cast<B *>(b)) {
        cout << "b is an instance of B\n";
        p->fun1();
        p->fun2();
        b->fun1();
        //b->fun2();
    } else {
        cout << "b is not an instance of B\n";
    }

    if (A * p = dynamic_cast<A *>(b)) {
        cout << "b is an instance of A\n";
        p->fun1();
        //p->fun2();
    } else {
        cout << "b is not an instance of A\n";
    }

    C* c = new C();
    if (B * p = dynamic_cast<B *>(c)) {
        cout << "c is an instance of B\n";
        p->fun1();
        //p->fun2();
    } else {
        cout << "c is not an instance of B\n";
    }
}