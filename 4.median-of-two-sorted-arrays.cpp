/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int size_nums1 = nums1.size(), size_nums2 = nums2.size();
        int total_size = size_nums1 + size_nums2;
        int left_mid_index = 0, right_mid_index = 0;
        if (total_size % 2) {
            left_mid_index = right_mid_index = total_size / 2;
        } else {
            right_mid_index = total_size / 2;
            left_mid_index = right_mid_index - 1;
        }

        int index_nums1 = 0, index_nums2 = 0, i = 0;
        bool inc_num1 = true;
        double res = 0;
        while (index_nums1 < size_nums1 || index_nums2 < size_nums2) {
            if (index_nums1 >= size_nums1) {
                inc_num1 = false;
            } else if (index_nums2 >= size_nums2) {
                inc_num1 = true;
            } else {
                if (nums1[index_nums1] < nums2[index_nums2]) {
                    inc_num1 = true;
                } else {
                    inc_num1 = false;
                }
            }
            if (i == left_mid_index) {
                res += inc_num1 ? nums1[index_nums1] : nums2[index_nums2];
            } else if (i == right_mid_index) {
                res += inc_num1 ? nums1[index_nums1] : nums2[index_nums2];
                res /= 2;
                break;
            }
            if (inc_num1) {
                index_nums1++;
            } else {
                index_nums2++;
            }
            i++;
        }

        return res;
    }
};
// @lc code=end
