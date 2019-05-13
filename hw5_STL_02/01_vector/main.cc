#include <iostream>
#include <vector>

#include "sales_data.h"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char* args[]) {
  SalesData data;
  data.Add(80, 85, 66, 64);
  data.Add(99, 91, 95, 92);
  data.Add(55, 12, 74, 32);

  cout << data << endl;

  // Sort and print total scores.
  vector<int> total_scores(3);
  total_scores[0] = data.GetTotalScores(0);
  total_scores[1] = data.GetTotalScores(1);
  total_scores[2] = data.GetTotalScores(2);
  SalesData::Sort(total_scores);

  cout << "Total score: ";
  for (auto score : total_scores) {
    cout << score << " ";
  }
  cout << endl;
}
