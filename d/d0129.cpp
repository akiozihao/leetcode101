//
// Created by akio on 2021/1/29.
//
#include <vector>
#include <tuple>
#include <numeric>

using namespace std;

class UF {
private:
    vector<int> parent;
    vector<int> size;
    int setCount;
    int n;
public:
    UF(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        return findset(x) == findset(y);
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2) {
            auto &&[x1, y1, v1] = e1;
            auto &&[x2, y2, v2] = e2;
            return v1 < v2;
        });

        UF uf(m * n);
        int res = 0;
        for (const auto[x, y, v]:edges) {
            uf.unite(x, y);
            if (uf.connected(0, m * n - 1)) {
                res = v;
                break;
            }
        }
        return res;
    }
};