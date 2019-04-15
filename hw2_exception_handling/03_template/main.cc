#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

// Four overloaded functions
short times(short num1, short num2) {
  return num1 * num2;
}

int times(int num1, int num2) {
  return num1 * num2;
}

float times(float num1, float num2) {
  return num1 * num2;
}

double times(double num1, double num2) {
  return num1 * num2;
}


// Template version
template <typename T>
T times(T num1, T num2) {
  return num1 * num2;
}

template <typename T1, typename T2>
T1 times(T1 num1, T2 num2) {
  return num1 * num2;
}


int main() {
  assert((times<int>(5, 5)) == 25);
  assert((times<int>(10, 20)) == 200);

  assert((times<double, int>(.5, 3)) == 1.5);
  assert((times<double, int>(.0, 0)) == 0.0);
  assert((times<double, int>(.999, 999)) == 998.001);
}
