//
// Created by coast on 19-3-21.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char * argv[]) {
    cout << argc << endl;
    for(int i=0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    argc++;
    string str = "-m";
    argv[argc-1] = (char*)str.c_str();
    argc++;
    string str2 = "prosody.model";
    argv[argc-1] = (char*)str2.c_str();

    cout << endl << argc << endl;
    for(int i=0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    return 0;
}