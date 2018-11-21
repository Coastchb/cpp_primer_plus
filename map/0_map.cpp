/**
 * Created by coast on 2018/11/20
 */
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
  return a.second < b.second;
}

//template <class RandomAccessIterator>
//void sort(RandomAccessIterator first, RandomAccessIterator last);

int main(int argc, char* argv[]) {
    map<string, int> dict;
    vector<string> phones;
    for(int i = 0; i <= 9; i++) {
      phones.push_back("a");
    }
    for(int i = 0; i <= 2; i++) {
      phones.push_back("b");
    }
    for(int i = 0; i <= 4; i++) {
      phones.push_back("c");
    }
    phones.push_back("d");

    for(auto ph : phones) {
      auto iter = dict.find(ph);
      if(iter != dict.end()) {
        iter->second += 1;
      } else {
        dict.insert(make_pair(ph,1));
      }
    }
    dict["e"] = 1;
    map<string,int>* dp = &dict;
    //dp->at("f") = 1;

    vector<pair<string,int>> vec(dict.begin(),dict.end());
    sort(vec.begin(), vec.end(), cmp);
    for(auto iter=dict.begin();iter!=dict.end();iter++) {
      cout << iter->first << " occurs " << iter->second << " times" << endl;
    }
    cout << "after sorted:" << endl;
    for(auto iter=vec.begin();iter!=vec.end();iter++) {
      cout << iter->first << " occurs " << iter->second << " times" << endl;
    }

}