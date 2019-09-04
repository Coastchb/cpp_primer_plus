//
// Created by coast on 19-3-24.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// capacity, size and insert()

void print_vector(vector<int>& vec) {
    cout << "vec[0]:" << vec[0] << endl;
    cout << "vec capacity:" << vec.capacity() << endl;
    cout << "vec size:" << vec.size() << endl;
    for(auto v : vec) {
        cout << v << "\t";
    }
    cout << endl << endl;
}
int main(){
    vector<int> vec1({1,2,3});
    vector<int> vec2({{11,22,33}});

    print_vector(vec1);
    print_vector(vec2);

    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    print_vector(vec1);

    vector<string> str_v = {"a","b"};
    for (auto v: str_v) {
        cout << v << endl;
    }

    vector<vector<string>> str_v_v;
    str_v_v.push_back({"a","b"});


    vector<vector<int>> v_v_i(3,vector<int>(2,0));
    for(auto v1 : v_v_i)
        for(auto v2 : v1)
            cout << v2 << endl;

    cout << v_v_i.size() << "\t" << v_v_i[0].size() << endl;

    v_v_i.erase(v_v_i.begin() , v_v_i.begin() + 1);

    for(auto v1 : v_v_i)
        for(auto v2 : v1)
            cout << v2 << endl;

    vector<int> v_int(2,10);
    v_int.insert(v_int.end(), 2,11);
    for (auto v : v_int)
        cout << v << "\t";

}