#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>

class LinkedList {
 public:
  LinkedList();
  virtual ~LinkedList() = default;

  // Insert number at the specified index.
  void Insert(int index, int number);
  size_t size() const;

  friend std::ostream& operator<< (std::ostream& os, const LinkedList& list);

 private:
  struct Node {
    Node(int data);
    int data;
    Node* next;
  };

  LinkedList::Node* head_;
  LinkedList::Node* tail_;
  size_t size_;
};

#endif // LINKED_LIST_H_
