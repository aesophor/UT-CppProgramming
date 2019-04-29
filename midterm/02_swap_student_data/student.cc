#include "student.h"

using std::ostream;

Student::Student(int chi, int eng, int math) : chi_(chi), eng_(eng), math_(math) {}


int Student::chi() const {
  return chi_;
}

int Student::eng() const {
  return eng_;
}

int Student::math() const {
  return math_;
}


void Student::set_chi(int chi) {
  chi_ = chi;
}

void Student::set_eng(int eng) {
  eng_ = eng;
}

void Student::set_math(int math) {
  math_ = math;
}


ostream& operator<< (ostream& os, const Student& s) {
  return os << "chi: " << s.chi_
    << " eng: " << s.eng_
    << " math: " << s.math_;
}
