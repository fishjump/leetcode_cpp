/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0, begin = 0;
        std::unordered_map<char, int> char_index_map;
        for (int i = 0; i < s.size(); i++) {
            auto iter = char_index_map.find(s[i]);
            if (iter != char_index_map.end()) {
                begin = std::max(begin, iter->second + 1);
            }
            char_index_map[s[i]] = i;
            max_length = std::max(max_length, i - begin + 1);
        }

        return max_length;
    }
};
// @lc code=end
