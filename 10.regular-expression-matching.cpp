/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        size_t s_length = s.size(), p_length = p.size();
        vector<vector<bool>> dp(s_length + 1,
                                vector<bool>(p_length + 1, false));
        /*
         *  dp[i][j] = dp[i-1][j-1] when p[i-1] == s[j-1] || p[j-1] == '.'
         *  dp[i][j] = dp[i][j-2]   when p[j-1] == '*' (* repeat 0 time.)
         *  dp[i][j] = dp[i-1][j]   when p[j-1] == '*' && p[j-2] == '.' ||
         * p[j-2]==s[i-1]
         */
        dp[0][0] = true;
        for (int i = 0; i <= s_length; i++) {
            for (int j = 1; j <= p_length; j++) {
                if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1])) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (i > 0
                        && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[s_length][p_length];
    }
};
// @lc code=end
