#include "linked_list_map.h"

#include <stdexcept>

using std::endl;
using std::ostream;
using std::runtime_error;

LinkedListMap::Node::Node(int key, int val) : prev(), next(), key(key), val(val) {}

LinkedListMap::LinkedListMap() : head_() {}

LinkedListMap::~LinkedListMap() {}


void LinkedListMap::Put(int key, int val) {
  // Two pass:
  // (1) Check if key already exists, if so, remove it
  // (2) Insert this node at the correct position.
  Node* new_node = new Node(key, val);

  // First pass
  Remove(key);

  // Second pass
  if (!head_) {
    head_ = new_node;
  } else if (!head_->next) {
    if (head_->val >= val) {
      head_->next = new_node;
      new_node->prev = head_;
    } else {
      new_node->next = head_;
      head_->prev = new_node;
      head_ = new_node;
    }
  } else {
    Node* ptr = head_;
    while (ptr->next && ptr->next->val >= val) {
      ptr = ptr->next;
    }
    // Create a new node at the end of the linked list.
    new_node->prev = ptr;
    new_node->next = ptr->next;
    if (ptr->next) {
      ptr->next->prev = new_node;
    }
    ptr->next = new_node;
  }
}

void LinkedListMap::Remove(int key) {
  if (!head_) {
    return;
  }

  if (head_->key == key) {
    Node* old_head = head_;
    head_ = head_->next;
    if (head_) {
      head_->prev = nullptr;
    }
    delete old_head;
  } else {
    Node* ptr = head_->next;
    while (ptr) {
      if (ptr->key == key) {
        ptr->prev->next = ptr->next;
        if (ptr->next) {
          ptr->next->prev = ptr->prev;
        }
        delete ptr;
        return;
      }
      ptr = ptr->next;
    }
  }
}

int LinkedListMap::Get(int key) const {
  Node* ptr = head_;
  while (ptr) {
    if (ptr->key == key) {
      return ptr->val;
    }
    ptr = ptr->next;
  }
  throw runtime_error("The key " + std::to_string(key) + " doesn't exist.");
}

ostream& operator<< (ostream& os, const LinkedListMap& list_map) {
  LinkedListMap::Node* ptr = list_map.head_;
  while (ptr) {
    os << ptr->key << ": " << ptr->val << endl;
    ptr = ptr->next;
  }
  return os;
}
