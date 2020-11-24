//
// Created by akio on 2020/11/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size() + 1, 0);
        int res = nums[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(nums[i - 1], nums[i - 1] + dp[i - 1]);
            res = max(res, dp[i]);
        }
        return res;
    }

    int maxSubArray2(vector<int> &nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int) nums.size() - 1);
    }

private:
    int helper(const vector<int> &nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(max(lmax, rmax), mmax);
    }

};