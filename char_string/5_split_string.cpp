/**
 * Created by coast on 2019/3/20
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Caution: 请注意string::find 和 string::find_first_of 的区别！！！

string delimiters[] = {"。", "！", "？"};

void SplitStringToVector(const string& full,
                         bool omit_empty_strings,
                         vector<string>* out) {
  //CHECK(out != NULL);
  out->clear();

  size_t start = 0, end = full.size();
  bool has_end = false;

  //for (int i = 0; i < 2; i++) {
  while(! has_end) {
    has_end = true;
    size_t found = end;
    string cur_delim = "";
    for(auto de: delimiters) {
      size_t tmp_found = full.find(de, start);
      if(tmp_found != string::npos){
        has_end = false;
        if (found > tmp_found){
          found = tmp_found;
          cur_delim = de;
        }
      }
    }

    // start != end condition is for when the delimiter is at the end.
    if (!omit_empty_strings || (found != start && start != end))
      out->push_back(full.substr(start, found - start));
    start = found + cur_delim.size();
  }
}

int main() {
  string text = "据中央气象局预计，今明两天北京市有中雨。请市民做好出行准备！带好雨具。有任何疑问吗？";
  vector<string> ret;

  //tmp_fun(delim);
  SplitStringToVector(text, true, &ret);
  for(auto s: ret){
    cout << s << endl;
  }
}