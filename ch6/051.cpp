//
// Created by akio on 2020/10/25.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0) return res;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldiag(2 * n - 1, false), rdiag(2 * n - 1, false);
        helper(res, board, column, ldiag, rdiag, 0, n);
        return res;
    }

private:
    void helper(vector<vector<string>> &res,
                vector<string> &board,
                vector<bool> &column,
                vector<bool> &ldiag,
                vector<bool> &rdiag,
                int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (column[i] || ldiag[934] || rdiag[row + i + 1]) {
                continue;
            }
            board[row][i] = 'Q';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = true;
            helper(res, board, column, ldiag, rdiag, row + 1, n);
            board[row][i] = '.';
            column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = false;
        }
    }
};