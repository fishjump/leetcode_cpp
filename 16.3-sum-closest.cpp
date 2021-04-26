/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start

#include <limits.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;
        int res = 0;
        size_t size = nums.size();
        for (int pivot = 0; pivot < size; pivot++) {
            if (pivot > 0 && nums[pivot] == nums[pivot - 1]) {
                continue;
            }
            int left = pivot + 1, right = size - 1;
            while (left < right) {
                int sum = nums[pivot] + nums[left] + nums[right];
                int diff = sum - target, abs_diff = std::abs(diff);

                if (diff == 0) {
                    return sum;
                }

                if (abs_diff < min_diff) {
                    min_diff = abs_diff;
                    res = sum;
                }

                if (diff > 0) {
                    right--;
                    continue;
                }

                if (diff < 0) {
                    left++;
                    continue;
                }
            }
        }
        return res;
    }
};
// @lc code=end
