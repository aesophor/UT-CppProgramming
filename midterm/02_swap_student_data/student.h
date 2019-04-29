#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

class Student {
 public:
  Student(int chi, int eng, int math);
  virtual ~Student() = default;

  int chi() const;
  int eng() const;
  int math() const;
  void set_chi(int chi);
  void set_eng(int eng);
  void set_math(int math);

  friend std::ostream& operator<< (std::ostream& os, const Student& s);

 private:
  int chi_; // chinese score
  int eng_; // english score
  int math_; // math score
};

#endif // STUDENT_H_
