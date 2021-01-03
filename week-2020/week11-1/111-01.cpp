//
// Created by akio on 2020/11/8.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int res = 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getMaximumGenerated(2) << endl;
}