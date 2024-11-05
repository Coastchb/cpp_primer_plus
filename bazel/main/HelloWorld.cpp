// Created by Coast Cao(Coastchb@sina.com) on 2018/8/26
#include "main/greet.h"
#include "lib/weather.h"
#include <string>
#include <iostream>
int main(){
    std::string name = "World";
    std::cout << print_greet(name);
    std::cout << print_weather();
}