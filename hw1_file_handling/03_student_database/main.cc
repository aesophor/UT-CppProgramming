#include <iostream>
#include <fstream>
#include <string>

#include "student.h"
#include "database.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

enum MenuOption {
  ADD_COURSE = 1,
  ADD_STUDENT,
  IMPORT,
  EXPORT
};


int main(int argc, char* args[]) {
  Database db;

  for (;;) {
    system("clear");
    cout << endl
      << "Student Database" << endl
      << "================" << endl
      << "(1) Add course" << endl
      << "(2) Add student" << endl
      << "(3) Import from..." << endl
      << "(4) Export to..." << endl << endl
      << db << endl;

    int option = 0;
    cin >> option;
    
    switch (option) {
      case MenuOption::ADD_COURSE: {
        cout << "Please enter the course name: ";
        string course_name;
        cin >> course_name;
        db.Add(course_name);
        break; }

      case MenuOption::ADD_STUDENT: {
        Student s;
        cin >> s;
        db.Add(s);
        break; }

      case MenuOption::IMPORT: {
        cout << "Please enter the filename: ";
        string filename;
        cin >> filename;
        ifstream infile(filename);
        infile >> db;
        break; }

      case MenuOption::EXPORT: {
        cout << "Please enter the filename: ";
        string filename;
        cin >> filename;
        ofstream outfile(filename);
        outfile << db;
        break; }

      default: {
        cout << "Error: No such option. Retry." << endl;
        break; }
    }
  }

  return EXIT_SUCCESS;
}
