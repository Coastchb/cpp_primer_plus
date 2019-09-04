//
// Created by coastcao(操海兵) on 2019-08-23.
//

#include <fstream>

using namespace std;

int main() {
    float arr[2][3] = {{1.0, 2.0, 3.0},{4.0, 5.0, 6.0}};

    ofstream fos("files/8.txt", ios_base::out);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            fos << arr[i][j] << " ";
        }
        fos << endl;
    }
    fos.close();
}