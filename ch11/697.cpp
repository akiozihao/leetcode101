//
// Created by akio on 2021/1/14.
//
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        vector<int> left(50000, -1);
        vector<int> right(50000, -1);
        unordered_map<int, int> cnt;
        int degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left[nums[i]] == -1) {
                left[nums[i]] = i;
            }
            right[nums[i]] = i;
            ++cnt[nums[i]];
            degree = max(degree, cnt[nums[i]]);
        }
        int res = INT_MAX;
        for (auto &it : cnt) {
            if (it.second == degree) {
                res = min(res, right[it.first] - left[it.first] + 1);
            }
        }
        return res;
    }
};