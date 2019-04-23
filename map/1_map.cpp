/**
 * Created by coast on 2019/4/22
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

// if "b" is not in map, and calling m["b"] will add <"b",0> to map

void print_map(map<string,int>& m) {
  for(auto iter = m.begin(); iter != m.end(); iter++) {
    cout << iter->first << ":" << iter->second << endl;
  }
}
int main(int argc, char* argv[]) {
  map<string,int> m;
  m["a"] = 1;

  print_map(m);

  cout << m["b"] << endl;

  print_map(m);

  return 0;
}