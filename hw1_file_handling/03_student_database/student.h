#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

class Student {
public:
  Student();
  virtual ~Student();

  const std::string& name() const;
  const std::vector<int> scores() const;

  static int score_count;

  friend std::ostream& operator<< (std::ostream& os, const Student& s);
  friend std::istream& operator>> (std::istream& is, Student& s);

private:
  std::string name_;
  std::vector<int> scores_;
};

#endif
