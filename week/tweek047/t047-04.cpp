#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges,
                           vector<int>& queries) {
        int q = queries.size();
        vector<int> deg(n + 1);
        unordered_map<int, int> cnt;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (u > v) {
                swap(u, v);
            }
            cnt[u * (n + 1) + v]++;
            deg[u]++;
            deg[v]++;
        }
        vector<int> s(deg);
        sort(s.begin(), s.end());
        vector<int> res(q);
        for (int i = 0; i < q; ++i) {
            int target = queries[i];
            int r = n;
            for (int l = 1; l < n; ++l) {
                r = max(r, l + 1);
                
            }
        }
    }
};