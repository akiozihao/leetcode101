//
// Created by akio on 2020/10/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions{{0,  1},
                                   {0,  -1},
                                   {1,  0},
                                   {-1, 0}};

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                int cnt = 0;
                helper(grid, i, j, cnt, res);
            }
        }
        return res;
    }

private:
    void helper(vector<vector<int>> &grid, int i, int j, int &cnt, int &res) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        res = max(res, ++cnt);
        grid[i][j] *= -1;
        for (auto dir:directions) {
            helper(grid, i + dir[0], j + dir[1], cnt, res);
        }
    }
};