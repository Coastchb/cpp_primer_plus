/**
 * Created by coast on 2019/4/20
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef _1_TEMPLATE_CLASS_
#define _1_TEMPLATE_CLASS_

template <typename T>
class Stack {
private:
    int num_; // element number;
    T* list_;

public:
    Stack();
    void push(T const&);
    T const& pop();
    bool is_empty() const;
    ~Stack();

};

#endif