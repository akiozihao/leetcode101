//
// Created by akio on 2021/1/15.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> f;

    int getf(vector<int> &f, int x) {
        if (f[x] == x) return x;
        int nf = getf(f, f[x]);
        f[x] = nf;
        return nf;
    }

    void add(vector<int> &f, int x, int y) {
        int fx = getf(f, x);
        int fy = getf(f, y);
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
                add(f, i, row[x]);
            }
            if (col.count(y)) {
                add(f, i, col[y]);
            }
            row[x] = i;
            col[y] = i;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == getf(f, i)) ++cnt;
        }
        return n - cnt;
    }
};