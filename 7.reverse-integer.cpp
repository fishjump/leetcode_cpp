/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start

#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        if (INT_MIN == x) {
            return 0;
        }

        bool negative = x < 0;
        if (negative) {
            x = -x;
        }

        int res = 0;
        while (x) {
            if ((res > INT_MAX / 10)
                || (res == INT_MAX / 10 && x % 10 > INT_MAX % 10)) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }

        return negative ? -res : res;
    }
};
// @lc code=end
