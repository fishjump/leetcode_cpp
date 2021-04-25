/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start

#include <limits.h>

#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        size_t size = s.size();

        while (index < size && s[index] == ' ') {
            index++;
        }

        if (index >= size) {
            return 0;
        }

        bool postive = true;
        switch (s[index]) {
            case '-':
                postive = false;
            case '+':
                index++;
        }

        int start = index, end = index;
        while (end < size && '0' <= s[end] && s[end] <= '9') {
            end++;
        }
        if (start == end) {
            return 0;
        }

        int64_t res = 0;
        if (postive) {
            res = s[start] - '0';
            for (int i = start + 1; i < end; i++) {
                res = res * 10 + s[i] - '0';
                if (res > INT_MAX) {
                    return INT_MAX;
                }
            }
        } else {
            res = -s[start] + '0';
            for (int i = start + 1; i < end; i++) {
                res = res * 10 - s[i] + '0';
                if (res < INT_MIN) {
                    return INT_MIN;
                }
            }
        }

        return (int)res;
    }
};
// @lc code=end
