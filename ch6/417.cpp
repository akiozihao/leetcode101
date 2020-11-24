//
// Created by akio on 2020/10/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs{{-1, 0},
                             {0,  1},
                             {1,  0},
                             {0,  -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> canlt(m, vector<bool>(n, false));
        vector<vector<bool>> canrd(m, vector<bool>(n, false));
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            dfs(matrix, canlt, i, 0);
            dfs(matrix, canrd, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(matrix, canlt, 0, j);
            dfs(matrix, canrd, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (canlt[i][j] && canrd[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &can_reach, int r, int c) {
        if (can_reach[r][c]) return;
        can_reach[r][c] = true;
        int m = can_reach.size(), n = can_reach[0].size();
        int x, y;
        for (auto dir:dirs) {
            x = r + dir[0], y = c + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] < matrix[r][c]) continue;
            dfs(matrix, can_reach, x, y);
        }
    }
};