//
// Created by akio on 2021/2/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        vector<vector<int>> dirs{
                {-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}
        };
        if (isWater.empty() || isWater[0].empty()) return {};
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto[xx, yy, hh] = q.front();
            q.pop();
            for (auto dir:dirs) {
                int nx = xx + dir[0], ny = yy + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                res[nx][ny] = hh + 1;
                q.push({nx, ny, hh + 1});
            }
        }
        return res;
    }
};