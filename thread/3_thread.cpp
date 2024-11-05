/**
 * Created by coast on 2018/10/11
 */
#include <iostream>
#include <thread>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>

// preliminary example

// multiple threads operate on global variable
// but it will fail when it comes to string (very strange)

void do_task(long l, int& a);

class Threads{
public:
  void run(int i, long n, int& aa){
    for(int j=0;j < i; j++) {
      thread_list_.push_back(std::thread(do_task, n, std::ref(aa)));
    }
  }
  ~Threads(){
    for(int i=0; i < thread_list_.size(); i++){
      if(thread_list_[i].joinable()){
        thread_list_[i].join();
      }
    }
  }

private:
  std::vector<std::thread> thread_list_;
};

int main(int argc, char *argv[]){
  long N = 10; //100000000;
  int num_jobs = 50; //100;
  std::string str;
  int a;


  // parallel mode
  time_t st2, ed2;
  st2 = time(NULL);
  {
    Threads tds;
    tds.run(num_jobs, N, a);
  }
  ed2 = time(NULL);
  std::cout << "parallel2 mode consumed:" << (ed2 - st2) << "s" << std::endl;

  std::ofstream fout("3_thread_out.txt");
  fout << str << std::endl;

  do_task(10,a);
  std::cout << a << std::endl;
}

void do_task(long l, int& a){
  for(long i = 0; i < l; i++){
    a += l;
  }

}