/**
 * Created by coast on 2018/10/30
 */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
  string filename;
  cout << "Enter file name:";
  cin >> filename;

  ofstream fout(filename);
  fout << "First line" << endl;
  fout << "Second line" << endl;
  fout.close();

  string line;
  fstream fin(filename, ios_base::in);
  fin >> line;
  cout << "get: " << line << endl;
  fin >> line;
  cout << "get: " << line << endl;

  char ch;
  while(fin.get(ch)){
    cout << "get char:" << ch << endl;
  }

  size_t len = fin.tellp();
  cout << "fin.tellp()=" << len << ";sizeof(fin.tellp())=" << sizeof(len) << endl;
  fin.close();

  return 0;
}