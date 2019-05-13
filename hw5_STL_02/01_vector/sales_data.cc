#include "sales_data.h"

using std::endl;
using std::ostream;
using std::string;
using std::vector;

SalesData::SalesData() {
  // Create a 3x4 2d-vector
  scores_.reserve(3);
  scores_[0].reserve(4);
  scores_[1].reserve(4);
  scores_[2].reserve(4);
}

void SalesData::Sort(vector<int>& nums) {
  for (int i = 1; i < (int) nums.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (nums[j] < nums[j+1]) {
        std::swap(nums[j], nums[j+1]);
      }
    }
  }
}

void SalesData::Add(int s1, int s2, int s3, int s4) {
  scores_.push_back({s1, s2, s3, s4});
}

int SalesData::GetTotalScores(int person) const {
  int sum = 0;
  for (size_t i = 0; i < scores_.at(person).size(); i++) {
    sum += scores_.at(person).at(i);
  }
  return sum;
}

ostream& operator<< (ostream& os, const SalesData& data) {
  for (size_t i = 0; i < data.scores_.size(); i++) {
    os << "Sales" << std::to_string(i) << ": ";
    auto& current = data.scores_[i];
    for (size_t j = 0; j < current.size(); j++) {
      os << std::to_string(current[j]) << " ";
    }
    os << "(total: " << data.GetTotalScores(i) << ")" << endl;
  }
  return os;
}
