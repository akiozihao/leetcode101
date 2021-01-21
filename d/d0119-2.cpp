//
// Created by akio on 2021/1/19.
//
#include <vector>
#include <map>

using namespace std;

class Edge {
public:
    Edge(int x, int y, int len) : x(x), y(y), len(len) {}

    int x;
    int y;
    int len;


};

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
        vector<Edge> ve;
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                ve.emplace_back(i, j, dist);
            }
        }
        sort(ve.begin(), ve.end(), [](Edge &a, Edge &b) {
            return a.len < b.len;
        });
        for (auto e:ve) {
            int x = e.x, y = e.y, len = e.len;
            if (connected(f, x, y)) continue;
            merge(f, x, y);
            res += len;
        }
        return res;
    }
};