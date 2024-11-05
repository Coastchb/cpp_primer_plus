/**
 * Created by coast on 2019/4/22
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

#include "1_1_template_class.cpp"
#endif