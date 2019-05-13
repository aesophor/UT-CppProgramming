#include "queue.cc"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
  Queue<int> q;

  // Test Queue<T>::push_back
  q.push_back(5);
  assert(q.to_string() == "5");

  // Test Queue<T>::push_front
  q.push_front(8);
  assert(q.to_string() == "8->5");

  // Test Queue<T>::pop_back
  q.pop_back();
  assert(q.to_string() == "8");

  // Test Queue<T>::pop_front
  q.pop_front();
  assert(q.to_string() == "");



  q.push_back(8);
  cout << q.to_string() << endl;

  q.push_back(5);
  cout << q.to_string() << endl;
  
  q.push_back(2);
  cout << q.to_string() << endl;

  q.push_back(4);
  cout << q.to_string() << endl;

  q.push_back(7);
  cout << q.to_string() << endl << endl;

  cout << "Sort queue in incrementing order: " << endl;
  bool incrementing = true;
  q.sort(incrementing);
  assert(q.to_string() == "2->4->5->7->8");
  cout << q.to_string() << endl << endl;

  cout << "Sort queue in decrementing order: " << endl;
  incrementing = false;
  q.sort(incrementing);
  assert(q.to_string() == "8->7->5->4->2");
  cout << q.to_string() << endl << endl;

  cout << "All test passed" << endl;
}
