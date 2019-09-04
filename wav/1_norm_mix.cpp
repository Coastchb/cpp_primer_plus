//
// Created by coastcao(操海兵) on 2019-09-03.
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
    return true;
}

bool norm_pcm(vector<int16_t> & in_pcm, int norm_val, vector<int16_t>& out_pcm) {

    // find the max value in pcm
    int16_t max = in_pcm[0];
    for (auto iter = in_pcm.begin() + 1; iter != in_pcm.end(); iter++) {
        //max = *iter > max ? *iter : max;
    }

    auto iter = in_pcm.begin();
    int count = 0;
    while(true) {
        if(*(iter+count) != 0) {
            cout << count << endl;
            cout << *iter << endl;
            break;
        }
        count++;
    }

    cout << in_pcm.size() << endl;
    if (max == 0) {
        cout << "ERROR: max value = 0";
        return false;
    }
    for (auto iter = in_pcm.begin(); iter != in_pcm.end(); iter++) {
        //cout << (*iter) << "\t" << norm_val << "\t" << max << endl;
        out_pcm.insert(out_pcm.end(), (*iter) * norm_val / max);
    }
    return true;
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


//参数为数据，采样个数
//返回值为分贝
#define VOLUMEMAX   32767
int SimpleCalculate_DB(vector<int16_t>& pcmData)
{
    int16_t ret = 0;
    if (pcmData.size() > 0){
        int16_t sum = 0;
        for(auto v : pcmData) {
            sum += abs(v);
        }

        ret = sum * 500 / (pcmData.size() * VOLUMEMAX);
        if (ret >= 100){
            ret = 100;
        }
    }
    return ret;
}

int main() {
    vector<int16_t> in_pcm, out_pcm;
    parse_pcm("data/10000_sox_norm_-3.pcm", in_pcm);

    cout << SimpleCalculate_DB(in_pcm) << endl;
    /*
    if (!norm_pcm(in_pcm, -3, out_pcm)) {
        cout << "ERROR: failed to norm pcm\n";
    }*/
    //write_pcm(out_pcm, "data/10000_norm_-3.pcm");

    return 0;
}