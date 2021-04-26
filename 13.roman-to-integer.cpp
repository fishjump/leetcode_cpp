/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0, size = s.length();
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case 'M':
                    result += 1000;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'C':
                    if (i + 1 < size) {
                        if (s[i + 1] == 'M') {
                            result += 900;
                            i++;
                        } else if (s[i + 1] == 'D') {
                            result += 400;
                            i++;
                        } else {
                            result += 100;
                        }
                    } else {
                        result += 100;
                    }
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'X':
                    if (i + 1 < size) {
                        if (s[i + 1] == 'C') {
                            result += 90;
                            i++;
                        } else if (s[i + 1] == 'L') {
                            result += 40;
                            i++;
                        } else {
                            result += 10;
                        }
                    } else {
                        result += 10;
                    }
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'I':
                    if (i + 1 < size) {
                        if (s[i + 1] == 'X') {
                            result += 9;
                            i++;
                        } else if (s[i + 1] == 'V') {
                            result += 4;
                            i++;
                        } else {
                            result += 1;
                        }
                    } else {
                        result += 1;
                    }
                    break;
            }
        }

        return result;
    }
};
// @lc code=end
