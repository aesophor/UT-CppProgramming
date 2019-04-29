#include <iostream>

#include "student.h"

using std::cout;
using std::endl;

void swap(Student& s1, Student& s2) {
  // Swap chi
  int s1_chi = s1.chi();
  int s2_chi = s2.chi();
  s1.set_chi(s2_chi);
  s2.set_chi(s1_chi);
  
  // Swap eng
  int s1_eng = s1.eng();
  int s2_eng = s2.eng();
  s1.set_eng(s2_eng);
  s2.set_eng(s1_eng);
 
  // Swap math
  int s1_math = s1.math();
  int s2_math = s2.math();
  s1.set_math(s2_math);
  s2.set_math(s1_math);
}

int main() {
  Student s1(85, 90, 66);
  Student s2(100, 99, 99);

  cout << "Before swap: " << endl
    << "[s1] " << s1 << endl
    << "[s2] " << s2 << endl << endl;

  swap(s1, s2);

  cout << "After swap: " << endl
    << "[s1] " << s1 << endl
    << "[s2] " << s2 << endl;
  
  return EXIT_SUCCESS;
}
