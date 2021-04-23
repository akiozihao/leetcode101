#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        int maxSize = 1, maxVal = dp[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > maxSize){
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        vector<int> res;
        if(maxSize==1) {
            res.push_back(nums[0]);
            return res;
        }

        for(int i=n-1;i>=0 && maxVal >0;--i){
            if(dp[i]==maxSize && maxVal % nums[i]==0){
                res.push_back(nums[i]);
                maxVal = nums[i];
                maxSize--;
            }
        }
        return res;
    }
};