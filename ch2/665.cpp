//
// Created by akio on 2020/10/12.
//
#include <vector>

using namespace std;

bool checkPossibility(vector<int> &nums) {
    if (nums.empty() || nums.size() < 2) return true;
    int sz = nums.size(), count = 0;
    for (int i = 0; i < sz - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            if (i == 0 || nums[i - 1] <= nums[i + 1]) {
                nums[i] = nums[i + 1];
            } else if (nums[i - 1] > nums[i + 1]) {
                nums[i + 1] = nums[i];
            }
            ++count;
            if (count > 1) return false;
        }
    }
    return true;
}