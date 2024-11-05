/**
 * Created by coast on 2019/4/21
 */
#include <iostream>
using namespace std;

 struct Node {
     int data;
     Node* next;
 };

 class LinkedList {
 private:
     size_t size_;
     Node* head_;

 public:
     LinkedList();
     virtual ~LinkedList(){delete head_;}

     bool add_element(int e);
     bool find_element(int e) const;
     size_t size() const {return this->size_;}
     int get_header(){return this->head_->data;}

 };