#include <algorithm>
#include <string>

using namespace std;

void expandPalindromeRecursive(const string &str, int &left, int &right) {
    if (left < 0 || right >= str.size()) {
        left++;
        right--;
        return;
    }

    if (str[left] != str[right]) {
        left++;
        right--;
        return;
    }

    left--;
    right++;
    expandPalindromeRecursive(str, left, right);
}

std::pair<int, int> expandtPalindromeOdd(const string &str, int pivot) {
    int left = pivot;
    int right = pivot;
    expandPalindromeRecursive(str, left, right);
    return std::make_pair(left, right);
}

std::pair<int, int> expandtPalindromeEven(const string &str, int left,
                                          int right) {
    if (str[left] == str[right]) {
        expandPalindromeRecursive(str, left, right);
        return std::make_pair(left, right);
    } else {
        return std::make_pair(0, 0);
    }
}

class Solution {
public:
    string longestPalindrome(string s) {
        std::pair<int, int> maxPair;
        for (int i = 1; i < s.size(); i++) {
            auto oddPair = expandtPalindromeOdd(s, i);
            auto evenPair = expandtPalindromeEven(s, i - 1, i);
            std::vector<std::pair<int, int>> pairs{maxPair, oddPair,
                                                   evenPair};
            maxPair = *std::max_element(
                pairs.begin(), pairs.end(),
                [](const std::pair<int, int> &lhs,
                   const std::pair<int, int> &rhs) -> bool {
                    int lhsSize = lhs.second - lhs.first + 1;
                    int rhsSize = rhs.second - rhs.first + 1;
                    return rhsSize > lhsSize;
                });
        }

        return s.substr(maxPair.first, maxPair.second - maxPair.first + 1);
    }
};

int main() {
    Solution solution;
    solution.longestPalindrome("babad");
    return 0;
}