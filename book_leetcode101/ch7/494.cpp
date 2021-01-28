//
// Created by akio on 2020/11/10.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        vector<unordered_map<int, int>> memo(nums.size());
        return helper(nums, S, 0, memo);
    }

private:
    int helper(vector<int> &nums, long S, int start, vector<unordered_map<int, int>> &memo) {
        if (start == nums.size()) return S == 0;
        if (memo[start].count(S)) return memo[start][S];
        int cnt1 = helper(nums, S - nums[start], start + 1, memo);
        int cnt2 = helper(nums, S + nums[start], start + 1, memo);
        return memo[start][S] = cnt1 + cnt2;
    }
};