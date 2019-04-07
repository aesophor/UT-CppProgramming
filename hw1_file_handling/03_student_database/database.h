#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "student.h"

class Database {
public:
  Database() = default;
  virtual ~Database() = default;

  void Add(const std::string& course_name);
  void Add(const Student& student);

  double GetAverage(int course_index) const;
  double GetHighest(int course_index) const;

  friend std::ostream& operator<< (std::ostream& os, const Database& db);
  friend std::istream& operator>> (std::istream& is, Database& db);

private:
  std::vector<std::string> courses_; // course names
  std::unordered_map<std::string, Student> students_; // random access :)
};

#endif
