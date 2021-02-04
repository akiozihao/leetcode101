//
// Created by akio on 2021/1/31.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dp[0][i]) {
                for (int j = i + 1; j < n - 1; ++j) {
                    if(dp[i+1][j] && dp[j+1][n-1]) return true;
                }
            }
        }
        return false;
    }
};