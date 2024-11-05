// map::emplace
#include <iostream>
#include <map>
#include <vector>
#include <time.h>
#include<sys/timeb.h>

using namespace std;

long long systemtime()
{
    timeb t;
    ftime(&t);
    return t.time*1000+t.millitm;
}

void print_map(map<string, int>& m) {
    for(auto v = m.begin(); v != m.end(); v++) {
        cout << v->first << ":" << v->second << endl;
    }
}

int main ()
{
  time_t start_time, end_time;
  int N = 100;
  map<string, int> mymap;
  
  time(&start_time);
  for(int i = 0; i < N; i++){
      string key = "a";
      mymap[key] = 1;
      cout << "key:" << key << endl;
  }
  print_map(mymap);
 


  
  
  return 0;
}