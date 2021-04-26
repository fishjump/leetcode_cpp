/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        size_t size = nums.size();

        if (size < 4) {
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> solutions;
        int pivot_sum = 0;
        for (int i = 0; i < size - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = size - 1;
                while (left < right) {

                    int sum = nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum > target) {
                        right--;
                        continue;
                    }

                    if (sum < target) {
                        left++;
                        continue;
                    }

                    solutions.push_back(
                        {nums[i], nums[j], nums[left], nums[right]});
                    do {
                        right--;
                    } while (left < right
                             && nums[right] == nums[right + 1]);
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                }
            }
        }

        return solutions;
    }
};
// @lc code=end
