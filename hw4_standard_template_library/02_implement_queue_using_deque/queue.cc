#include "queue.h"

#include <algorithm>

using std::string;

template <typename T>
void Queue<T>::push_front(T val) {
  dq_.push_front(val);
}

template <typename T>
void Queue<T>::push_back(T val) {
  dq_.push_back(val);
}

template <typename T>
void Queue<T>::pop_front() {
  dq_.pop_front();
}

template <typename T>
void Queue<T>::pop_back() {
  dq_.pop_back();
}


template <typename T>
T Queue<T>::front() const {
  return dq_.front();
}

template <typename T>
T Queue<T>::back() const {
  return dq_.back();
}

template <typename T>
void Queue<T>::sort(bool incrementing) {
  if (incrementing) {
    std::sort(dq_.begin(), dq_.end());
  } else {
    std::sort(dq_.begin(), dq_.end(), std::greater<T>());
  }
}

template <typename T>
string Queue<T>::to_string() const {
  string s;
  for (size_t i = 0; i < dq_.size(); i++) {
    s += std::to_string(dq_[i]);
    s += (i != dq_.size() - 1) ? "->" : "";
  }
  return s;
}
