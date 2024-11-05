//
// Created by coastcao(操海兵) on 2019-08-29.
//

#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
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
}

// mix audio and noise
void mix_pcm_vec(vector<int16_t>& data_pcm, vector<int16_t> & noise_pcm) {
    vector<int16_t> out_pcm;
    for(unsigned long i=0; i<min<unsigned long>(data_pcm.size(), noise_pcm.size()); i++)
    {
        out_pcm.push_back(std::max<int16_t>(-32767, std::min<int16_t>((int16_t)(1*data_pcm[i] + 1*noise_pcm[i]), 32767)));
    }
    data_pcm = out_pcm;
}

int main() {
    vector<int16_t> noise_pcm, data_pcm;
    parse_pcm("noise.pcm", noise_pcm);
    parse_pcm("10000.pcm", data_pcm);

    cout << noise_pcm.size() << endl;

    mix_pcm_vec(data_pcm, noise_pcm);
    write_pcm(data_pcm, "mix.pcm");


}