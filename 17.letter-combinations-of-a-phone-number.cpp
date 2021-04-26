/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<string> set_mul(const std::vector<string> &v1,
                                const std::vector<string> &v2) {
        if (v1.empty()) {
            return v2;
        }

        std::vector<string> result;
        for (const auto &val1 : v1) {
            for (const auto &val2 : v2) {
                result.push_back(val1 + val2);
            }
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        std::vector<string> key_map[] = {
            {"a", "b", "c"}, {"d", "e", "f"},     {"g", "h", "i"},
            {"j", "k", "l"}, {"m", "n", "o"},     {"p", "q", "r", "s"},
            {"t", "u", "v"}, {"w", "x", "y", "z"}};

        std::vector<string> result;
        for (const auto &ch : digits) {
            result = set_mul(result, key_map[ch - '2']);
        }

        return result;
    }
};
// @lc code=end
