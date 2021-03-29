#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(15, vector<int>(70, 0));
        for (int i = 1; i <= 6; ++i) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= 6 * i; ++j) {
                for (int cur = 1; cur <= 6; ++cur) {
                    if (j - cur <= 0) break;
                    dp[i][j] += dp[i - 1][j - cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> res;
        for (int i = n; i <= 6 * n; ++i) {
            res.push_back(dp[n][i] * 1. / all);
        }
        return res;
    }
};