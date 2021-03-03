//
// Created by akio on 2021/2/16.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.empty())return {};
        int n = nums.size(), l = 0, r = 0;
        vector<string> res;
        while (r < n) {
            while (l==r || (r < n && nums[r] == nums[r - 1] + 1)) ++r;
            if (l != r - 1) res.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
            else res.push_back(to_string(nums[l]));
            l = r;
        }
        return res;
    }
};