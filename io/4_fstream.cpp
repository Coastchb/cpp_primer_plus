/**
 * Created by coast on 2018/10/31
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// mark 1: pay attention to it.  after reading, remember to clear the eof flag, otherwise the file cannot be write or read
//          even though the pointer position has been reset
const int LEN_NAME = 20;
inline void eatline(){ while(cin.get() != '\n'){}}

struct planet{
    char name[LEN_NAME];
    double population;
    double g;
};

int main(int argc, char* argv[]){
  if (argc != 2) {
    cerr << "Usage:" << argv[0] << " filename\n";
    exit(EXIT_FAILURE);
  }
  string filename = argv[1];

  planet pl;
  size_t planet_size = sizeof(pl);
  cout << fixed;

  fstream fio(filename, ios_base::in | ios_base::out | ios_base::binary);
  if (fio.is_open()){
    cout << "reading the existing content of file " << filename << ":\n";
    while (fio.read((char*)&pl, planet_size)) {
      cout << "pl.name:" << pl.name << "\tpl.population:" << pl.population << "\tpl.g:" << pl.g << endl;
    }

    // mark 1
    if (fio.eof()){
      fio.clear();
    }
  }

  cout << "after reading the entire file , tellg()=" << fio.tellg() << ",tellp()=" << fio.tellp() << endl;

  long p;
  cout << "the id of object to change:";
  cin >> p;

  size_t target_pos = p * planet_size;
  fio.seekg(target_pos);

  if (fio.read((char*)&pl, planet_size)){
    cout << "content of the target object:\n";
    cout << "pl.name:" << pl.name << "\tpl.population:" << pl.population << "\tpl.g:" << pl.g << endl;
  } else {
    cerr << "error while reading the target object\n";
    exit(EXIT_FAILURE);
  }

  cout << "eof flag after reading the target object:" << fio.eof() << endl;
  cout << "after reading the target object , tellg()=" << fio.tellg() << ",tellp()=" << fio.tellp() << endl;
  // mark 1
  if (fio.eof()){
    fio.clear();
  }

  size_t len = fio.tellp();
  cout << len << " sizeof(fio.tellp()):" << sizeof(len) << endl;

  cout << "enter the new name:";
  eatline();
  cin.get(pl.name, LEN_NAME);
  cout << "enter the new population:";
  eatline();
  cin >> pl.population;
  cout << "enter the new g:";
  cin >> pl.g;

  fio.seekp(target_pos);
  fio.write((char*)&pl,planet_size) << flush;

  cout << "sizeof(pl)=" << planet_size << endl;
  cout << "just after writing, tellg()=" << fio.tellg() << ",tellp()=" << fio.tellp() << endl;
  if (fio.fail()) {
    cerr << "fail to write to file\n";
    exit(EXIT_FAILURE);
  }

  fio.seekg(0);
  cout << "reading the new content of file " << filename << ":\n";
  while (fio.read((char*)&pl, planet_size)) {
    cout << "pl.name:" << pl.name << "\tpl.population:" << pl.population << "\tpl.g:" << pl.g << endl;
  }

  fio.close();

  return 0;
}