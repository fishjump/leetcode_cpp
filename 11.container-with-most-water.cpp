/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1, max_area = 0;
        while (left < right) {
            int height_left = height[left], height_right = height[right];
            if (height_left < height_right) {
                max_area =
                    std::max(max_area, (right - left) * height_left);
                left++;
            } else {
                max_area =
                    std::max(max_area, (right - left) * height_right);
                right--;
            }
        }
        return max_area;
    }
};
// @lc code=end
