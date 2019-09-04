//
// Created by coast on 19-3-28.
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    char * cp = "012";
    cout << cp << endl;

    string short_str = cp; //"32354";
    stringstream ss(short_str);
    short str_value;
    ss >> str_value;
    cout << "value is: " << str_value << endl;

    stringstream s1("345");
    int int_value;
    s1 >> int_value;
    cout << "int value is:" << int_value << endl;
    //cout << SHRT_MAX << endl;
    return 0;
}