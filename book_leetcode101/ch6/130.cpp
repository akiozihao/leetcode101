//
// Created by akio on 2020/10/27.
//
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()||board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0, 'O', '*');
            dfs(board, i, n - 1, 'O', '*');
        }
        for (int j = 0; j < n; ++j) {
            dfs(board, 0, j, 'O', '*');
            dfs(board, m - 1, j, 'O', '*');
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board,i,j,'O','X');
            }
        }
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0, '*', 'O');
            dfs(board, i, n - 1, '*', 'O');
        }
        for (int j = 0; j < n; ++j) {
            dfs(board, 0, j, '*', 'O');
            dfs(board, m - 1, j, '*', 'O');
        }
    }

private:
    void dfs(vector<vector<char>> &board, int i, int j, char f, char c
    ) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != f) return;
        board[i][j] = c;
        dfs(board, i - 1, j, f, c);
        dfs(board, i + 1, j, f, c);
        dfs(board, i, j - 1, f, c);
        dfs(board, i, j + 1, f, c);
    }
};