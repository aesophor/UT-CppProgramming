#include "linked_list_map.h"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* args[]) {
  LinkedListMap m;

  m.Put(1, 60);
  cout << "Inserting (1,60): " << endl
    << m << endl;

  m.Put(2, 99);
  cout << "Inserting (2, 99): " << endl
    << m << endl;

  m.Put(3, 84);
  cout << "Inserting (3, 84): " << endl
    << m << endl;

  m.Remove(1);
  cout << "Removing 1: " << endl
    << m << endl;

  m.Remove(2);
  cout << "Removing 2:" << endl
    << m << endl;

  m.Remove(3);
  cout << "Removing 3: " << endl
    << m << endl;
}
