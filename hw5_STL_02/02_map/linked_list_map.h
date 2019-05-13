#ifndef LINKED_LIST_MAP_H_
#define LINKED_LIST_MAP_H_

#include <iostream>

class LinkedListMap {
 public:
  LinkedListMap();
  virtual ~LinkedListMap();

  void Put(int key, int val);
  void Remove(int key);
  int Get(int key) const;
  friend std::ostream& operator<< (std::ostream& os, const LinkedListMap& list_map);

 private:
  struct Node {
    Node(int key, int val);
    Node* prev;
    Node* next;
    int key;
    int val;
  };

  LinkedListMap::Node* head_;
};

#endif // LINKED_LIST_MAP_H_
