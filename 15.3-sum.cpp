/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3) {
            return {};
        }

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> solutions;
        size_t size = nums.size();
        for (int pivot = 0; pivot < size; pivot++) {
            if (pivot > 0 && nums[pivot] == nums[pivot - 1]) {
                continue;
            }
            int left = pivot + 1, right = size - 1;
            while (left < right) {
                int sum = nums[pivot] + nums[left] + nums[right];
                if (sum == 0) {
                    solutions.push_back(
                        {nums[pivot], nums[left], nums[right]});
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                    do {
                        right--;
                    } while (left < right
                             && nums[right] == nums[right + 1]);
                    continue;
                }
                if (sum > 0) {
                    right--;
                    continue;
                }
                if (sum < 0) {
                    left++;
                    continue;
                }
            }
        }

        return solutions;
    }
};
// @lc code=end
