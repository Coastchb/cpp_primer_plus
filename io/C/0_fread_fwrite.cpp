//
// Created by coastcao(操海兵) on 2019-08-30.
//
#include <stdlib.h>
#include <iostream>
using namespace std;

void write_float_array_to_binary_file(const string& file, float* arr, int size) {

    FILE * fw = fopen(file.c_str(), "wb");
    fwrite(arr, sizeof(float), size, fw);
    fclose(fw);
}

void read_float_array_from_binary_file(const string& file) {
    FILE * pFile = fopen(file.c_str(), "rb");

    fseek (pFile , 0 , SEEK_END);
    long lSize = ftell (pFile);
    rewind (pFile);

    float * buffer;
    buffer = (float*) malloc (sizeof(float)*lSize);

    size_t result = fread(buffer,1,lSize,pFile);


    for (int i = 0; i < result / sizeof(float); i++) {
        cout << buffer[i] << "\t";
    }

    cout << endl << lSize << endl;

}

int main() {
    float arr[] = {1.2, 3.4, 5.6, 7.8, 9.10, 11.12, 12.13};
    write_float_array_to_binary_file("files/0.bin", arr, 7);
    read_float_array_from_binary_file("files/0.bin");
}