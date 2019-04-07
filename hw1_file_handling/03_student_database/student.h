#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

class Student {
 public:
  Student() = default;
  virtual ~Student() = default;

  static int score_count();
  static void set_score_count(int count);

  const std::string& name() const;
  const std::vector<int>& scores() const;
  
  friend std::ostream& operator<< (std::ostream& os, const Student& s);
  friend std::istream& operator>> (std::istream& is, Student& s);

 private:
  static int score_count_;

  std::string name_;
  std::vector<int> scores_;
};

#endif // STUDENT_H_
