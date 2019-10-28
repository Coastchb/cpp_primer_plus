//
// Created by coastcao(操海兵) on 2019-09-03.
//

#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <math.h>
//#include "Audacity.h"
//#include "effects/Normalize.h"
using namespace std;

bool parse_pcm(const string& file_path, vector<int16_t>& pcm_data_vec) {
    pcm_data_vec.clear();
    fstream fs;
    fs.open(file_path, ios::binary | ios::in);
    fs.seekg(0, fs.end);

    size_t data_size = fs.tellg();
    auto *pcm_data = new int16_t[data_size / sizeof(int16_t)];

    fs.seekg(0, fs.beg);
    fs.read((char *) pcm_data, sizeof(char) * data_size);

    int i;
    for (i = 0; i < data_size / sizeof(int16_t); i++) {
        pcm_data_vec.push_back(pcm_data[i]);
    }
    fs.close();
    delete[] pcm_data;

    return true;
}

bool write_pcm(vector<int16_t>& pcm, const string& filename) {
    fstream fs(filename, ios::binary | ios::out);
    for (auto p : pcm) {
        fs.write((char*)(&p), sizeof(int16_t));
    }
    fs.close();
    return true;
}

bool norm_pcm(vector<int16_t> & in_pcm, int norm_val, vector<int16_t>& out_pcm) {
    for (auto v : in_pcm) {
        out_pcm.insert(out_pcm.end(), v * pow(10, float(norm_val) / 20));
    }
    return true;
}

// mix audio and noise
bool mix_pcm(vector<int16_t>& pcm_1, vector<int16_t> & pcm_2, vector<int16_t> & out_pcm) {
    for(unsigned long i=0; i<min<unsigned long>(pcm_1.size(), pcm_2.size()); i++)
    {
        out_pcm.insert(out_pcm.end(), std::max<int16_t>(-32767, std::min<int16_t>((int16_t)(1*pcm_1[i] + 1*pcm_2[i]), 32767)));
    }
    return true;
}


int16_t get_max(vector<int16_t>& in) {
    int16_t max = -32767; //int16_t.MAX;
    for(auto v:in) {
        max = v > max ? v : max;
    }

    return max;
}

int main() {
    vector<int16_t> in_pcm, normed_pcm, noise_pcm, mixed_pcm;
    parse_pcm("data/10000.pcm", in_pcm);

    if (!norm_pcm(in_pcm, -6, normed_pcm)) {
        cout << "ERROR: failed to norm pcm\n";
    }
    write_pcm(normed_pcm, "data/10000_norm_-6.pcm");

    parse_pcm("data/noise.pcm", noise_pcm);
    if (!mix_pcm(in_pcm, noise_pcm, mixed_pcm)) {
        cout << "ERROR: failed to mix pcm\n";
    }
    write_pcm(mixed_pcm, "data/10000_noise.pcm");


    return 0;
}