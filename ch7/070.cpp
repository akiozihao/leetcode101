//
// Created by akio on 2020/10/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + 1;
        }
        return dp.back();
    }

    int climbStairs2(int n) {
        if (n <= 2) return n;
        int pre2 = 1, pre = 2, cur;
        for (int i = 3; i <= n; ++i) {
            cur = pre + pre2;
            pre2 = pre;
            pre = cur;
        }
        return cur;
    }
};