//
// Created by akio on 2021/2/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int res = 0;
        long long miss = 1;
        int sz = nums.size(), i = 0;
        while (miss <= n) {
            if (i < sz && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss <<= 1;
                ++res;
            }
        }
        return res;
    }
};