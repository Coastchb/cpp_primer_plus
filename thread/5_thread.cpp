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
#include <mutex>

// important example: based on 3_thread.cc

// multiple threads operate on global variable


void do_task(long l, std::string& a, std::mutex& m);

class Threads{
public:
    void run(int i, long n, std::string& aa, std::mutex& m){
      for(int j=0;j < i; j++) {
        thread_list_.push_back(std::thread(do_task, n, std::ref(aa), std::ref(m)));
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
  int num_jobs = 100; //100;
  std::string str;
  int a;

  std::mutex mtx;

  // parallel mode
  time_t st2, ed2;
  st2 = time(NULL);
  {
    Threads tds;
    tds.run(num_jobs, N, str, mtx);
  }
  ed2 = time(NULL);
  std::cout << "parallel2 mode consumed:" << (ed2 - st2) << "s" << std::endl;

  std::ofstream fout("3_thread_out.txt");
  fout << str << std::endl;

  do_task(10,str, mtx);
  std::cout << str << std::endl;
}

void do_task(long l, std::string& st, std::mutex& m){
  for(long i = 0; i < l; i++){
    if(m.try_lock()) {
      st = st + std::to_string(l);
      m.unlock();
    }
  }

}