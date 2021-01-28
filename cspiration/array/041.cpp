//
// Created by akio on 2021/1/26.
//
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty()) return 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 1 || nums[i] > n || nums[i] == i + 1) continue;
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};