#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string out;
        //      1  2  3
        // x    4  5  6
        // ------------
        //      6 12 18
        //   5 10 15  0
        // 4 8 12  0  0
        vector<int> sum(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                int res = x * y;
                sum[sum.size() - j - i - 2] += res;
            }
        }

        int carry = 0;
        stack<char> outStack;
        for (int i : sum) {
            outStack.push((i + carry) % 10 + '0');
            carry = (i + carry) / 10;
            cout << i << " ";
        }

        if (carry != 0) {
            outStack.push(carry + '0');
        }

        while (outStack.size() > 1 && outStack.top() == '0') {
            outStack.pop();
        }

        while (!outStack.empty()) {
            out.push_back(outStack.top());
            outStack.pop();
        }

        cout << endl << out << endl;
        return out;
    }
};

int main() {
    Solution solution;
    solution.multiply("123", "456");
    return 0;
}