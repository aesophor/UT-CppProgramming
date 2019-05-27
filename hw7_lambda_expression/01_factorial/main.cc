#include <iostream>

using namespace std;

int main(int argc, char* args[]) {
  // Calculate the factorial of 5.
  auto f = [=](int n) -> int {
    int result = 1;
    for (int i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
  };

  cout << "5! is: " << f(5) << endl;
}
