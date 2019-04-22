#include <iostream>
#include <string>

#include "base_conversion.h"

using std::cout;
using std::endl;
using std::string;
using base_conversion::int2string;

int main() {
  cout << "Decimal 388 to base2: " << int2string(388, 2) << endl;
  cout << "Decimal 388 to base8: " << int2string(388, 8) << endl;
  cout << "Decimal 388 to base16: " << int2string(388, 16) << endl;
}
