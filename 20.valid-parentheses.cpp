/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;

        for (const auto &ch : s) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    left.push(ch);
                    break;
                case ')':
                    if (left.empty() || left.top() != '(') {
                        return false;
                    }
                    left.pop();
                    break;
                case ']':
                    if (left.empty() || left.top() != '[') {
                        return false;
                    }
                    left.pop();
                    break;
                case '}':
                    if (left.empty() || left.top() != '{') {
                        return false;
                    }
                    left.pop();
                    break;
            }
        }

        return left.empty();
    }
};
// @lc code=end
