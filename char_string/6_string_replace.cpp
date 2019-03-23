#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

string boson_key = "2DgGSC-8.33497.8yeNchBP6L9n";

string useless_symbols[] = {"“", "”", "《", "》"};
unordered_map<std::string, string> replace_map = {
        {"，", ","},
        {"；", ";"}};


void replace_single(string& text, const string src_sym, const string tar_sym) {
    size_t src_sym_len = src_sym.size(), tar_sym_len = tar_sym.size();
    size_t found = text.find(src_sym, 0);
    while(found != string::npos) {
        text.replace(found, src_sym_len, tar_sym);
        found = text.find(src_sym, found + tar_sym_len);
    }
}

void replace_all(string& text) {
    for(auto sym: useless_symbols) {
        replace_single(text, sym, "");
    }
    for(auto& sym: replace_map) {
        replace_single(text, sym.first, sym.second);
    }

}

void get_segment_pos(string& text) {
    string filename = "tmp.txt";
    string segment_pos_cmd = "curl -X POST \\\n"
                             "     -H \"Content-Type: application/json\" \\\n"
                             "     -H \"Accept: application/json\" \\\n"
                             "     -H \"X-Token:" + boson_key + "\" \\\n"
                             "     --data \"\\\"" + text + "\\\"\" \\\n"
                             "     'http://api.bosonnlp.com/tag/analysis?space_mode=0&oov_level=3&t2s=0' > " + filename;
    cout << segment_pos_cmd << endl;
    system("echo 'hello, coast'");
    int str = system(segment_pos_cmd.c_str());
    cout << str << endl;
}

int main() {
    string text = "今天，读了“诗圣”李白的古诗《静夜思》；然后洗了个澡。";
    cout << text << endl;
    replace_all(text);
    cout << text << endl;

    get_segment_pos(text);


}
