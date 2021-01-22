//
// Created by akio on 2021/1/22.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> f;

    int find(vector<int> &f, int x) {
        if (f[x] == x) return x;
        int nf = find(f, f[x]);
        f[x] = nf;
        return nf;
    }

    void merge(vector<int> &f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
    }

    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        unordered_map<int, int> row, col;
        for (int i = 0; i < n; ++i) {
            int x = stones[i][0], y = stones[i][1];
            if (row.count(x)) {
                merge(f, i, row[x]);
            }
            if (col.count(y)) {
                merge(f, i, col[y]);
            }
            row[x] = i;
            col[y] = i;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == find(f, i)) ++cnt;
        }
        return n - cnt;
    }
};