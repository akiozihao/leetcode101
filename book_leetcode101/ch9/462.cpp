//
// Created by akio on 2021/1/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0, i = 0, j = (int) nums.size() - 1;
        while (i < j) {
            res += nums[j--] - nums[i++];
        }
        return res;
    }
};