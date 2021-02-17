//
// Created by akio on 2021/2/17.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        vector<int> res{-1, -1};
        auto p1 = lower_bound(nums.begin(), nums.end(), target);
        if (p1 == nums.end() || *p1 != target) {
            res[0] = -1;
        } else res[0] = p1 - nums.begin();
        auto p2 = upper_bound(nums.begin(), nums.end(), target);
        if (p2 == nums.begin() || *--p2 != target) {
            res[1] = -1;
        } else res[1] = p2 - nums.begin();
        return res;
    }
};