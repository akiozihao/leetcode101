//
// Created by akio on 2021/2/7.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &e, int k) {
        sort(e.begin(), e.end());
        int n = e.size();
        vector<int> next(n);
        for (int i = 0; i < n; ++i) {
            next[i] = lower_bound(e.begin(), e.end(), vector<int>{e[i][1] + 1, 0, 0}) - e.begin();
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1,0));
        for (int i = 1; i <= k; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(e[j][2] + dp[i - 1][next[j]], dp[i][j + 1]);
            }
        }
        return dp[k][0];
    }
};