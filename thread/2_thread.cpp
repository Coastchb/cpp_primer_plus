/**
 * Created by coast on 2018/10/11
 */
#include <iostream>
#include <thread>
#include <time.h>
#include <math.h>
#include <vector>

// important example

// multiple threads v.s one thread

void do_task(long l);

class Threads{
public:
  void run(int i, long n){
    for(int j=0;j < i; j++) {
      thread_list_.push_back(std::thread(do_task, n));
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
  long N = 100000000;
  int num_jobs = 100;

  // sequential mode
  time_t st, ed;
  st = time(NULL);
  for(int i = 0; i < num_jobs; i++){
    do_task(N);
  }
  ed = time(NULL);
  std::cout << "sequential mode consumed:" << (ed - st) << "s" << std::endl;

  // parallel mode
  time_t st1, ed1;
  st1 = time(NULL);
  std::thread threads[num_jobs];
  //int num_threads = std::min(num_jobs, 4);
  //std::cout << num_threads << std::endl;
  for(int i = 0; i < num_jobs; i++){
    threads[i] = std::thread(do_task, N);
  }
  for(int i = 0; i < num_jobs; i++){
    threads[i].join();
  }
  ed1 = time(NULL);
  std::cout << "parallel1 mode consumed:" << (ed1 - st1) << "s" << std::endl;

  // parallel mode
  time_t st2, ed2;
  st2 = time(NULL);
  {
    Threads tds;
    tds.run(num_jobs, N);
  }
  ed2 = time(NULL);
  std::cout << "parallel2 mode consumed:" << (ed2 - st2) << "s" << std::endl;

}

void do_task(long l){
  long j = 1;
  for(long i = 0; i < l; i++){
    j *= i;
  }
}