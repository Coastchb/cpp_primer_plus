//
// Created by coastcao(操海兵) on 2019-08-26.
//

#include "boost/regex.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

int main() {

    // exp 1
    regex pattern("\\w+-([a-zA-Z0]+)+.*>([0-9]+)<([0-9])/P.*");
    ifstream fis("test_data/full_lab.txt");
    cmatch ret;
    const int NUM = 1024;
    char line[NUM];
    while(fis.getline(line, NUM)) {
        string str = string(line);
        if (regex_match(str.c_str(), ret, pattern)) {
            cout << ret[1].str() << endl;
            cout << ret[2].str() << endl;
        }
    }

    // exp 2
    string str = "XX-sil+C0y/A:XX_XX@XX$1#4/B:XX_XX@XX$XX#XX&XX/E:XX/V:XX_XX@XX$XX/M:0_0@90$XX#XX&XX>20<0/P:XX_0@3$XX#XX&XX>XX<XX/K:XX_XX@XX$XX#XX&XX>XX<XX^XX/G:XX_XX@XX$XX#XX&XX/L:XX_XX@XX$XX#XX&XX>XX/N:XX_XX@XX$XX#XX&XX>XX[3]";
    pattern= regex(".*/M.*@([X0-9]+)\\$.*/P.*");
    if (regex_match(str.c_str(), ret, pattern)) {
        cout << ret[1].str() << endl;
    } else {
        cout << "mismatched!\n";
    }

}
