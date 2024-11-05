/**
 * Created by coast on 2019/4/21
 */
#include "0_linked_list.h"

LinkedList::LinkedList() {
  head_ = new Node;
  head_->data = INT_MIN;
  head_->next = NULL;
  size_ = 0;
}

bool LinkedList::find_element(int e) const {
  Node* pt = this->head_;
  while(pt != NULL) {
    if(pt->data == e)
      return true;
    pt = pt->next;
  }
  return false;
}

bool LinkedList::add_element(int e) {
  Node* pt = this->head_;
  while(pt->next != NULL) {
    pt = pt->next;
  }
  pt->next = new Node;
  pt->next->data = e;
  pt->next->next = NULL;
  this->size_++;
  return true;
}


int main(int argc, char* argv[]) {
  LinkedList linkedList;

  cout << linkedList.get_header() << endl;

  for(int i = 0; i < 20; i++) {
    linkedList.add_element(i);
  }
  cout << "size of linkedList:" << linkedList.size() << endl;

  cout << "3 in linkedList: " << linkedList.find_element(3) << endl;

  return 0;
}