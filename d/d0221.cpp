//
// Created by akio on 2021/2/21.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        map<int, int> m;
        int res = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            m[nums[j]]++;
            while (m.rbegin()->first - m.begin()->first > limit) {
                --m[nums[i]];
                if (m[nums[i]] == 0) m.erase(nums[i]);
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};