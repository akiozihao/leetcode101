//
// Created by akio on 2021/1/21.
//
#include <vector>
#include <unordered_set>

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

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        if (edges.empty()) return {};
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        int value = 0;
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        for (auto &e:edges) {
            if (!connected(f, e[0], e[1])) {
                merge(f, e[0], e[1]);
                value += e[2];
            }
        }
        vector<vector<int>> res;
        // 关键边
        unordered_set<int> k;
        for (int idx = 0; idx < m; ++idx) {
            for (int i = 0; i < n; ++i) {
                f[i] = i;
            }
            int v1 = 0;
            for (int i = 0; i < m; ++i) {
                if (i == idx) continue;
                if (!connected(f, edges[i][0], edges[i][1])) {
                    merge(f, edges[i][0], edges[i][1]);
                    v1 += edges[i][2];
                }
            }
            if (v1 != value) k.insert(edges[idx].back());
        }
        res.emplace_back(vector<int>{k.begin(), k.end()});
        // 非关键边
        unordered_set<int> nk;
        for (int idx = 0; idx < edges.size(); ++idx) {
            if (k.count(edges[idx].back())) continue;
            int v2 = 0;
            for (int i = 0; i < n; ++i) {
                f[i] = i;
            }
            merge(f, edges[idx][0], edges[idx][1]);
            v2 += edges[idx][2];
            for (int i = 0; i < m; ++i) {
                if(i==idx) continue;
                if (!connected(f, edges[i][0], edges[i][1])) {
                    merge(f, edges[i][0], edges[i][1]);
                    v2 += edges[i][2];
                }
            }
            if (v2 == value) nk.insert(edges[idx].back());
        }
        res.emplace_back(vector<int>{nk.begin(), nk.end()});
        return res;
    }
};