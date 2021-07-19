// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <time.h>

using namespace std;

void print_vector(vector<int>& v) {
    for(auto x : v){
        cout << x << "\t";
    }
    cout << endl;
}

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
  
  time_t start, end;
  time(&start);
  for(auto x = a.begin(); x != a.end(); x++){
      //cout << "in erasing\n";
      if(find(b.begin(),b.end(),*x) != b.end()){
        //cout << "to remove " << *x << " from a\n";
        a.erase(x);
      }
  }
  time(&end);
  cout << "time consumed:" << (end - start) << endl;
  //print_vector(a);
    

  return 0;
}