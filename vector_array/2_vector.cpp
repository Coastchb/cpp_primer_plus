//
// Created by coast on 19-3-24.
//
#include <iostream>
#include <vector>
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

}