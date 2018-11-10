//
// Created by coast on 18-11-10.
//
#include "level_1.h"

int add_three(int a,int b,int c) {
    int d = add_two(a, b);
    return add_two(d, c);
}
