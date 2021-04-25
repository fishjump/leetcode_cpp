/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    inline char zigZagMap(const string &s, const int &loop_length,
                          const int &loop_index,
                          const int &loop_internal_index) {
        int index = loop_length * loop_index + loop_internal_index;
        if (index < s.size()) {
            return s[index];
        } else {
            return 0;
        }
    }

    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        int loop_length = numRows * 2 - 2;
        int half_loop_length = loop_length / 2;
        int loop_times =
            (s.size() / loop_length) + (s.size() % loop_length ? 1 : 0);

        for (int loop_index = 0; loop_index < loop_times; loop_index++) {
            if (char ch = zigZagMap(s, loop_length, loop_index, 0)) {
                res.push_back(ch);
            }
        }

        for (int loop_internal_index = 1;
             loop_internal_index < half_loop_length;
             loop_internal_index++) {
            for (int loop_index = 0; loop_index < loop_times;
                 loop_index++) {
                if (char ch = zigZagMap(s, loop_length, loop_index,
                                        loop_internal_index)) {
                    res.push_back(ch);
                }
                if (char ch =
                        zigZagMap(s, loop_length, loop_index,
                                  loop_length - loop_internal_index)) {
                    res.push_back(ch);
                }
            }
        }

        for (int loop_index = 0; loop_index < loop_times; loop_index++) {
            if (char ch = zigZagMap(s, loop_length, loop_index,
                                    half_loop_length)) {
                res.push_back(ch);
            }
        }

        return res;
    }
};
// @lc code=end
