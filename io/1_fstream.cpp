/**
 * Created by coast on 2018/10/30
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]){
  if(argc != 4){
    cerr << "Usage:" << argv[0] << " f1 f2 f3" << endl;
    exit(EXIT_FAILURE);
  }

  fstream fin;
  long count = 0;
  for(int i = 1; i < argc; i++){
    fin.open(argv[i]);
    if(!fin.is_open()){
      cout << "Error open file" << argv[i] << endl;
      exit(EXIT_FAILURE);
    }
    char ch;
    while(fin.get(ch)) {
      count += 1;
    }
    fin.close();
    fin.clear();
  }
  cout << "total character count: " << count << endl;

  return 0;
}