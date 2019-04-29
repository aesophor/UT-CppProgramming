#include "stack.cc"

#include <iostream>

using namespace std;

int main() {
  Stack<int> s;
  s.push(5);
  s.push(8);
  s.push(1);
  s.push(9);
  s.push(3);
  s.push(2);

  cout << "Stack content: " << endl
    << s.to_string() << endl << endl;

  cout << "Pop: " << s.pop() << endl << endl;

  cout << "Stack content: " << endl
    << s.to_string() << endl << endl;

  cout << "Sort stack in incrementing order." << endl;
  bool incrementing = true;
  s.sort(incrementing);
  cout << s.to_string() << endl << endl;

  cout << "Sort stack in decrementing order." << endl;
  incrementing = false;
  s.sort(incrementing);
  cout << s.to_string() << endl << endl;
}
