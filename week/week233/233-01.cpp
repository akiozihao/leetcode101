#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cur = nums[0], res = 0, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                cur += nums[i];
            } else {
                res = max(res, cur);
                cur = nums[i];
            }
        }
        res = max(res, cur);
        return res;
    }
};