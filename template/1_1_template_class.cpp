/**
 * Created by coast on 2019/4/22
 */
#include "1_1_template_class.h"

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