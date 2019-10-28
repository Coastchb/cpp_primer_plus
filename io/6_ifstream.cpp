/**
 * Created by coast on 2019/3/25
 */
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;


bool load_file(string& file, map<string,string>* dict) {
  ifstream fis(file, ios_base::in);
  if(fis.is_open()){
    //string line;
    char line[1024];
    while(fis.getline(line, 1024)) {
      size_t found = string(line).find(" ", 0);
      if(found == string::npos){
        continue;
      }
      string word = string(line).substr(0, found);
      string pron = string(line).substr(found);
      dict->emplace(word, pron);
    }
  }
  return true;
}

bool load_file1(string& file, map<string, string> * dict) {
    fstream fs(file, ios::in);
    string line;
    while(getline(fs, line)) {
        size_t found = string(line).find(" ", 0);
        if(found == string::npos){
            continue;
        }
        string word = string(line).substr(0, found);
        string pron = string(line).substr(found);
        dict->emplace(word, pron);
    }

    return true;
}

int main(){
  string file = "files/6.txt";
  map<string,string> dict, dict1;
  load_file(file, &dict);

  for(auto& x: dict) {
    cout << x.first << "\t" << x.second << endl;
  }

  load_file1(file, &dict1);

    for(auto& x: dict1) {
        cout << x.first << "\t" << x.second << endl;
    }

  cout << "pronunciation for 我 is: " << dict["我"] << endl;
  return 0;

}