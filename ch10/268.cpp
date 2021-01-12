//
// Created by akio on 2021/1/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0, n = nums.size();
        for (int &i:nums) {
            sum += i;
        }
        return n * (n + 1) / 2 - sum;
    }

    int missingNumber2(vector<int> &nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};