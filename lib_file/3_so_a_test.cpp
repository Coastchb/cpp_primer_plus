//
// Created by coast on 18-11-10.
//
#include "lib_so_a/add.h"

#include <iostream>
using namespace std;

int main() {
    cout << add_five(1, 2, 3, 4, 5) << endl;
}


// .so library depend on .a library:
// (1) compile all the depended libraries with -shared -fPIC :
//    gcc -c -o level_0.o level_0.cpp -shared -fPIC
//    gcc -c -o level_1.o level_1.cpp -shared -fPIC
// (2) package the depended static library: ar -crv sublib/libsub.a level_0.o level_1.o
// (3) package the dynamic library: g++ -shared -fPIC -o so/libadd.so add.cpp -L libsub -l sub
// (4) ...