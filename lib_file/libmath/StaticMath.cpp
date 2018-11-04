//
// Created by coast on 18-11-4.
//
#include "StaticMath.h"
#include <iostream>
using namespace std;

double StaticMath::add(double a, double b) {
    return a + b;
}

double StaticMath::sub(double a, double b) {
    return a - b;
}

double StaticMath::mul(double a, double b) {
    return a*b;
}

double StaticMath::div(double a, double b) {
    return a/b;
}

void StaticMath::print() {
    cout << "Static Math Library";
}