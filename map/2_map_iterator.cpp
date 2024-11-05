#include <iostream>
#include <map>
using namespace std;

void print_map(map<string, int>& m) {
    for(auto x = m.begin(); x != m.end(); x++) {
        cout << x->first << ":" << x->second << "\n";
    }

}

int main() {
    map<string, int> mymap;
    mymap["a"] = 1;
    mymap["b"] = 2;
    mymap["c"] = 3;

    print_map(mymap);

    mymap.erase("c");
    print_map(mymap);

}