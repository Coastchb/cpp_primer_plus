/**
 * Created by coast on 2018/10/29
 */

#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds
using namespace std;

// preliminary example

bool is_prime (int x) {
  for (int i = 2; i < x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main () {
  future<bool> fut = async(is_prime, 700020007);

  cout << "checking, please wait";
  chrono::milliseconds span(100);

  while (fut.wait_for(span) == future_status::timeout) { // 若超时，则继续wait_for
    cout << '.';
  }

  bool x = fut.get(); // 此时能保证共享状态已经就绪，因此get()不会阻塞

  cout << "\n700020007 " << (x ? "is" : "is not") << " prime.\n";

  return 0;
}
