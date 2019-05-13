#ifndef SALES_DATA_H_
#define SALES_DATA_H_

#include <iostream>
#include <vector>
#include <string>

class SalesData {
 public:
  SalesData();
  virtual ~SalesData() = default;

  // 1. Sort a vector in descending order.
  static void Sort(std::vector<int>& nums);

  // 2. 3x4 2d-vector
  void Add(int s1, int s2, int s3, int s4);
  int GetTotalScores(int person) const;

  friend std::ostream& operator<< (std::ostream& os, const SalesData& data);

 private:
  std::vector<std::vector<int> > scores_;
};

#endif // SALES_DATA_H_
