/**
 * Created by coast on 2019/3/28
 */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

// So, use fread to read data written by fwirte ??


int main() {
  short a = 12245;

  fstream fw("files/7.bin", ios_base::out | ios_base::binary);
  fw.write(to_string(a).c_str(), 5);
  fw.close();

  fstream fr("files/7.bin", ios_base::in | ios_base::binary);
  char * data = new char[5];
  fr.read(data, 5);
  cout << data << endl;
  fr.close();


  FILE * wFile;
  wFile = fopen ("files/7_1.bin", "wb");
  fwrite(&a, sizeof(short), 1, wFile);
  fclose(wFile);

  fstream fr_1("files/7_1.bin", ios_base::in | ios_base::binary);
  char * data_1 = new char[2];
  fr_1.read(data_1, 2);
  cout << *data_1 << endl;
  cout << data_1 << endl;
  cout << fr_1.gcount() << endl;
  fr_1.close();

  FILE * rFile;
  rFile = fopen ("files/7_1.bin", "rb");
  short aa;
  size_t num = fread(&aa, sizeof(short), 1, rFile);
  cout << aa << endl;
  fclose(rFile);

  ifstream is ("files/7_1.bin", std::ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length];

    std::cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    if (is) {
      std::cout << "all characters read successfully." << endl;
      cout << *buffer << endl;
    }
    else
      std::cout << "error: only " << is.gcount() << " could be read";
    is.close();

    // ...buffer contains the entire file...

    delete[] buffer;
  }
}