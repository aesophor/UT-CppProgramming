#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <string>

template <typename T>
class Stack {
 public:
  Stack() = default;
  virtual ~Stack() = default;

  void push(T val);
  T pop();
  void sort(bool incrementing=true);
  std::string to_string() const;

 private:
  std::vector<T> vec_;
};

#endif // STACK_H_
