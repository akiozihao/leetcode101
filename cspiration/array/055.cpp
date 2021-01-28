//
// Created by akio on 2021/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.empty()) return true;
        int n = nums.size(), mx = 0;
        for (int i = 0; i < n; ++i) {
            if (mx >= n - 1) return true;
            if (mx < i) return false;
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};