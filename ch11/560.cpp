//
// Created by akio on 2021/1/14.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        ++m[sum];
        for (int &num:nums) {
            sum += num;
            res += m[sum - k];
            ++m[sum];
        }
        return res;
    }
};