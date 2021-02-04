//
// Created by akio on 2021/1/29.
//
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>

using namespace std;

class UF {
private:
    vector<int> parents;
    vector<int> sz;
    int setCount;
    int n;
public:
    UF(int _n) : n(_n), parents(_n), sz(_n, 1), setCount(_n) {
        iota(parents.begin(), parents.end(), 0);
    }

    int findset(int x) {
        if (parents[x] == x) return x;
        int nf = findset(parents[x]);
        parents[x] = nf;
        return nf;
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        parents[y] = x;
        sz[x] += sz[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        return findset(x) == findset(y);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = i * n + j;
                if (i > 0) {
                    v.emplace_back(idx - n, idx, max(grid[i - 1][j], grid[i][j]));
                }
                if (j > 0) {
                    v.emplace_back(idx - 1, idx, max(grid[i][j - 1], grid[i][j]));
                }
            }
        }
        sort(v.begin(), v.end(), [](const auto &t1, const auto &t2) {
            auto &&[x1, y1, h1] = t1;
            auto &&[x2, y2, h2] = t2;
            return h1 < h2;
        });
        int res = 0;
        UF uf(m * n);
        for (const auto[x, y, h]:v) {
            if (uf.connected(0, m * n - 1)) return res;
            uf.unite(x, y);
            res = h;
        }
        return -1;
    }
};