#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};