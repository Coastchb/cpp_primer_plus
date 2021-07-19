// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <time.h>
#include <map>

using namespace std;


int main () {
  // using std::find with array and pointer:
  int N = 1000000;
  vector<int> a;
  a.reserve(N);
  
  for(int x = 0; x < N; x++)
    a.emplace_back(x);

  //print_vector(a);
  
  int M = 1000000;
  vector<int> b;
  b.reserve(M);
  for(int x = 0; x < M; x++)
    b.emplace_back(x);

  map<int, char> b_map;
  for(auto x : b)
    b_map[x] = '1';
  
  time_t start, end;
  time(&start);
  for(auto x = a.begin(); x != a.end(); x++){
      //cout << "in erasing\n";
      if(b_map.find(*x) != b_map.end()){
        //cout << "to remove " << *x << " from a\n";
        a.erase(x);
      }
  }
  time(&end);
  cout << "time consumed:" << (end - start) << endl;
  //print_vector(a);
    

  return 0;
}