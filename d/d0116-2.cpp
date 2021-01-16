//
// Created by akio on 2021/1/16.
//
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> f, sz;
public:
    UnionFind(int n) : f(n), sz(n) {
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (f[x] == x) return x;
        int nf = find(f[x]);
        f[x] = nf;
        return nf;
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        f[fx] = fy;
        sz[fy] += sz[fx];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n + 1);
        vector<vector<int>> status = grid;
        for (int i = 0; i < hits.size(); ++i) {
            status[hits[i][0]][hits[i][1]] = 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (status[i][j] == 1) {
                    if (i == 0) {
                        uf.merge(m * n, i * n + j);
                    }
                    if (i > 0 && status[i - 1][j] == 1) {
                        uf.merge(i * n + j, (i - 1) * n + j);
                    }
                    if (j > 0 && status[i][j - 1] == 1) {
                        uf.merge(i * n + j, i * n + j - 1);
                    }
                }
            }
        }
        const vector<pair<int, int>> dirs{{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}};
        vector<int> res(hits.size(), 0);
        for (int i = hits.size() - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0) continue;
            int prev = uf.size(m * n);
            if (x == 0) uf.merge(y, m * n);
            for (const auto[dx, dy]:dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (status[nx][ny] == 1) {
                        uf.merge(x * n + y, nx * n + ny);
                    }
                }
            }
            int sz = uf.size(m * n);
            res[i] = max(0, sz - prev - 1);
            status[x][y] = 1;
        }
        return res;
    }
};