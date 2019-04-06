#include "student.h"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::istream;
using std::ostream;


// Tell compiler the static class member Student::score_count exists.
int Student::score_count_ = 0;

Student::Student() {}

Student::~Student() {}


int Student::score_count() {
  return Student::score_count_;
}

void Student::set_score_count(int count) {
  Student::score_count_ = count;
}


const string& Student::name() const {
  return name_;
}

const vector<int>& Student::scores() const {
  return scores_;
}

ostream& operator<< (ostream& os, const Student& s) {
  // Write student name to ostream.
  os << s.name_ << "\t";

  // Write all scores to ostream.
  for (auto score : s.scores_) {
    os << score << "\t";
  }

  return os;
}

istream& operator>> (istream& is, Student& s) {
  if (&is == &cin) {
    cout << "Name: ";
  }
  is >> s.name_;

  for (int i = 0; i < Student::score_count_; i++) {
    if (&is == &cin) {
      cout << "Enter score (" << i + 1 << "/" << Student::score_count_ << "): ";
    }
    int score = 0;
    is >> score;
    s.scores_.push_back(score);
  }

  return is;
}
