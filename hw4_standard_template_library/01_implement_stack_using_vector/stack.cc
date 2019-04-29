#include "stack.h"

#include <algorithm>
#include <stdexcept>

using std::string;
using std::out_of_range;

template <typename T>
void Stack<T>::push(T val) {
  vec_.push_back(val);
}

template <typename T>
T Stack<T>::pop() {
  if (vec_.size() == 0) {
    throw out_of_range("Stack out of range.");
  }

  T val = vec_.back();
  vec_.pop_back();
  return val;
}

template <typename T>
void Stack<T>::sort(bool incrementing) {
  if (incrementing) {
    std::sort(vec_.begin(), vec_.end());
  } else {
    std::sort(vec_.begin(), vec_.end(), std::greater<T>());
  }
}

template <typename T>
string Stack<T>::to_string() const {
  string s;
  for (size_t i = 0; i < vec_.size(); i++) {
    s += std::to_string(vec_[i]);
    s += (i != vec_.size() - 1) ? "->" : "";
  }
  return s;
}
