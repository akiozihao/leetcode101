//
// Created by akio on 2021/1/19.
//
#include <vector>
#include <map>

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

    bool connected(vector<int> &f, int x, int y) {
        return find(f, x) == find(f, y);
    }

    int minCostConnectPoints(vector<vector<int>> &points) {
        if (points.empty() || points[0].empty()) return 0;
        int n = points.size(), res = 0;
        map<int, vector<pair<int, int>>> m;
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                m[dist].push_back({i, j});
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            vector<pair<int, int>> &v = it->second;
            for (auto &p:v) {
                if (connected(f, p.first, p.second)) continue;
                merge(f,p.first,p.second);
                res += it->first;
            }
        }
        return res;
    }
};