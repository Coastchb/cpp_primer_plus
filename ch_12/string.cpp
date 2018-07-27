//
// Created by Apple on 2018/5/18.
//

#include "string.h"

using std::cout;
using std::endl;
using std::cin;

int string::num_strings = 0;

string::string() {
    std::cout << "default constructor called\n";
    str = new char[1];
    str[0] = '\0';
    len = 0;
    num_strings++;
}
string::string(const char *s) {
    std::cout << "char* constructor called\n";
    str = new char[std::strlen(s) + 1 ];
    std::strcpy(str, s);
    len = int (std::strlen(str));
    num_strings++;
    /*
    for(int i = 0; i < len; ++i)
        std::cout << "char " << str[i] << " at " << &str[i] << std::endl;
     */
}
string::string(const string &s) {
    std::cout << "copy constructor called\n";
    cout << "copy from " << s.str << endl;
    len = s.len;
    str = new char[len+1];
    std::strcpy(str,s.str);
    num_strings++;
}
string::~string(){
    delete [] str;
    num_strings--;
    cout << num_strings << " objects left\n";
}
const char & string::operator[](int i) const {
    std::cout << "2: str[" << i << "]:" << str[i] << " at " << static_cast<void *>(&str[i]) << endl;
    // mark 4
    num_strings++;
    num_strings--;
    return str[i];
}


char & string::operator[](int i) {
    std::cout << "1: str[" << i << "]:" << str[i] <<  " at " << static_cast<void *>(&(str[i])) << std::endl;
    return str[i];
}

int string::length() const {
    return len;
}

int string::HowMany() {
    return num_strings;
}

// mark 7
string string::operator=(const char * s){
    // mark 5
    cout << "operator=(char*) called\n";
    delete [] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    return *this;
}
// mark 7
string& string::operator=(const string& s){
    cout << "operator=(string) called\n";
    if(&s == this){
        cout << "copy from self.\n";
        return *this;
    }

    delete [] str;
    str = new char [s.len + 1];
    strcpy(str, s.str);
    return *this;
}

bool operator<(const string &s1, const string &s2){
    return s1.str < s2.str ;
}
bool operator>(const string &s1, const string &s2){
    return s1.str > s2.str;
}
bool operator==(const string &s1, const string &s2){
    return s1.str == s2.str;
}
std::istream & operator>>(std::istream & is, string& s){
    char temp[string::CINLIM];
    is.get(temp, string::CINLIM);
    if(is)
        s = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}
std::ostream & operator<<(std::ostream & os, const string& s){
    os << s.str;
    return os;
}

