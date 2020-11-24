//
// Created by akio on 2020/10/31.
//
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> st;
        for (const string &w:wordDict)
            st.insert(s);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (st.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};