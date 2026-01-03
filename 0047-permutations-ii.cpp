#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> out;

        do {
            out.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return out;
    }
};