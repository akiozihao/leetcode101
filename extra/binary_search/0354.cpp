//
// Created by akio on 2020/12/29.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        if (envelopes.empty() || envelopes[0].empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int maxEnvelopes2(vector<vector<int>> &envelopes) {
        // 我理解的是dp[i]维护的是长度为i+1的递增子序列可以取到的最小结尾值
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for(int i=0;i<envelopes.size();++i){
            int left = 0,right = dp.size(),t = envelopes[i][1];
            while(left < right){
                int mid = left + (right - left) / 2;
                if(dp[mid] < t) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(t);
            else dp[right] = t;
        }
        return dp.size();
    }
};