#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    auto [lIter, rIter] = std::equal_range(nums.begin(), nums.end(), target);
    int left = lIter - nums.begin();
    int right = rIter - nums.begin(); // 半开区间 [left, right)
    if (left == right) {
      return {-1, -1};
    } else {
      return {left, right - 1};
    }
  }
};