#include <stdint.h>

#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    static bool pairLt(const std::pair<int, int> &lhs,
                       const std::pair<int, int> &rhs) {
        return std::abs(lhs.first) < std::abs(rhs.first);
    }

    std::pair<int, int> findClosestSum(int *beg, int *end, int fixed,
                                       int target) {
        std::pair<int, int> minPair{INT32_MAX, INT32_MAX};
        while (beg < end) {
            int begVal = *beg;
            int endVal = *end;
            int sum = begVal + endVal + fixed;
            int diff = sum - target;
            if (diff == 0) {
                return {0, sum};
            } else if (diff > 0) {
                end--;
            } else {
                beg++;
            }

            minPair = std::min(minPair, {diff, sum}, pairLt);
        }

        return minPair;
    }

    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int fixed = INT32_MIN;
        std::pair<int, int> minPair{INT32_MAX, INT32_MAX};
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (fixed == nums[i]) {
                continue;
            }
            fixed = nums[i];

            auto pair = findClosestSum(&nums[i + 1], (&*nums.end()) - 1,
                                       fixed, target);
            minPair = std::min(minPair, pair, pairLt);
            if (minPair.first == 0) {
                return minPair.second;
            }
        }

        return minPair.second;
    }
};

int main() {
    Solution solution;
    vector<int> input{4, 0, 5, -5, 3, 3, 0, -4, -5};
    solution.threeSumClosest(input, -2);
    return 0;
}