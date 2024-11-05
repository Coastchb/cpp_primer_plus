//
// Created by coastcao(操海兵) on 2019-08-23.
//

#include <boost/lexical_cast.hpp>
#include <iostream>
using namespace std;
int main() {
    // string to int
    cout << boost::lexical_cast<int>("123") << endl;

    return 0;
}