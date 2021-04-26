/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() < 2) {
            return strs[0];
        }

        size_t max_common_prefix_length =
            std::min_element(strs.begin(), strs.end(),
                             [](const string &s1, const string &s2) {
                                 return s1.length() < s2.length();
                             })
                ->length();

        std::string res;
        for (int i = 0; i < max_common_prefix_length; i++) {
            char ch = strs[0][i];
            for (const auto &str : strs) {
                if (str[i] != ch) {
                    return res;
                }
            }
            res.push_back(ch);
        }

        return res;
    }
};
// @lc code=end
