//
// Created by akio on 2021/2/8.
//
#include <vector>

using namespace std;
vector<vector<int>> dirs{
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
};

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = countLive(board, i, j);
                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3) board[i][j] = 3;
                } else {
                    if (cnt == 3) board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) board[i][j] = 1;
                if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }

private:
    // 0-->1 2
    // 1-->0 3
    int countLive(const vector<vector<int>> &board, int i, int j) {
        int x, y;
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for (auto dir:dirs) {
            x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (board[x][y] == 1 || board[x][y] == 3) ++cnt;
            }
        }
        return cnt;
    }
};