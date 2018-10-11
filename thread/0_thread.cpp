#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std;

void output1(int i)
{
  cout << i << endl;
}

void output2(){
  cout << "output2 started..." << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "output2 finished" << endl; // in detach mode, this will not be printed to console
  ofstream fout("from_output2");
  fout << "content outputed from output2 thread" << endl;


}

class Task{
public:
    Task(int i){i_=i;}
    void operator()(int i){
      cout << "output from Task class: " << i << " " << i_ << endl;
    }

private:
    int i_;
};

int main()
{

  int N = 10;
  thread threads[N];
  for (int i = 0; i < N; i++)
  {
    threads[i] = thread(output1, i);
    //cout << t.get_id() << endl;
  }

  for (int i = 0; i < N; i++)
  {
    threads[i].join();
  }
  thread t(output2);
  t.join();

  thread t1(Task(20), 2);
  t1.join();
  cout << "Finally return to main!" << endl;
  //getchar();
  return 0;
}