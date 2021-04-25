/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    void expandPalindrome(const string &s, int begin, int end,
                          int &ans_start, int &max_length) {
        size_t size = s.size();
        while (0 <= begin && end < size && s[begin] == s[end]) {
            begin--;
            end++;
        }
        begin++;
        end--;
        int len = end - begin + 1;
        if (len > max_length) {
            max_length = len;
            ans_start = begin;
        }
    }

    string longestPalindrome(string s) {
        size_t size = s.size();
        int max_length = 0;
        int ans_start = 0;
        if (size < 2) {
            return s;
        }

        for (int i = 0; i < size - 1; i++) {
            expandPalindrome(s, i, i, ans_start, max_length);     // odd
            expandPalindrome(s, i, i + 1, ans_start, max_length); // even
        }

        return s.substr(ans_start, max_length);
    }
};
// @lc code=end
