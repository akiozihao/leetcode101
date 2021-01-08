//
// Created by akio on 2021/1/8.
//
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.empty()) return;
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }

private:
    void reverse(vector<int> &nums, int l, int r) {
        while (l < r) {
            swap(nums[l++], nums[r--]);
        }
    }
};