//
// Created by akio on 2021/2/15.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i < pre.size(); ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int res = n + 1;
        for (int i = 0; i < pre.size(); ++i) {
            if (pre[i] < target) continue;
            int l = upper_bound(pre.begin(),pre.begin()+i,pre[i]-target) - pre.begin() - 1;
            res = min(res,i-l);
        }
        return res == n + 1 ? 0:res;
    }
};