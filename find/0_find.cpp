//
// Created by coast on 19-3-25.
//

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[] = {"ab", "cd", "efg"};
    string* begin_p = begin(arr);
    string* end_p = end(arr);
    cout << begin_p << "\t" << end_p << "\t" << (end_p - begin_p) << endl;

    string* p = find(begin_p, end_p, "ab");
    if(p != end_p)
        cout << "found ab at " << p << endl;

    p = find(begin_p, end_p, "efg");
    if(p != end_p)
        cout << "found efg at " << p << endl;

    p = find(begin_p, end_p, "ad");
    if(p != end_p)
        cout << "found ad at " << p << endl;

}