#include "linked_list.h"

#include <stdexcept>

using std::ostream;
using std::out_of_range;

LinkedList::Node::Node(int data) : data(data), next() {}

LinkedList::LinkedList() : head_(), tail_(), size_() {}


void LinkedList::Insert(int index, int number) {
  if (index > (int) size_) {
    throw out_of_range("LinkedList::Insert index out of range!");
  }

  Node* new_node = new Node(number);
  size_++;

  if (index == 0) {
    new_node->next = head_;
    head_ = new_node;
    if (!tail_) {
      tail_ = new_node;
    }
  } else if (index == (int) size_) {
    tail_->next = new_node;
    tail_ = new_node;
  } else {
    Node* ptr = head_;
    for (int i = 0; i < (int) index - 1; i++) {
      ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
  }
}

size_t LinkedList::size() const {
  return size_;
}


ostream& operator<< (ostream& os, const LinkedList& list) {
  LinkedList::Node* ptr = list.head_;
  while (ptr) {
    os << ptr->data;
    os << ((ptr->next) ? "->" : "");
    ptr = ptr->next;
  }
  return os;
}
