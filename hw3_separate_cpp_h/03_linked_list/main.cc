#include <iostream>

#include "linked_list.h"

using std::cout;
using std::endl;

int main() {
  LinkedList list;
  list.Insert(0, 3);
  list.Insert(1, 5);
  list.Insert(2, 6);
  list.Insert(0, 1);
  list.Insert(1, 4);
  list.Insert(list.size(), 8);

  cout << list << endl;
}
