//
// Created by akio on 2020/10/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r; ++i) {
            if (nums[i] == 0)
                swap(nums[l++], nums[i]);
            else if (nums[i] == 2)
                swap(nums[r--], nums[i--]);
        }
    }
};