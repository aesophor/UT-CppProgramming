#include "stack.cc"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
  Stack<int> s;

  // Test Stack<T>::push
  s.push(5);
  assert(s.to_string() == "5");
  s.push(8);
  assert(s.to_string() == "5->8");

  // Test Stack<T>::pop
  s.pop();
  assert(s.to_string() == "5");
  s.pop();
  assert(s.to_string() == "");


  s.push(5);
  s.push(8);
  s.push(1);
  s.push(9);
  s.push(3);

  cout << "Stack content: " << endl
    << s.to_string() << endl << endl;

  cout << "Sort stack in incrementing order." << endl;
  bool incrementing = true;
  s.sort(incrementing);
  assert(s.to_string() == "1->3->5->8->9");
  cout << s.to_string() << endl << endl;

  cout << "Sort stack in decrementing order." << endl;
  incrementing = false;
  s.sort(incrementing);
  assert(s.to_string() == "9->8->5->3->1");
  cout << s.to_string() << endl << endl;

  cout << "All test passed" << endl;
}
