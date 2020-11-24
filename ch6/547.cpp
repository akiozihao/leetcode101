//
// Created by akio on 2020/10/19.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    ++res;
                    queue<pair<int, int>> q{{{i, j}}};
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int X = p.first, Y = p.second;
                        for (int x = 0; x < m; ++x) {
                            if (M[x][Y] == 1) q.push({x, Y});
                            M[x][Y] = 0;
                        }
                        for (int y = 0; y < n; ++y) {
                            if (M[X][y] == 1) q.push({X, y});
                            M[X][y] = 0;
                        }
                    }

                }
            }
        }
        return res;
    }
};