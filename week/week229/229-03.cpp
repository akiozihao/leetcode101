//
// Created by akio on 2021/2/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        vector<vector<long long>> dp(1e3 + 5, vector<long long>(1e3 + 5));
        long long m = multipliers.size(), res = INT_MIN, n = nums.size();
        for (int k = 1; k <= m; ++k) {
            for (int i = 0; i <= k; ++i) {
                if (i == 0) dp[i][k - i] = dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1];
                else if (i == k) dp[i][k - i] = dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1];
                else
                    dp[i][k - i] = max(dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1],
                                       dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1]);
                if (k == m) res = max(res, dp[i][k - i]);
            }
        }
        return res;
    }
};