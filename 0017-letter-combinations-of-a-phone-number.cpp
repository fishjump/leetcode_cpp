#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::unordered_map<char, std::vector<std::string>>
            digitToLetterMap;
        digitToLetterMap['2'] = {"a", "b", "c"};
        digitToLetterMap['3'] = {"d", "e", "f"};
        digitToLetterMap['4'] = {"g", "h", "i"};
        digitToLetterMap['5'] = {"j", "k", "l"};
        digitToLetterMap['6'] = {"m", "n", "o"};
        digitToLetterMap['7'] = {"p", "q", "r", "s"};
        digitToLetterMap['8'] = {"t", "u", "v"};
        digitToLetterMap['9'] = {"w", "x", "y", "z"};

        std::vector<std::vector<std::string>> transformed{digits.size()};
        std::transform(digits.begin(), digits.end(), transformed.begin(),
                       [&](char ch) -> std::vector<std::string> {
                           return digitToLetterMap[ch];
                       });

        std::vector<std::string> result =
            std::reduce(transformed.begin(), transformed.end(),
                        std::vector<std::string>{},
                        [](const std::vector<std::string> &lhs,
                           const std::vector<std::string> &rhs)
                            -> std::vector<std::string> {
                            if (lhs.empty()) {
                                return rhs;
                            }

                            std::vector<std::string> result;
                            for (const auto &l : lhs) {
                                for (const auto &r : rhs) {
                                    result.push_back(l + r);
                                }
                            }

                            return result;
                        });

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> input{4, 0, 5, -5, 3, 3, 0, -4, -5};
    solution.letterCombinations("23");
    return 0;
}