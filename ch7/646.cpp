//
// Created by akio on 2020/11/10.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};