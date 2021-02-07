//
// Created by akio on 2021/2/5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums) {
        if (nums.empty()) return true;
        int n = nums.size(), cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++cnt;
                if (cnt > 1) return false;
                if(nums[0] < nums.back()) return false;
            }
        }
        return true;
    }
};