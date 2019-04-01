#include "database.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

Database::Database() {}

Database::~Database() {}


void Database::Add(const std::string& course_name) {
  courses_.push_back(course_name);
  Student::score_count++;
}

void Database::Add(const Student& student) {
  students_[student.name()] = student;
}


ostream& operator<< (ostream& os, const Database& db) {
  // If we're writing to a file, write the number of courses first.
  if (&os != &cout) {
    os << db.courses_.size() << " ";
  }

  // Print course names.
  for (auto& name : db.courses_) {
    os << name << " ";
  }
  os << endl;


  // If we're writing to a file, write the number of students first.
  if (&os != &cout) {
    os << db.students_.size() << endl;
  }

  for (auto& record : db.students_) {
    os << record.second << endl; // student object
  }

  return os;
}

istream& operator>> (istream& is, Database& db) {
  // I don't overload the >> operator for cin,
  // user can only use >> for constructing db from ifstream.
  if (&is == &cin) {
    return is;
  }

  // If we are reading from a file stream, then
  // read the number of course names first.
  is >> Student::score_count;

  // Read all course names into our vector.
  for (int i = 0; i < Student::score_count; i++) {
    string course_name;
    is >> course_name;
    db.courses_.push_back(course_name);
  }

  // Reconstruct student objects from the input file,
  // and put them back to the hash table.
  int student_count = 0;
  is >> student_count;
  for (int i = 0; i < student_count; i++) {
    Student student;
    is >> student;
    db.students_[student.name()] = student;
  }

  return is;
}
