//
// Created by akio on 2020/10/30.
//
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j * j < i; ++j) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp.back();
    }
};