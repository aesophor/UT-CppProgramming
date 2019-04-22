#include <iostream>

#include "linked_list.h"

using std::cout;
using std::endl;

int main() {
  LinkedList list;
  list.Insert(0, 3);
  cout << list << endl;
}
