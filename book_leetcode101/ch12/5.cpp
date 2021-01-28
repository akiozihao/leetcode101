//
// Created by akio on 2021/1/21.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return 0;
        pair<int, int> p;
        int n = s.size(), mx = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > mx) {
                    mx = j - i + 1;
                    p.first = i;
                    p.second = j;
                }
            }
        }
        return {s.begin() + p.first, s.begin() + p.second + 1};
    }
};