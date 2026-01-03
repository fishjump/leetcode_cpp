#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRowValid(vector<vector<char>> &board, int row) {
        map<char, int> hash;
        for (int i = 0; i < 9; i++) {
            char ch = board[row][i];
            auto iter = hash.find(ch);
            if (iter == hash.end()) {
                hash[ch] = 1;
            } else {
                iter->second++;
            }

            if (ch != '.' && hash[ch] > 1) {
                return false;
            }
        }

        return true;
    }

    bool isColValid(vector<vector<char>> &board, int col) {
        map<char, int> hash;
        for (int i = 0; i < 9; i++) {
            char ch = board[i][col];
            auto iter = hash.find(ch);
            if (iter == hash.end()) {
                hash[ch] = 1;
            } else {
                iter->second++;
            }

            if (ch != '.' && hash[ch] > 1) {
                return false;
            }
        }

        return true;
    }

    bool isRectValid(vector<vector<char>> &board, int row, int col) {
        int rectI = row / 3;
        int rectJ = col / 3;
        map<char, int> hash;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char ch = board[i + 3 * rectI][j + 3 * rectJ];
                auto iter = hash.find(ch);
                if (iter == hash.end()) {
                    hash[ch] = 1;
                } else {
                    iter->second++;
                }

                if (ch != '.' && hash[ch] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isStepValid(vector<vector<char>> &board, int row, int col,
                     char val) {
        board[row][col] = val;
        if (isRowValid(board, row) && isColValid(board, col)
            && isRectValid(board, row, col)) {
            return true;
        }
        return false;
    }

    bool isStepValid(vector<vector<char>> &board, int row, int col) {
        return isRowValid(board, row) && isColValid(board, col)
               && isRectValid(board, row, col);
    }

    bool dfs(vector<vector<char>> &board, int row, int col) {
        cout << "row:" << row << ", col:" << col << endl;
        if (row == 8 && col == 8) {
            if (board[row][col] != '.') {
                return true;
            }

            for (char ch = '1'; ch <= '9'; ch++) {
                if (isStepValid(board, row, col, ch)) {
                    return true;
                }
            }
            return false;
        }

        if (board[row][col] != '.') {
            int colNext = (col + 1) % 9;
            int rowNext = row + (col + 1) / 9;
            return dfs(board, rowNext, colNext);
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            if (isStepValid(board, row, col, ch)) {
                int colNext = (col + 1) % 9;
                int rowNext = row + (col + 1) / 9;
                if (dfs(board, rowNext, colNext)) {
                    return true;
                }
            }
            board[row][col] = '.';
        }

        return false;
    }

    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isStepValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
        {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
    cout << (solution.isValidSudoku(board) ? "true" : "false") << endl;
    return 0;
}