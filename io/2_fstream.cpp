/**
 * Created by coast on 2018/10/30
 */
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]){
  if (argc != 2){
    cerr << "Usage:" << argv[0] << "file" << endl;
    exit(EXIT_FAILURE);
  }
  string filename = argv[1];
  ifstream fin;
  fin.open(filename);
  if(!fin.is_open()){
    cerr << "error while opening file " << filename << endl;
    exit(EXIT_FAILURE);
  }
  char ch;
  cout << "existing content in file" << filename << ":\n";
  while (fin.get(ch)){
    cout << ch;
  }
  fin.close();

  ofstream fout;
  fout.open(filename,ios_base::out|ios_base::app);
  fout << "the appended content\n";
  fout.close();

  fin.open(filename);
  cout << "after appending,the content in file" << filename << ":\n";
  if(!fin.is_open()){
    cerr << "error while opening file " << filename << endl;
    exit(EXIT_FAILURE);
  }
  while (fin.get(ch)){
    cout << ch;
  }
  fin.close();

}