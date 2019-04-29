#include "queue.cc"

#include <iostream>

using namespace std;

int main() {
  Queue<int> q;
  cout << q.to_string() << endl << endl;

  q.push_back(8);
  cout << q.to_string() << endl << endl;

  q.push_back(5);
  cout << q.to_string() << endl << endl;
  
  q.push_back(2);
  cout << q.to_string() << endl << endl;

  q.push_back(4);
  cout << q.to_string() << endl << endl;

  q.push_back(7);
  cout << q.to_string() << endl << endl;

  cout << "Sort queue in incrementing order: " << endl;
  bool incrementing = true;
  q.sort(incrementing);
  cout << q.to_string() << endl << endl;

  cout << "Sort queue in decrementing order: " << endl;
  incrementing = false;
  q.sort(incrementing);
  cout << q.to_string() << endl << endl;
}
