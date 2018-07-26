//
// Created by 操海兵 on 26/04/2018.
//

#include <cmath>
#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void firstPrint();
void getInfo();
void get_len();
void print_int();
char * getName();
int splitStr(char, string, vector<string>*);
void SplitStringToVector(const string&,const char*,bool,vector<string>*);
void split_str(string&, const char*, vector<string>*);
void print(const char* s)
{
    cout << s << endl;
}
int main(int argc, const char * argv[]) {

    string raw_str= "比较^省心的^出行`方式,适合`~FAMILY`TRIP.~  bi3 jiao4 sheng3 xin1 de5 chu1 xing2 fang1 shi4 shi4 he2 ~ F_AE8 M_IH7 L_IY7 T_R_IH8_P ~";
    vector<string> str_ret;
    string de = "~";
    cout << de << endl;
    /*
    string s = "a~b";
    size_t f = s.find_first_of("~", 0);
    cout << string::npos<< endl << endl;
    while (f!=string::npos){
        cout << "f:" << f << endl;
        f = s.find_first_of("~", f + 1);
    }

    //print(de.c_str());
    //const char * a = de.c_str();
    //split_str(raw_str, de.c_str(), &str_ret);
    SplitStringToVector(raw_str, de.c_str(), true, &str_ret);
    cout << str_ret.size() << endl;
    vector<string>::iterator iter = str_ret.begin();
    while(iter != str_ret.end())
    {
        string tmp_str = *iter;
        size_t len_str = tmp_str.size();
        cout << "raw: " << tmp_str << endl;

        tmp_str.erase(0,tmp_str.find_first_of("\t"));
        cout << tmp_str << endl;
        iter += 1;
    }
    */
    //char* a = "ab";
    //cout << a << endl;
    //print(a);
}
void split_str(string& str, const char * de, vector<string>* ret)
{
    size_t start = 0, len_str = str.size();
    while(start != len_str)
    {
        size_t found = str.find_first_of(de,start);
        if(found == -1)
        {
            ret->push_back(str.substr(start,len_str));
            break;
        }else{
            ret->push_back(str.substr(start,found-start));
            start = found + 1;
        }

    }


}
void SplitStringToVector(const string& full, const char* delimiters,
                         bool omit_empty_strings,
                         vector<string>* out) {
    out->clear();


    size_t start = 0, end = full.size();
    size_t found = 0;
    while (found != string::npos) {
        found = full.find_first_of(delimiters, start);

        // start != end condition is for when the delimiter is at the end.
        if (!omit_empty_strings || (found != start && start != end))
            out->push_back(full.substr(start, found - start));
        start = found + 1;
    }

}

int splitStr(char delimiter, string str, vector<string>* ret)
{
    size_t start = 0, str_len = str.size();
    while(start < str_len)
    {
        size_t found_loc = str.find_first_of("\t", start);
        cout << (int)found_loc << endl;
        ret->push_back(str.substr(start, found_loc - start));
        start = found_loc + 1;
    }
    return 0;
}
char * getName()
{
    char temp[20];
    cout << "Enter something:";
    cin >> temp;
    char * ps = new char[strlen(temp) + 1];
    //ps = temp;
    strcpy(ps,temp);
    return ps;
}
void print_int()
{
    cout << 0x11 << endl;
    cout << hex;
    cout << 0x11 << endl;
}
void getInfo()
{
    string name;
    cout << "Enter your name:";
    cin >> name;
    cout << "Hello, " << name << endl;
}
void firstPrint()
{
    cout << "Come up and C++ me some time.";
    cout << endl;
    cout << "You won't regret it!" << "\n";
}
void get_len()
{
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    cout << "int is " << sizeof(int) << " bytes" << endl;
    cout << "short is " << sizeof(n_short) << " bytes" << endl;
    cout << "long is " << sizeof (n_long) << " bytes" << endl;
    cout << "long long is " << sizeof n_llong << " bytes" << endl << endl;

    cout << "Max values:" << endl;
    cout << "int :" << n_int << endl;
    cout << "short :" << n_short << endl;
    cout << "long :" << n_long << endl;
    cout << "long long :" << n_llong <<endl;

    cout << "int min: " << INT_MIN << endl;
    cout << "Bit of each char: " << CHAR_BIT << endl;
}
