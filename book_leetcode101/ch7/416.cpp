//
// Created by akio on 2020/10/31.
//
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2, sz = nums.size();
        vector<vector<bool>> dp(sz + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= sz; ++i)
            dp[i][0] = true;
        for (int i = 1; i <= sz; ++i) {
            for (int j = nums[i - 1]; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[sz][target];
    }
};