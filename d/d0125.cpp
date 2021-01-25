//
// Created by akio on 2021/1/25.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(3 * m, vector<int>(3 * n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    dp[3 * i][3 * j] = 1;
                    dp[3 * i + 1][3 * j + 1] = 1;
                    dp[3 * i + 2][3 * j + 2] = 1;
                } else if (grid[i][j] == '/') {
                    dp[3 * i][3 * j + 2] = 1;
                    dp[3 * i + 1][3 * j + 1] = 1;
                    dp[3 * i + 2][3 * j] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                if (dp[i][j] == 0) {
                    ++res;
                    dfs(dp, i, j);
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>> &dp, int x, int y) {
        int m = dp.size(), n = dp[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || dp[x][y] != 0) return;
        dp[x][y] = 2;
        dfs(dp, x + 1, y);
        dfs(dp, x - 1, y);
        dfs(dp, x, y + 1);
        dfs(dp, x, y - 1);
    }
};