#ifndef QUEUE_H_
#define QUEUE_H_

#include <deque>
#include <string>

template <typename T>
class Queue {
 public:
  Queue() = default;
  virtual ~Queue() = default;

  void push_front(T val);
  void push_back(T val);
  void pop_front();
  void pop_back();
  T front() const;
  T back() const;

  void sort(bool incrementing=true);
  std::string to_string() const;

 private:
  std::deque<T> dq_;
};

#endif // QUEUE_H_
