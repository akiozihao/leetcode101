//
// Created by akio on 2020/10/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }

    int rob2(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];
        int pre2 = nums[0], pre = max(nums[0], nums[1]), res=pre;
        for (int i = 2; i < nums.size(); ++i) {
            res = max(pre, pre2 + nums[i]);
            pre2 = pre;
            pre = res;
        }
        return res;
    }
};