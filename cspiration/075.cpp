//
// Created by akio on 2021/2/16.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[p2--]);
            }
        }
    }
};