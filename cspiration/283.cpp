//
// Created by akio on 2021/2/16.
//
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ++cnt;
            else nums[i - cnt] = nums[i];
        }
        for (int i = nums.size() - cnt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }

    void moveZeroes2(vector<int> &nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }

};