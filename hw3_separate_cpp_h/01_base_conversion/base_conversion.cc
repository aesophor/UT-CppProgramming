#include "base_conversion.h"

#include <stdexcept>
#include <algorithm>

using std::string;
using std::runtime_error;

namespace base_conversion {

string int2string(int num, uint8_t base) {
  if (base > 36) {
    throw runtime_error("base should be <= 36.");
  }

  static const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
  string result;

  while (num != 0) {
    result += alphabet[num % base];
    num /= base;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

} // namespace base_conversion
