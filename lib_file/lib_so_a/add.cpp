//
// Created by coast on 18-11-10.
//
#include "add.h"

int add_five(int a,int b,int c,int d,int e) {
    return add_two(add_two(a, b), add_three(c, d, e));
}

