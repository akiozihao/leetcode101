//
// Created by akio on 2020/10/19.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs{{-1, 0},
                             {1,  0},
                             {0,  1},
                             {0,  -1}};

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    queue<pair<int, int>> q{{{i, j}}};
                    grid[i][j] *= -1;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        res = max(res, ++cnt);
                        for (auto dir:dirs) {
                            int x = t.first + dir[0], y = t.second + dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
                            q.push({x, y});
                            grid[x][y] *= -1;
                        }
                    }

                }
            }
        }
        return res;
    }
};