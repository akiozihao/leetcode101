//
// Created by akio on 2020/10/28.
//
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        vector<int> res;
        vector<unordered_set<int>> adj(n);
        queue<int> q;
        for (auto edge:edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) q.push(i);
        }
        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; ++i) {
                int t = q.front();
                q.pop();
                for (auto a:adj[t]) {
                    adj[a].erase(t);
                    if (adj[a].size() == 1) q.push(a);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};