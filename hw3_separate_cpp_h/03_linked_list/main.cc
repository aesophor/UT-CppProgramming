#include <iostream>

#include "linked_list.h"

using std::cout;
using std::endl;

int main() {
  LinkedList list;

  list.Insert(0, 3);
  cout << list << endl;

  list.Insert(1, 5);
  cout << list << endl;

  list.Insert(2, 6);
  cout << list << endl;

  list.Insert(0, 1);
  cout << list << endl;

  list.Insert(1, 4);
  cout << list << endl;

  list.Insert(list.size(), 8);
  cout << list << endl;
}
