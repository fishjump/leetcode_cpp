#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(const vector<int> &candidates, vector<int> currentBuild,
           int currentSum, int target, vector<vector<int>> &ctx) {
    for (int item : candidates) {
      if (currentBuild.size() > 0) {
        if (item < currentBuild.back()) {
          continue;
        }
      }
      if (currentSum + item > target) {
        return;
      }
      if (currentSum + item == target) {
        currentBuild.push_back(item);
        ctx.push_back(currentBuild);
        return;
      }
      currentBuild.push_back(item);
      dfs(candidates, currentBuild, currentSum + item, target, ctx);
      currentBuild.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> output;
    std::sort(candidates.begin(), candidates.end());
    vector<int> currentBuild;
    dfs(candidates, currentBuild, 0, target, output);
    return output;
  }
};

int main() {
  Solution solution;
  vector<int> input = {2, 3, 6, 7};
  solution.combinationSum(input, 7);
  return 0;
}