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
#include <tuple>
using namespace std;

// import example
// the function returns multiple values
tuple<int,string> do_task(int i, vector<int>& vv){
  stringstream ss;
  ss << i;
  //cout << "vv at: " << &vv << endl;
  vv[i] = i;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return make_tuple(i, ss.str());
}

int main(){
  time_t st = time(NULL);

  vector<future<tuple<int,string>>> futures;
  int N = 50;
  vector<int> v(N);
  cout << "v at: " << &v << endl;
  for(int j=0; j<N; j++){
    futures.push_back(async(std::launch::async,do_task,j,ref(v)));
  }

  for(auto& s : v){
    cout << s << endl;
  }

  for(auto& f : futures){
    tuple<int,string> ret = f.get();
    cout << get<0>(ret) << " " << get<1>(ret) << endl;
  }

  time_t ed = time(NULL);
  cout << "Finished, consumed: " << (ed - st) << "s" << endl;
  return 0;
}