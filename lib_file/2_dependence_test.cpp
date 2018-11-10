//
// Created by coast on 18-11-10.
//
#include "libdependence/add.h"

#include <iostream>
using namespace std;

int main() {
    cout << add_five(1, 2, 3, 4, 5) << endl;
}


// for static library with complex dependencies:
// (1) compile all the libraries, e.g get level_0.o, level_1.o and add.o in libdependence
// (2) packet the library: ar -crv lib/libadd.a level_0.o level_1.o add.o
// (3) ...

// for dynamic library with complex dependencies:
// (1) compile and packet the library: g++ -fPIC -shared -o so/libadd.so level_0.cpp level_1.cpp add.cpp
// (2) ...