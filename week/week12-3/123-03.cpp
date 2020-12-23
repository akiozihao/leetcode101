//
// Created by akio on 2020/12/20.
//
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int sz = nums.size();
        multiset<int> mst;
        vector<int> dp(sz,INT_MIN);
        dp[0] = nums[0];
        for(int i=1;i<sz;++i){
            dp[i] = max(dp[i],*mst.begin() + nums[i]);
            if(i>k){
                mst.erase(mst.find(dp[i-k-1]));
            }
        }
        // for(int i :dp){
        //     cout << i << ' ';
        // }
        // cout  << endl;
        return dp.back();
    }
};