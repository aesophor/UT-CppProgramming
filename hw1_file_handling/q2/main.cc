#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char* args[]) {
  // The user should specify the filename in the command line argument.
  if (argc < 2) {
    cout << "usage: " << args[0] << " <filename>" << endl;
    return EXIT_FAILURE;
  }
  

  int vowel_count = 0;

  // Open the file, read it line by line, and count the vowels.
  ifstream file(args[1]);
  string line;
  while (std::getline(file, line)) {
    for (auto c : line) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vowel_count++;
      }
    }
  }
  file.close();

  cout << "This file has " << vowel_count << " vowels." << endl;
  return EXIT_SUCCESS;
}
