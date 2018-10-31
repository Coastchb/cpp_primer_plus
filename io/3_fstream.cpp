/**
 * Created by coast on 2018/10/31
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

// mark 1: do not use char* or string (which store the pointer of character string), or
//         only the pointer are stored and will point to wrong object
// mark 2: get() will read util newline character or the specified length are met;
//          >> will automatically eat the begining whitespace and newline util read characters and ends util meet whitespace or newline; (see 0_cout.cpp)
//        the whitespace or newline character will be left by them(not read or throw by them), so pay attention to
//        eat the extra character, otherwise error will occur while next reading (except for >> which will eat the beginning whitespace and newline character)
// what if the characters are read by >> or get() from binary file? And the numeric values?

const int LEN_NAME = 20;
inline void eatline(){ while(cin.get() != '\n'){}}

struct planet{
    char name[LEN_NAME];  // mark 1
    double population;
    double g;
};
int main(int argc, char * argv[]){
  if (argc != 2) {
    cerr << "Usage:" << argv[0] << " filename\n";
    exit(EXIT_FAILURE);
  }
  string filename = argv[1];

  planet pl;
  cout << "Read existing content in file " << filename << ":\n";
  ifstream fin;
  fin.open(filename, ios_base::in | ios_base::binary);
  if (fin.is_open()) {
    while(fin.read((char*)&pl, sizeof(pl))){
      cout << "pl.name:" << pl.name << "\tpopulation:" << pl.population << "\tpl.g:" << pl.g << endl;
    }
    fin.close();
  } else {
    cerr << "file " << filename << " not exists or error while reading file" << endl;
  }

  ofstream fout(filename, ios_base::out | ios_base::binary | ios_base::app);
  if (!fout.is_open()){
    cerr << "error while opening file " << filename << " for writing\n";
    exit(EXIT_FAILURE);
  }

  cout << "enter planet name:";
  cin.get(pl.name, LEN_NAME);
  while (pl.name[0] != '\0') {
    cout << "enter population for " << pl.name << ":";
    // mark 2
    eatline(); // the input for pl.name may be longer than 19, eat the extra characters!
    cin >> pl.population;

    cout << "enter g for " << pl.name << ":";
    // mark 2
    //eatline(); // optional
    cin >> pl.g;

    fout.write((char*)&pl, sizeof(pl));

    cout << "Enter planet name:";
    // mark 2
    eatline(); // eat the '\n'!  get() will not eat newline character!
    cin.get(pl.name, LEN_NAME);
  }
  fout.close();

  fin.open(filename, ios_base::in | ios_base::binary);
  if (fin.is_open()) {
    while(fin.read((char*)&pl, sizeof(pl))){
      cout << "pl.name:" << pl.name << "\tpopulation:" << pl.population << "\tpl.g:" << pl.g << endl;
    }
    fin.close();
  } else {
    cerr << "file " << filename << " not exists or error while reading file" << endl;
  }

  return 0;
}