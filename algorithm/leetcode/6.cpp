//
// Created by coast on 19-4-22.
//
#include <iostream>
using namespace std;
class Solution {
public:
    string convert0(string s, int numRows) {
        if(numRows <= 0 || s.size() == 0) return "";
        string ret;
        size_t R = 2 * numRows - 2;
        for(size_t i = 0; i < numRows; i++) {
            size_t j = 0;
            while(1){
                size_t k;
                if(j != 0){
                    cout << (R*j-i) << endl;
                    k = R * j - i;
                    cout << R << "\t" << j << "\t" << i << "\t" << k << "\t" << s.size() << endl;
                    if(k >= s.size()){
                        cout << "k>=s.size()\n";
                        break;
                    }

                    if(k >= 0)
                        ret += s[k];
                }

                if( (R % 2 == 0 && R == 2 * i)) {
                    j++;
                    cout << "continue!" << endl;
                    continue;
                }
                k = R * j + i;
                cout << R << "\t" << j << "\t" << i << "\t" << k << "\t" << s.size() <<  endl;
                if(k < s.size())
                    ret += s[k];
                j++;
            }
        }
        return ret;
    }

    string convert(string s, int numRows) {
        if(s=="" || numRows <= 0) return "";
        if(numRows == 1) return s;
        size_t R = 2 * numRows - 2;
        size_t N = s.size();
        string ret = "";
        for (size_t i = 0; i < numRows; i++) {
            for(size_t j = i; j < N; j++) {
                if( (j - i) % R == 0  || (j + i) % R == 0){
                    cout << "j=" << j <<"\ti=" << i << "\tR=" << R << "\t" << (j-i) % R << "\t" << (j+i) % R << endl;
                    ret += s[j];

                }

            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("ABCDEF", 7) << endl;
}