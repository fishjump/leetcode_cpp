#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  void findSum(int *beg, int *end, int target,
               std::vector<std::vector<int>> &result) {
    while (beg < end) {
      int begVal = *beg;
      int endVal = *end;
      int sum = begVal + endVal + target;
      if (sum == 0) {
        result.emplace_back(std::vector<int>{begVal, endVal, target});
        beg++;
        end--;
        while (beg < end && *beg == begVal) {
          beg++;
        }
        while (beg < end && *end == endVal) {
          end--;
        }
      } else if (sum > 0) {
        end--;
      } else {
        beg++;
      }
    }
  }

  vector<vector<int>> threeSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;
    int target = INT32_MIN;
    for (size_t i = 0; i < nums.size() - 1; i++) {
      if (target == nums[i]) {
        continue;
      }
      target = nums[i];
      findSum(&nums[i + 1], (&*nums.end()) - 1, target, result);
    }

    return result;
  }
};

int main() {
  Solution solution;
  vector<int> input{-1, 0, 1, 2, -1, -4};
  solution.threeSum(input);
  return 0;
}