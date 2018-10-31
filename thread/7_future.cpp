/**
 * Created by coast on 2018/10/29
 */

#include <future>
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
using namespace std;

// import example
// the function returns one value
// Caution:
// in multithread, lock must be used if the non-thread-safe operation (e.g assign value to the same variable) will be done by several threads;
// for vector, it has lock mechanism inside, e.g push_back is thread-safe

string do_task(int i, int& k, vector<int>& j){
  stringstream ss;
  ss << i;
  k+=1; //
  //j.push_back(1);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return ss.str();
}

int main(){
  time_t st = time(NULL);

  vector<future<string>> futures;
  int N = 100, k=0;
  vector<int> v;
  {
    for(int j=0; j<N; j++){
      futures.push_back(async(std::launch::async,do_task,j, ref(k), ref(v)));
    }
  }

  for(auto& f : futures){
    cout << f.get() << endl;
  }

  time_t ed = time(NULL);
  cout << "Finished, consumed: " << (ed - st) << "s" << endl; // !!! get unexpected k
  cout << "k=" << k << endl;
  cout << "size(v)=" << v.size() << endl;
  return 0;
}