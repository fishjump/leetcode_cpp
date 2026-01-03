#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int greedy(const vector<int> &nums) {
        int lowB = 0;
        int upB = nums[0];
        int target = nums.size() - 1;
        int count = 1;
        while (upB < target) {
            int newLowB = lowB;
            int newUpB = upB;
            for (int i = lowB + 1; i <= upB; i++) {
                int jump = nums[i];
                int curUpB = i + jump;
                if (curUpB > newUpB) {
                    newUpB = curUpB;
                    newLowB = i;
                }
            }
            upB = newUpB;
            lowB = newLowB;
            count++;
        }

        return count;
    }

    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        return greedy(nums);
    }
};

int main() {
    Solution solution;
    // vector<int> input{1, 2};
    vector<int> input{1};
    cout << solution.jump(input) << endl;
    return 0;
}