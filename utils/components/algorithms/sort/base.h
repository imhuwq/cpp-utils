#ifndef CPP_UTILS_ALGORITHM_SORT_BASE_H
#define CPP_UTILS_ALGORITHM_SORT_BASE_H

#include <vector>

using namespace std;

template<typename Num>
class SortBase {
 public:
  virtual void Sort(vector<Num> &nums)=0;
  virtual ~SortBase() = 0;

  bool IsSorted(const vector<Num> &nums) {
    for (int index = 0; index < nums.size() - 1; index++) {
      if (nums[index] > nums[index + 1]) return false;
    }
    return true;
  }

};

template<typename Num>
SortBase<Num>::~SortBase() = default;

#endif //CPP_UTILS_ALGORITHM_SORT_BASE_H
