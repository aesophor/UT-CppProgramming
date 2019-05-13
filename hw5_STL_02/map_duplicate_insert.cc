#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> m;

  m[3] = 3;
  cout << "m[3]:" << m[3] << endl;

  m[3] = 5; // 直接覆寫原value
  cout << "m[3]:" << m[3] << endl;
}
