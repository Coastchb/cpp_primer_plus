/**
 * Created by coast on 2019/4/20
 */
#include <iostream>
#include <string>
using namespace std;

// 类模板成员函数实现必须要跟头文件在同一文件
// reference:
//   [1]http://www.cnblogs.com/lifexy/p/8781525.html
//   [2]https://www.cnblogs.com/xiehongfeng100/p/4073867.html

#ifndef _1_TEMPLATE_CLASS_
#define _1_TEMPLATE_CLASS_

template <typename T, int max_size>
class Stack {
private:
    int size_; // element number;
    T* list_;
    int capacity_;

public:
    Stack();
    bool push(T const&);
    bool pop(T&);
    bool is_empty() const {
      return size_ == 0;
    };
    bool is_full() const {
      return size_ == capacity_;
    };
    int get_size() const {
      return size_;
    }
    ~Stack();

};

template <typename T, int max_size>
Stack<T, max_size>::Stack() {
  size_ = 0;
  capacity_ = max_size;
  list_ = new T[capacity_];
}

template <typename T, int max_size>
Stack<T, max_size>::~Stack() {
  delete[] list_;
}

template <typename T, int max_size>
bool Stack<T, max_size>::push(T const& e) {
  if(is_full()) {
    cout << "The stack is already full, refuse to push the element:" << e << "!\n";
    return false;
  }
  list_[size_] = e;
  size_++;
  return true;
}

template <typename T, int max_size>
bool Stack<T, max_size>::pop(T& e) {
  if(is_empty()) {
    cout << "The stack is empty, refuse to pop anything!\n";
    return false;
  }
  size_--;
  e = list_[size_];
  return true;
}


#endif