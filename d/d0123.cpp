//
// Created by akio on 2021/1/23.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> f;
    int cnt;

    int find(vector<int> &f, int x) {
        if (f[x] == x) return x;
        int nf = find(f, f[x]);
        f[x] = nf;
        return nf;
    }

    void merge(vector<int> &f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
        --cnt;
    }

    bool connected(vector<int> &f, int x, int y) {
        return find(f, x) == find(f, y);
    }

    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) return -1;
        cnt = n;
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        int remain = 0;
        for (auto &c:connections) {
            if (!connected(f, c[0], c[1])) {
                merge(f, c[0], c[1]);
            } else {
                ++remain;
            }
        }
        return remain >= cnt - 1 ? cnt - 1 : -1;
    }
};