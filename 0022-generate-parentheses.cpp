#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(std::vector<string> &res, const std::string &pat, int left,
           int right) {
    if (left == 0 && right == 0) {
      res.push_back(pat);
      return;
    }

    if (right - 1 >= left) {
      dfs(res, pat + ")", left, right - 1);
    }
    if (left > 0) {
      dfs(res, pat + "(", left - 1, right);
    }
  }

  vector<string> generateParenthesis(int n) {
    std::vector<string> res;
    dfs(res, "", n, n);
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> input{4, 0, 5, -5, 3, 3, 0, -4, -5};
  solution.generateParenthesis(3);
  return 0;
}