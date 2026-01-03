#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(const vector<int> &candidates, vector<int> currentBuild,
             int currentSum, int startIdx, int target,
             vector<vector<int>> &ctx) {
        for (int i = startIdx; i < candidates.size(); i++) {
            if (i > 1 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            int item = candidates[i];
            if (currentSum + item > target) {
                return;
            }
            if (currentSum + item == target) {
                currentBuild.push_back(item);
                ctx.push_back(currentBuild);
                return;
            }
            currentBuild.push_back(item);
            dfs(candidates, currentBuild, currentSum + item, i + 1, target,
                ctx);
            currentBuild.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates,
                                        int target) {
        vector<vector<int>> ctx;
        std::sort(candidates.begin(), candidates.end());
        vector<int> currentBuild;
        dfs(candidates, currentBuild, 0, 0, target, ctx);
        // vector<vector<int>> output;
        // for (auto vec : ctx) {
        //   output.push_back(std::move(vec));
        // }
        return ctx;
    }
};

int main() {
    Solution solution;
    vector<int> input = {10, 1, 2, 7, 6, 1, 5};
    solution.combinationSum2(input, 8);
    return 0;
}