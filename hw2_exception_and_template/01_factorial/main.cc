#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::runtime_error;

int fact(int n) {
  if (n < 0) {
    throw runtime_error("argument out of bound");
  } 

  // Dynamic programming (bottom up)
  // 0 1 2 3 4 5
  int memo[n + 1];
  memo[0] = 1;

  for (int i = 1; i <= n; i++) {
    if (memo[i - 1] > INT_MAX / i) {
      throw runtime_error("number too large");
    }
    memo[i] = memo[i - 1] * i;
  }

  return memo[n];
}


int main() {
  cout << "Calculate factorial of n: ";

  int input = 0;
  cin >> input;

  try {
    cout << fact(input) << endl;
  } catch (const exception& ex) {
    cout << ex.what() << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
