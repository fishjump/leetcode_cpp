/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        std::vector<std::pair<int, string>> int_to_roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        std::stringstream ss;
        for (const auto &item : int_to_roman) {
            int count = num / item.first;
            num = num % item.first;
            for (int i = 0; i < count; i++) {
                ss << item.second;
            }
        }

        return ss.str();
    }
};
// @lc code=end
