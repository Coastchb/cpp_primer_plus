/**
 * Created by coast on 2018/10/11
 */
#include<iostream>    //std::cout std::endl
#include<thread>      //std::thread
#include<future>      //std::future std::promise
#include<utility>     //std::ref
#include<chrono>      //std::chrono::seconds

// preliminary example
// ref: https://blog.csdn.net/hutianyou123/article/details/79147541

void initiazer(std::promise<int> &promiseObj) {
  std::cout << "Inside thread: " << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  promiseObj.set_value(35);
}

int main() {
  std::promise<int> promiseObj;
  std::future<int> futureObj = promiseObj.get_future();
  std::thread th(initiazer, std::ref(promiseObj));

  std::cout << futureObj.get() << std::endl;

  th.join();
  return 0;
}
