//
// Created by akio on 2021/2/5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAbsDifference(vector<int> &nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        int ls = half, rs = n - half;
        vector<int> lsum(1 << ls, 0);
        for (int i = 1; i < (1 << ls); ++i) {
            for (int j = 0; j < ls; ++j) {
                if ((i & (1 << j)) == 0) continue;
                lsum[i] = lsum[i - (1 << j)] + nums[j];
                break;
            }
        }
        vector<int> rsum(1 << rs, 0);
        for (int i = 1; i < (1 << rs); ++i) {
            for (int j = 0; j < rs; ++j) {
                if ((i & (1 << j)) == 0) continue;
                rsum[i] = rsum[i - (1 << j)] + nums[ls + j];
                break;
            }
        }
        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        int res = INT_MAX;
        for (int x:lsum) {
            res = min(res, abs(goal - x));
        }
        for (int x:rsum) {
            res = min(res, abs(goal - x));
        }
        int i = 0, j = rsum.size() - 1;
        while (i < lsum.size() && j >= 0) {
            int s = lsum[i] + rsum[j];
            res = min(res, abs(goal - s));
            if (s > goal) {
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};