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

// important example
// the function returns multiple values
// mark 1: pay attention to the inside mechanism!
// mark 2: pass the first parameter with value instead of reference or pointer, otherwise error will occur.
//         make sure that the parameter passed to the called function is not changed before the called function stops to use it,
//         otherwise the function will call a null pointer or get an incorrect value.


// mark 2
tuple<int,string> do_task(int i, vector<string>* vv){
  stringstream ss;
  ss << i;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  //cout << "vv at: " << &vv << endl;
  vv->at(i) = "vv" + ss.str();
  //vv->push_back("vv"+ss.str());
  //std::this_thread::sleep_for(std::chrono::seconds(1));
  return make_tuple(i, ss.str());
}

int main(){
  time_t st = time(NULL);

  vector<future<tuple<int,string>>> futures;
  int N = 50;
  vector<string> v(N);
  cout << "v at: " << &v << endl;
  for(int j=0; j<N; j++){
    // mark 2
    futures.push_back(async(std::launch::async,do_task, j ,&v));
  }

  // mark 1
  // this for loop will run earlier than the multi-threads

  for(auto& s : v){
    cout << s << endl;
  }

  // this will wait for the multi-threads ends and get their returns
  for(auto& f : futures){
    tuple<int,string> ret = f.get();
    cout << get<0>(ret) << " " << get<1>(ret) << endl;
  }

  // this will get what we expect
  for(auto& s : v){
    cout << s << endl;
  }
  cout << v.size() << endl;

  time_t ed = time(NULL);
  cout << "Finished, consumed: " << (ed - st) << "s" << endl;
  return 0;
}