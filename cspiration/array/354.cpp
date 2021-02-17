//
// Created by akio on 2021/2/17.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &e) {
        if (e.empty()) return 0;
        int n = e.size();
        vector<int> dp(n, 1);
        sort(e.begin(), e.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (e[i][0] > e[j][0] && e[i][1] > e[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int maxEnvelopes2(vector<vector<int>> &e) {
        vector<int> dp;
        sort(e.begin(), e.end(), [](const vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < e.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), e[i][1]);
            if (it == dp.end()) dp.push_back(e[i][1]);
            else *it = e[i][1];
        }
        return dp.size();
    }

};