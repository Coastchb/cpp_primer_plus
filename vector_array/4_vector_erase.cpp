// string::substr
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vector(vector<int>& v) {
    for (auto x = v.begin(); x != v.end(); x++) {
        cout << *x << "\t";
    }
    cout << endl;

    for(auto x : v) {
        cout << x << "\t";
    }
    cout << endl;
}

int main ()
{
    vector<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    //print_vector(a);
    
    for(auto x = a.begin(); x < a.end(); x++) {
        cout << "*x:" << *x << endl;
        if(*x == 3) {
            a.erase(x);
        }   
        print_vector(a);   
    }

    cout << "nnn\n";
    vector<int> b = {12, 23, 34, 45, 56, 67, 78, 89};
     
    auto iter = b.begin();
    while (iter != b.end()) {
        if (*iter > 30) {
            iter = b.erase(iter);
        }
        else {
            ++iter;
        }
    }

    print_vector(b);   

  return 0;
}