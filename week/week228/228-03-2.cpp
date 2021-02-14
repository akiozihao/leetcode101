//
// Created by akio on 2021/2/14.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end()), mid, n = nums.size(), i, m;
        while (l < r) {
            mid = l + (r - l) / 2;
            for (i = 0, m = 0; i < n && m <= maxOperations; ++i) {
                m += (nums[i] - 1) / mid;
            }
            if(m<=maxOperations) r = mid;
            else l = mid+ 1;
        }
        return r;
    }
};