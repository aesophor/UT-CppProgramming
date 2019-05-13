#include "linked_list_map.h"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* args[]) {
  LinkedListMap m;
  m.Put(1, 60);
  cout << m << endl;

  m.Put(2, 99);
  cout << m << endl;

  m.Put(3, 84);
  cout << m << endl;

  m.Remove(1);
  cout << m << endl;

  m.Remove(2);
  cout << m << endl;

  m.Remove(3);
  cout << m << endl;
}
