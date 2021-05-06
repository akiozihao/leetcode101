#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }

   private:
    int rob(const vector<int>& nums) {
        int n = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int t = second;
            second = max(first + nums[i], second);
            first = t;
        }
        return second;
    }
};