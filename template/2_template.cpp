#include <iostream>
#include <map>
#include <vector>
#include <type_traits>
#include <cstdint>
using namespace std;

template <class T>
void print(T& m) {
    for(auto v = m.begin(); v != m.end(); v++) {
        cout << v->first << ":" << v->second << endl;
    }
}

template <class T>
void insert(const string& itemid, const int f,
    T& buffer, bool replace) {
    if(!replace){
        buffer.insert(buffer.end(), make_pair(itemid, f));
    }
    else {
        if(is_same<T, vector<pair<string, int>>>::value) {
            cout << "vector type\n";
            //buffer[3] = make_pair(itemid, f);
            //typename T::iterator tmp_iter = buffer.begin() + 3;
            //tmp_iter->first = itemid;
            //tmp_iter->second = f;
        } else if (is_same<T, map<string, int>>::value) {
            cout << "map type\n";
            //buffer[]
        }
    }
        
}

int main() {
    vector<pair<string, int>> v = {make_pair("a", 1)};
    v.reserve(10);
    insert("aaa", 2, v, false);
    print(v);

    map<string, int> m;
    m["b"] = 11;
    insert("bbb", 22, m, false);
    print(m);



    *(v.begin() + 1) = make_pair("aaaa", 3);
    print(v);

    //*(m.begin() + 1) = make_pair("bbbb", 33);
    auto tmp_iter = next(m.begin(), 3);
    (*tmp_iter) = make_pair("bbbb", 33);
    print(m);

}