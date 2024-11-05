/**
 * Created by coast on 2018/10/11
 */
#include <iostream>
#include <thread>
using namespace std;

// preliminary example

// Mark 1: must use "ref(counter)" because f1 accept int reference, even though counter is declared as int reference;
//        if "f1(int counter)", then "thread t1(f1, counter)" is ok

void f1(int &counter);


int main()
{

  int counter = 0;
  // Mark 1
  thread t1(f1, ref(counter));
  t1.join();

  f1(counter);
  std::cout << "a" << std::endl;
  return 0;
}


void f1(int &counter)
{
  while (true)
  {
    ++counter;
    if (counter < 100)
    {
      std::cout << "Function 1 counting " << counter << "...\n";
    }
    else
    {
      break;
    }
  }
}
