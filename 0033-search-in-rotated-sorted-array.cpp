#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int bsearch(const vector<int> &nums, int beg, int end, int target) {
    int mid = (beg + end) / 2;
    if (nums[mid] == target) {
      return mid;
    }

    if (beg == end) {
      return -1;
    }

    if (target < nums[mid]) {
      return bsearch(nums, beg, mid, target);
    } else {
      return bsearch(nums, mid + 1, end, target);
    }
  }

  int bsearchK(const vector<int> &nums, int beg, int end) {
    if (beg == end) {
      return -1;
    }

    int mid = (beg + end) / 2;
    if (nums[mid] > nums[mid + 1]) {
      return mid;
    }

    int ret = bsearchK(nums, beg, mid);
    if (ret != -1) {
      return ret;
    }

    return bsearchK(nums, mid + 1, end);
  }

  int search(vector<int> &nums, int target) {
    int k = bsearchK(nums, 0, nums.size() - 1);
    if (k == -1) {
      auto iter = std::find(nums.begin(), nums.end(), target);
      return iter != nums.end() ? iter - nums.begin() : -1;
    }

    int ret = bsearch(nums, 0, k, target);
    if (ret != -1) {
      return ret;
    }

    ret = bsearch(nums, k + 1, nums.size() - 1, target);
    return ret;
  }
};

int main() {
  Solution solution;
  vector<int> input{4, 5, 6, 7, 0, 1, 2};
  solution.search(input, 0);
  return 0;
}