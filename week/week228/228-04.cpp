//
// Created by akio on 2021/2/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>> &edges) {
        vector<vector<bool>> d(n, vector<bool>(n));
        vector<int> degree(n);
        for (auto &e:edges) {
            d[e[0] - 1][e[1] - 1] = d[e[1] - 1][e[0] - 1] = true;
            degree[e[0] - 1]++;
            degree[e[1] - 1]++;
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!d[i][j]) continue;
                for (int k = j + 1; k < n; ++k) {
                    if (d[i][k] && d[j][k]) {
                        res = min(res, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }

    int minTrioDegree2(int n, vector<vector<int>> &edges) {
        vector<unordered_set<int>> d(n);
        for (auto &e:edges) {
            int u = e[0] - 1, v = e[1] - 1;
            d[u].insert(v);
            d[v].insert(u);
        }
        vector<vector<int>> adj(n);
        for (auto &e:edges) {
            int u = e[0] - 1, v = e[1] - 1;
            if (d[u].size() < d[v].size() || (d[u].size() == d[v].size() && u < v)) {
                adj[u].emplace_back(v);
            } else {
                adj[v].emplace_back(u);
            }
        }

        int res = INT_MAX;
        for (int u = 0; u < n; ++u) {
            for (int v:adj[u]) {
                for (int w:adj[v]) {
                    if (d[u].count(w)) {
                        res = min(res, (int) (d[u].size() + d[v].size() + d[w].size() - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }

};