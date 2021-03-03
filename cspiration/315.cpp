//
// Created by akio on 2021/2/17.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> v, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; ++i) {
            auto ptr = lower_bound(v.begin(), v.end(), nums[i]);
            res[i] = ptr - v.begin();
            v.insert(ptr, nums[i]);
        }
        return res;
    }
};