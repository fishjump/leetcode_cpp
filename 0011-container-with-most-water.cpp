#include <vector>

using namespace std;

class Solution {
public:
    int calcArea(const vector<int> &height, int left, int right) {
        int min = std::min(height[left], height[right]);
        return min * (right - left);
    }

    int maxArea(vector<int> &height) {
        int max = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int area = calcArea(height, left, right);
            if (area > max) {
                max = area;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max;
    }
};

int main() {
    Solution solution;
    vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};
    solution.maxArea(input);
    return 0;
}