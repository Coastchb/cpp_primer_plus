//
// Created by coast on 18-11-4.
//
#include "libmath/StaticMath.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    double a = 10, b = 2;

    cout << "a + b" << StaticMath::add(a, b) << endl;
    cout << "a - b" << StaticMath::sub(a, b) << endl;
    cout << "a * b" << StaticMath::mul(a, b) << endl;
    cout << "a / b" << StaticMath::div(a, b) << endl;

    StaticMath stm;
    stm.print();

    cout << endl;
    return 0;
}

// for static library:
// (1) compile library: g++ -c StaticMath.cpp
// (2) packet the library: ar -crv libstaticmath.a StaticMath.o  (optional: mv libstaticmath.a to libmath/lib)
// (3) compile test file: g++ -o 1_staticmath_test 1_staticmath_test.cpp -L libmath/lib -l staticmath
// (4) run: ./1_staticmath_test

// for dynamic library:
// (1) compile and packet the library: g++ -fPIC -shared -o so/libdynamicmath.so StaticMath.cpp
// (1) compile test file: g++ -o 1_dynamicmath_test_dynmic 1_staticmath_test.cpp -L libmath/so -l staticmath
// (2) make sure libdynamicmath.so can be found: e.g link libdynamicmath.so to /usr/lib or add libmath/so to $LD_LIBRARY_PATH
// (3) run: ./1_dynamicmath_test