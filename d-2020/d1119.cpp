//
// Created by akio on 2020/11/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ++cnt;
            else
                swap(nums[i], nums[i - cnt]);
        }
    }
};