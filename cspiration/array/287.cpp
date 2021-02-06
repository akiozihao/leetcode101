//
// Created by akio on 2021/2/5.
//
#include<bits//stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < n; ++j) {
                if (bit & j) ++cnt1;
                if (bit & nums[j]) ++cnt2;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    }
};