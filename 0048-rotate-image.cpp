#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int up = 0;
        int down = matrix.size() - 1;
        while (up < down) {
            matrix[up].swap(matrix[down]);
            up++;
            down--;
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = matrix.size() - 1; j > i; j--) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};