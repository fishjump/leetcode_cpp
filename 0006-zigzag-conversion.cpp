#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int state = 0;
    int numRows = 0;
    int direction = 0; // 0: top2bottom, 1:bottom2top

    int nextState() {
        if (numRows == 1) {
            return 0;
        }

        int ret = state;
        if (direction == 0) {
            state++;
            if (state == (numRows - 1)) {
                direction = 1;
            }
        } else {
            state--;
            if (state == 0) {
                direction = 0;
            }
        }
        return ret;
    }

    string convert(string s, int numRows) {
        this->numRows = numRows;
        auto arr = std::vector<std::vector<char>>(numRows);
        for (char ch : s) {
            arr[this->nextState()].emplace_back(ch);
        }

        std::string ret;
        for (const auto &vec : arr) {
            for (char ch : vec) {
                ret.push_back(ch);
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    solution.convert("AB", 1);
    return 0;
}