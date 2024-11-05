//
// Created by coast on 19-3-24.
//
#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <algorithm>
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

/*
int exp1() {

    vector<pair<string, int> > samples = {
        make_pair("item1", 0), 
        make_pair("item2", 0), 
        make_pair("item3", 0),
        make_pair("item4", 1),
        make_pair("item5", 0), 
        make_pair("item6", 1), 
        make_pair("item7", 1),
        make_pair("item8", 1),
        make_pair("item9", 1), 
        make_pair("item10", 1), 
        make_pair("item11", 0),
        make_pair("item12", 1)};

    vector<pair<string, int>> sample_cache;
    vector<pair<string, int>> result;
    int library_num = 100;
    sample_cache.reserve(library_num);
    result.reserve(samples.size());
    int latest_sample_idx = -1;

    for(int i = 0; i < samples.size(); i++) {
        pair<string,int> cur_sample = samples[i];
        cout << "processing sample: " << get<0>(cur_sample) << std::endl;

        if(sample_cache.size() <= 0) {
            // no opposite sample in cache, store it
            std::cout << "no opposite sample in cache, store it!\n";
            latest_sample_idx = 0;
            std::cout << "latest_sample_idx:" << latest_sample_idx << std::endl;
            sample_cache.emplace_back(cur_sample);
            std::cout << "samples_cache.size():" << sample_cache.size() << std::endl;

        } else if(get<1>(sample_cache[0]) == get<1>(cur_sample)) {
            // too much the same kind of sample, store it
            std::cout << "too much the same kind of sample, store it\n";
            latest_sample_idx = (latest_sample_idx + 1) % library_num;
    
            if(sample_cache.size() < library_num) {
                sample_cache.emplace_back(cur_sample);
    
            } else {
                sample_cache[latest_sample_idx] = cur_sample;
            }
        } else {
            // get the latest opposite sample, and output them
            std::cout << "get the latest opposite sample, and output them\n";
            auto opposite_sample = sample_cache[latest_sample_idx];
            sample_cache.erase(sample_cache.begin() + latest_sample_idx);
            latest_sample_idx = (latest_sample_idx - 1) % library_num;
            std::cout << "samples_cache.size()" << sample_cache.size() << std::endl;
            // output the opposite sample in addition
            result.push_back(cur_sample);
            result.push_back(opposite_sample);
    
            std::cout << get<0>(cur_sample) << std::endl;
        }


        cout << "after processing:\n";
        for (auto v : sample_cache) {
            cout << get<0>(v) << endl;
        }
    }

    cout << "the final result:\n";
    for (auto v : result) {
        cout << get<0>(v) << endl;
    }
    return 0;
} */

void exp2() {
    vector<pair<string,int> > vec;
    vec.emplace_back(make_pair("a", 0));
    vec.emplace_back(make_pair("b", 1));
    vec.emplace_back(make_pair("c", 2));

    pair<string, int> target = make_pair("c", 2);
    vector<pair<string, int> >::iterator it = 
    find(vec.begin(), vec.end(), target);
    if(it != vec.end()) {
        std::cout << std::get<0>(*it) << std::endl;
    } else {
        std::cout << "cannot find target!\n";
    }

}
int main(){
    /*
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

    cout << "\nafter erasing\n";

    v_int.erase(v_int.begin() + 2, v_int.end());
	for (auto v : v_int)
		cout << v << "\t";
    cout << endl;
    */
   exp2();
}

