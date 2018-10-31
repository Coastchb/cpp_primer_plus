/**
 * Created by coast on 2018/10/28
 */

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){


 string filepath = "./5.ie";
 ifstream is;
 char * buffer;
 long size;
 is.open(filepath, ios_base::in|ios_base::binary);//|ios_base::ate);
 //size = is.tellg();
  /*
 is.seekg (0, ios::beg);
 buffer = new char[size];
 is.read(buffer, size);
 is.close();
  */
 string str;
 //is >> str;
 //cout << size << " " << "buffer:" << str << std::endl;
  if (is.peek() == '\0') {  // seems to be binary
    cout << "seems to be binary" << endl;
    is.get();
    if (is.peek() != 'B') {
      cout << "Something wrong" << endl;
    }
    is.get();
  } else {
    cout << "nothing" << endl;
  }

  /*
  is >> str;
  cout << str << endl;
  ios_base::openmode mode = std::ios_base::in | std::ios_base::binary;
  ios_base::openmode mode1 = std::ios_base::in;
  ios_base::openmode mode2 = std::ios_base::binary;
  cout << mode << " " << mode1 << " " << mode2 << endl;
   */
  size = is.tellg();
  buffer = new char[size];
  is.read(buffer, size);
  is.close();
  cout << size << " " << "buffer:" << buffer << std::endl;
/*
  bool a;
  cout << a << endl;
 string filename = "./final.ie";
 char * buffer;
 long size;
 ifstream in (filename, ios::in|ios::binary);
 size = in.tellg();
 in.seekg (0, ios::beg);
 buffer = new char [size];
 in.read (buffer, size);
 in.close();
 cout << size << " " << buffer << endl;
 delete[] buffer;
*/
  return 0;
}