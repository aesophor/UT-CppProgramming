#include "linked_list.h"

using std::ostream;

LinkedList::Node::Node(int data) : data(data) {}

LinkedList::LinkedList() : head_(), tail_(), size_() {}


void LinkedList::Insert(int index, int number) {

}

size_t LinkedList::size() const {
  return size_;
}


ostream& operator<< (ostream& os, const LinkedList& list) {
  LinkedList::Node* ptr = list.head_;
}
