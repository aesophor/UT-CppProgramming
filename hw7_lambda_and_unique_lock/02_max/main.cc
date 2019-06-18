#include <iostream>

using namespace std;

int main(int argc, char* args[]) {
  auto f = [=](int a, int b) -> int {
    return std::max(a, b);
  };

  cout << "Given two nums 5 and 7, the larger value is: "
    << f(5, 7) << endl;
}
