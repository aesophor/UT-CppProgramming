#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main(int argc, char* args[]) {
  const string kInputFilename1 = "aaa.txt";
  const string kInputFilename2 = "bbb.txt";
  const string kOutputFilename = "ccc.txt";

  // Open ccc.txt
  ofstream output_file(kOutputFilename);
  ifstream input_file(kInputFilename1);
  string line;

  if (!output_file.is_open()) {
    cerr << "Unable to open " << kOutputFilename << endl;
    return EXIT_FAILURE;
  } else if (!input_file.is_open()) {
    cerr << "Unable to open " << kInputFilename1 << endl;
    return EXIT_FAILURE;
  }

  // Open aaa.txt and append its content into ccc.txt
  while (std::getline(input_file, line)) {
    output_file << line << endl;
  }
  input_file.close();

  // Open bbb.txt and append its content into ccc.txt.
  input_file = ifstream(kInputFilename2);

  if (!input_file.is_open()) {
    cerr << "Unable to open " << kInputFilename2 << endl;
    return EXIT_FAILURE;
  }

  while (std::getline(input_file, line)) {
    output_file << line << endl;
  }
  input_file.close();

  output_file.close();

  cout << "Files merged successfully. See " << kOutputFilename << endl;
  return EXIT_SUCCESS;
}
