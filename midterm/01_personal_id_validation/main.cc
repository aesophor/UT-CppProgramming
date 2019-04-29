#include <iostream>
#include <string>
#include <array>

using namespace std;

int ConvertFirstChar(char c) {
  switch (c) {
    case 'A':
      return 10;
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D':
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
    case 'G':
      return 16;
    case 'H':
      return 17;
    case 'J':
      return 18;
    case 'K':
      return 19;
    case 'L':
      return 20;
    case 'M':
      return 21;
    case 'N':
      return 22;
    case 'P':
      return 23;
    case 'Q':
      return 24;
    case 'R':
      return 25;
    case 'S':
      return 26;
    case 'T':
      return 27;
    case 'U':
      return 28;
    case 'V':
      return 29;
    case 'X':
      return 30;
    case 'Y':
      return 31;
    case 'W':
      return 32;
    case 'Z':
      return 33;
    case 'I':
      return 34;
    case 'O':
      return 35;
    default:
      break;
  }
  return 0;
}

int main() {
  string input;
  cout << "Please enter personal ID number: ";
  cin >> input;

  if (input.size() != 10) {
    cerr << "Input length should be 10 characters long!" << endl;
    return EXIT_FAILURE;
  }

  array<int, 11> weight = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1};
  array<int, 11> nums = {};

  int ch = ConvertFirstChar(toupper(input.front()));

  if (ch != 0) {
    nums[1] = (ch % 10) * weight[1];
    ch /= 10;
    nums[0] = (ch % 10) * weight[0];

    for (size_t i = 2; i < nums.size(); i++) {
      nums[i] = weight[i] * (input[i - 1] - '0');
    }

    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    cout << ((sum % 10 == 0) ? "Passed" : "Incorrect") << endl;
  } else {
    cout << "Incorrect" << endl;
  }

  return EXIT_SUCCESS;
}
