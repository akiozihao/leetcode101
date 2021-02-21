//
// Created by akio on 2021/2/20.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> m;
        vector<int> left(5e5, -1);
        vector<int> right(5e5, -1);
        int n = nums.size(), res = n, degree = 0;
        for (int i = 0; i < n; ++i) {
            if (left[nums[i]] == -1) left[nums[i]] = i;
            right[nums[i]] = i;
            ++m[nums[i]];
            degree = max(degree, m[nums[i]]);
        }
        for (auto &it:m) {
            if (it.second == degree) res = min(res, right[it.first] - left[it.first] + 1);
        }
        return res;
    }
};