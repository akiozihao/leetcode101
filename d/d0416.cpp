#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                for (int j = 0; j <= n - len; ++j) {
                    if (len == 1) {
                        dp[i][j][len] = (s1[i] == s2[j]);
                    } else {
                        for (int k = 1; k < len; ++k) {
                            if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                                (dp[i][j + len - k][k] &&
                                 dp[i + k][j][len - k]))
                                dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};