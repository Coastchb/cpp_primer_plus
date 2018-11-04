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
// mark 1: pay attention to the inside mechanism!

tuple<int,string> do_task(int i, vector<string>* vv){
  stringstream ss;
  ss << i;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  //cout << "vv at: " << &vv << endl;
  //vv->at(i) = "vv" + ss.str();
  vv->push_back("vv"+ss.str());
  //std::this_thread::sleep_for(std::chrono::seconds(1));
  return make_tuple(i, ss.str());
}

int main(){
  time_t st = time(NULL);

  vector<future<tuple<int,string>>> futures;
  int N = 50;
  vector<string> v; //(N);
  cout << "v at: " << &v << endl;
  for(int j=0; j<N; j++){
    futures.push_back(async(do_task,j,&v));
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