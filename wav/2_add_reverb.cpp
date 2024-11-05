//
// Created by coastcao(操海兵) on 2019-09-10.
//

#include "Reverb.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stddef.h>
#include <string>

using namespace std;

bool parse_pcm(const std::string& file_path, std::vector<int16_t>& pcm_data_vec) {
    pcm_data_vec.clear();
    std::fstream fs;
    fs.open(file_path, std::ios::binary | std::ios::in);
    fs.seekg(0, fs.end);

    int data_size = fs.tellg();
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

bool add_reverb(std::vector<int16_t>& in_pcm, const EffectReverb::settings& set, const int sample_rate, const int channel_num) {
    //EffectReverb::settings set = EffectReverb::Vocal_I;
    EffectReverb reverb_module(set, sample_rate);
    reverb_module.ProcessInitialize(channel_num);

    float *pIn = reverb_module.mInBlock[0];
    float *pOut = reverb_module.mOutBlock[0];
    for (int i=0;i<in_pcm.size();i++)
    {
        pIn[i] = (float)(in_pcm[i])/32768;
    }
    reverb_module.ProcessBlock(&pIn, &pOut, in_pcm.size());
    reverb_module.ProcessFinalize();

    std::vector<int16_t> out_pcm;
    for (int i=0;i<in_pcm.size();i++)
    {
        out_pcm.push_back(std::max<int16_t>(-32767, std::min<int16_t>((int16_t)(pOut[i]*32768), 32767)));
    }

    in_pcm = out_pcm;
    return true;
}

bool write_pcm(vector<int16_t>& pcm, const string& filename) {
    fstream fs(filename, ios::binary | ios::out);
    for (auto p : pcm) {
        fs.write((char*)(&p), sizeof(int16_t));
    }
    fs.close();
}

int main() {

    string pcm_file = "data/output.pcm";
    vector<int16_t> pcm;
    parse_pcm(pcm_file, pcm);

    if ( ! add_reverb(pcm, EffectReverb::Large_Room, 24000, 1)) {
        cerr << "failed to add reverb\n";
    } else {
        cout << "add reverb\n";
    }

    write_pcm(pcm, "data/output_reverb.pcm");


    return 0;
}