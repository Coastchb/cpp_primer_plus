/**
 * Created by coast on 2019/4/20
 */
#include "1_template_class.h"

template <typename T>
Stack<T>::Stack() {
  num_ = 0;
  list_ = new T;
}

template <typename T>
Stack<T>::~Stack() {
  delete list_;
}

template <typename T>
void Stack<T>::push(T const& e) {
  num_++;
  list_[num_] = e;
}

template <typename T>
T const& Stack<T>::pop() {
  num_--;
  return list_[num_];
}

template <typename T>
bool Stack<T>::is_empty() const {
  return num_ == 0;
}